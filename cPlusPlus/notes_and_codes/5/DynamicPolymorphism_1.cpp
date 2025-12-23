#include <iostream>
#include <string>
using namespace std;

/*
Program : Dynamic Polymorphism using Virtual Functions. Demonstrate Dynamic Polymorphism in C++ using
virtual functions and base class pointers

Key Concepts :
1. Inheritance
2. Base class pointer
3. Virtual functions
4. Runtime method binding

Dynamic Polymorphism means the function call is decided at runtime, based on the actual object type, not the pointer type.
In Simple Words:
- One base class pointer
- points to different derived objects
- Calls the correct function depending on the object
- Why Dynamic : because the decision of which function to call happens while the program is running, not while compiling.

What are Virtual Functions? A virtual function is a member function of a base class that is declared using
the keyword virtual and is meant to be overridden in derived classes.

Notes:
• A virtual function is a member function of a base class that is expected to be overridden in derived classes.
• Virtual functions enable runtime (dynamic) polymorphism.
• Without the keyword 'virtual' in the function:
  - Function call is resolved at compile time
  - C++ decides which function to call at COMPILE TIME using the POINTER TYPE — NOT the object type.
  - static binding (or early binding).

• With the keyword 'virtual':
  - You are telling the compiler "Do NOT decide this at compile time. Wait until runtime and check the actual object"
  - Function call is resolved at runtime
  - Function call depends on OBJECT TYPE
  - IMP: it is not necessary to overide the virtual functiion in the derived class.
    If a derived class does NOT override a virtual function, then the base class version of that function is called.
    (we will see this in the next code)

VERY IMP : CORE RULE
In runtime polymorphism, the overridden method must have the same function name and the same parameter list (signature)
as the base class virtual function.
*/

class Base
{
public:
    // Virtual function
    // This tells C++ to decide which show() to call at runtime
    virtual void show()
    {
        cout << "Base Class Show" << endl;
    }

    // If 'virtual' is removed here,
    // dynamic polymorphism will NOT work
};

class Derived : public Base
{
public:
    // Overriding the base class virtual function
    void show()
    {
        cout << "Derived Class Show" << endl;
    }
};

int main()
{
    Base *ptr; // Base class pointer (This is also called a Generic Pointer)
    Base b;    // Base Class Object
    Derived d; // Derived class object

    // Because show() is virtual, C++ decides at runtime which function to call , using the generic pointer
    ptr = &b;
    ptr->show(); // Output: Bse class

    ptr = &d;    // Base pointer pointing to Derived object
    ptr->show(); // Output: Derived class

    return 0;
}
