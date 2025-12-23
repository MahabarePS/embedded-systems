// Inheritence : Base Class Access Specifiers
// Inheritance is a mechanism where one class (child/derived class) can inherit the properties and behaviors
// (members and functions) of another class (parent/base class).

/*
The access specifier used during inheritance (public, protected, or private)
affects how inherited members from the base class are treated in the derived class.

IMP : In all cases of Inheritence (Public , Private or Protected ) , the Base Classes Private Elements
remain Private to the base and are not Accessible / Inherited by members of the Derived Class.

1. PUBLIC INHERITENCE :
 - public members of the base are inherited and become public members of the derived class
 - protected members of the base are inherited and become protected members of the derived class.

2. PRIVATE INHERITENCE :
- public and protected members of the base class are inherited and  become Private members of the derived class

3. PROTECTED INHERITENCE :
- public and protected members of the base class are inherited and  become Protected members of the derived class
*/

#include <iostream>
using namespace std;

/*
// Public Inheritence
class Base
{
    public:
        int a;
    protected:
        int b;
    private:
        int c;
};

class Derived:public Base
{
    void doSomething()
    {
        a = 10;  //Allowed
        b = 20;  //Allowed
        c = 30;  //Not Allowed, Compiler Error
    }
};

int main()
{
    Derived obj;
    obj.a = 10;  //Allowed ; it is public
    obj.b = 20;  //Not Allowed, Compiler Error ; protected
    obj.c = 30;  //Not Allowed, Compiler Error ;
    return 0;
} */

/*
// Private Inheritence
class Base
{
    public:
      int a;
    protected:
      int b;
    private:
      int c;
};

class Derived: Base   //Not mentioning private is OK because for classes it  defaults to private
{
    void doSomething()
    {
        a = 10;  //Allowed
        b = 20;  //Allowed
        c = 30;  //Not Allowed, Compiler Error
    }
};

class Derived2:public Derived
{
    void doSomethingMore()
    {
        a = 10;  //Not Allowed, Compiler Error, a is private member of Derived now
        b = 20;  //Not Allowed, Compiler Error, b is private member of Derived now
        c = 30;  //Not Allowed, Compiler Error
    }
};

int main()
{
    Derived obj;
    Base b;
    b.a = 4;
    obj.a = 10;  //Not Allowed, Compiler Error
    obj.b = 20;  //Not Allowed, Compiler Error
    obj.c = 30;  //Not Allowed, Compiler Error
    return 0;
} */

/*
// Protected Inheritence
class Base
{
public:
    int a;
protected:
    int b;
private:
    int c;
};

class Derived : protected Base
{
    void doSomething()
    {
        a = 10; // Allowed
        b = 20; // Allowed
        c = 30; // Not Allowed, Compiler Error
    }
};

class Derived2 : public Derived
{
    void doSomethingMore()
    {
        a = 10; // Allowed, a is protected member inside Derived & Derived2 is public derivation from Derived, a is now protected member of Derived2
        b = 20; // Allowed, b is protected member inside Derived & Derived2 is public derivation from Derived, b is now protected member of Derived2
        c = 30; // Not Allowed, Compiler Error
    }
};
int main()
{
    Derived2 obj;
    obj.a = 10; // Not Allowed, Compiler Error
    obj.b = 20; // Not Allowed, Compiler Error
    obj.c = 30; // Not Allowed, Compiler Error

    Derived obj;
    obj.a = 10; // Not Allowed, Compiler Error
    obj.b = 20; // Not Allowed, Compiler Error
    obj.c = 30; // Not Allowed, Compiler Error

    return 0;
} */
