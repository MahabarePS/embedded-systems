// Access Modifiers
/*
Access Modifier     Accessible within class     Accessible in derived class     Accessible outside the class
private	            YES                         NO                              NO    
protected	        YES                         YES                             NO
public	            YES                         YES                             YES

*/

#include <iostream>
using namespace std;

class Example {
private:
    int privateVar;

protected:
    int protectedVar;

public:
    int publicVar;

    // Constructor
    Example() {
        privateVar = 1;
        protectedVar = 2;
        publicVar = 3;
    }

    // Public method to access private member
    void showData() {
        cout << "privateVar = " << privateVar << endl;
        cout << "protectedVar = " << protectedVar << endl;
        cout << "publicVar = " << publicVar << endl;
    }
};

class Derived : public Example {
public:
    void accessProtected() {
        // privateVar is NOT accessible here
        // cout << privateVar; // Compiler Errpr

        cout << "Accessing protectedVar from Derived class: " << protectedVar << endl;
        cout << "Accessing publicVar from Derived class: " << publicVar << endl;
    }
};

int main() {
    Example obj;
    obj.showData();                 // Allowed : Can access all via public method

    // obj.privateVar = 10;         // Error : private
    // obj.protectedVar = 20;       // Error: protected
    obj.publicVar = 30;             // Allowed : Can directly access public

    Derived d;
    d.accessProtected();            // Allowed : Can access protected & public from derived class

    return 0;
}
