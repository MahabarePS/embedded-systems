/*
In this Code we will look at :
- Raw Pointers vs Smart Pointers (Unique and shared)
- Raw Pointer vs unique_ptr vs shared_ptr

IMPORTANT THEORY:
1. RAW POINTER:
   - Memory allocated using new
   - Programmer must manually call delete
   - If delete is forgotten → MEMORY LEAK
   - Destructor may never be called
   - Raw pointers allow copy and move, but do not know what ownership means. This is exactly why they are dangerous.
     Hence Smart pointers were introduced

2. unique_ptr:
   - Smart pointer with SINGLE ownership
   - Cannot be copied
   - Can be moved (move semantics - ownership transfer , original ptr is set to nullptr)
   - Automatically deletes memory when it goes out of scope
   - Follows RAII
   - Use when Only one part of the program should own the object
     e.g. File handler , database connection etc.

3. shared_ptr:
   - Smart pointer with MULTIPLE ownership
   - Uses REFERENCE COUNTING
   - Can be copied (reference count increases)
   - Can be moved (ownership transferred)
   - Memory is deleted only when reference count becomes 0
   - Also follows RAII
   - Use when Multiple parts of the program must own the same object, and Object must stay alive until everyone is done using it
     e.g. Shared configuration object , all modules use same configurations
        moduleA(config);
        moduleB(config);
        moduleC(config);

KEY DIFFERENCE:
unique_ptr  - one owner
shared_ptr  - many owners allowed
Always Prefer unique_ptr over shared_ptr, unless absolutely necessary

MEMORY RULE:
Raw pointer - delete manually
unique_ptr  - automatic delete
shared_ptr  - automatic delete when count = 0

*/

#include <iostream>
#include <memory> // for smart pointers
#include <string>
using namespace std;

// Demo class has DATA so we can SEE copy vs move behaviour clearly

class Demo
{
public:
    string data;

    Demo(string d) : data(d)
    {
        cout << "Constructor: data = " << data << endl;
    }

    ~Demo()
    {
        cout << "Destructor: data = " << data << endl;
    }

    void show() const
    {
        if (data.empty())
            cout << "data is EMPTY\n";
        else
            cout << "data = " << data << endl;
    }
};

int main()
{
    // --- RAW POINTER DEMO ----
    cout << "\n----- RAW POINTER -----\n";

    // p is a pointer to a Demo object , stores address of Demo object
    // why -> with smart pointers? Because smart pointers overload the arrow operator to access the managed object.

    Demo *p = new Demo("RAW");
    cout << "Using raw pointer...\n";
    p->show();

    Demo *p2 = p; // COPY , p and p2 now store the same address, No ownership tracking
    p2->show();
    // if you want to move p to p2 -, u must remember to set p to nullptr , will not happen automatically

    // FORGOTTEN ON PURPOSE
    // Result: Destructor NOT called ; Memory leak
    // delete p;

    // --- UNIQUE POINTER DEMO (COPY not allowed, MOVE allowed) ---
    // This is in a scope block , so we see the destructor called at the end of the block
    {

        cout << "\n----- UNIQUE POINTER -----\n";

        // up1 is an OBJECT of type unique_ptr<Demo> that owns a Demo object.
        //'Owns' means:
        //  - Holds the address of a Demo object
        //  - Is responsible for deleting that object
        //  - Ensures no other unique_ptr owns it
        //  - manages the objects lifetime

        // this creates a Demo object and returns a unique_ptr<Demo> that owns it
        // make_unique<T>() creates a T object and returns a unique_ptr<T> that owns it.

        unique_ptr<Demo> up1 = make_unique<Demo>("UNIQUE");
        cout << "up1 owns:\n";
        up1->show();

        // COPY NOT ALLOWED:
        // unique_ptr<Demo> up2 = up1;   // ERROR

        cout << "\nMoving ownership...\n";
        unique_ptr<Demo> up2 = move(up1); // MOVE

        if (!up1)
            cout << "up1 is now nullptr\n";

        cout << "up2 now owns:\n";
        up2->show();
    }
    // Destructor called here for UNIQUE

    // --- SHARED POINTER DEMO (COPY vs MOVE + reference count) ----
    {

        cout << "\n----- SHARED POINTER -----\n";
        // sp1 is an OBJECT of type shared_ptr<Demo> that shares ownership of a Demo object.
        // 'shares ownership' means
        //   - sp1 holds the address of the Demo object
        //   - It increments/decrements a reference count
        //   - The Demo object is deleted only when the count becomes 0

        // this creates a Demo object and returns a shared_ptr<Demo> that shares ownership of the object
        // make_shared<T>() creates a T object and returns a shared_ptr<T> that shares ownership of the object

        shared_ptr<Demo> sp1 = make_shared<Demo>("SHARED");

        cout << "sp1 owns:\n";
        sp1->show();

        // Reference count tells how many shared_ptrs currently own the same object.
        // sp1.use_count() or sp2.use_count() - returns current refrence count
        cout << "Reference count: " << sp1.use_count() << endl;

        // COPY shared_ptr
        cout << "\nCopying shared_ptr...\n";
        shared_ptr<Demo> sp2 = sp1;

        cout << "Reference count after copy: " << sp1.use_count() << endl;
        cout << "sp2 sees:\n";
        sp2->show();

        // MOVE shared_ptr
        cout << "\nMoving shared_ptr...\n";
        shared_ptr<Demo> sp3 = move(sp1);

        if (!sp1)
            cout << "sp1 is now nullptr after move\n";

        cout << "Reference count after move: " << sp3.use_count() << endl;
        cout << "sp3 owns:\n";
        sp3->show();

        cout << "sp2 still sees :\n";
        sp2->show();
    }
    // When sp2 and sp3 go out of scope:
    //   - Reference count becomes 0
    //   - Destructor is called

    cout << "\nProgram ending safely.\n";
    return 0;
}