/*
Order Of Constructor (and Destructor) Calling in Inheritrence:

- Base class constructors are always called in the derived class constructors.
(Because the derived object is built on top of the base object, so the base part must exist first)
- Whenever you create derived class object, first the base class default constructor is executed and
then the derived class's constructor finishes execution.
- Whether derived class's default constructor is called or parameterised is called,
base class's default constructor is always called inside them.
- To call base class's parameterised constructor inside derived class's parameterised constructor,
we must mention it explicitly while declaring derived class's parameterized constructor
- Destructors are Called in Reverse Order
*/

#include <iostream>
using namespace std;

class Base
{
protected:
    int x;

public:
    Base()
    {
        cout << "Base Class Default Constructor Called\n";
        x = 0;
    }

    Base(int x)
    {
        cout << "Base Class Parameterized Constructor Called\n";
        this->x = x;
    }

    ~Base()
    {
        cout << "\nBase Class Destructor Called\n";
    }
};

class Derived : public Base
{

private:
    int z;

public:
    Derived()
    {
        cout << "Derived Class Default Constructor Called\n";
        z = 0;
    }

    /*
    // Even though Derived Parameterised constructor is called , this will call Base Class Default Constructor
    Derived(int x, int z)
    {
        cout << "Derived Class Parameterized Constructor Called\n";
        this->z = z;
    } */

    // Explicit call to Base CLass Parameterised Constructor
    Derived(int y, int z) : Base(y)
    {
        cout << "Derived Class Parameterized Constructor Called\n";
        this->z = z;
    }

    void Display()
    {
        cout << "x = " << x;
        cout << "z = " << z;
    }

    ~Derived()
    {
        cout << "\nDerived Class Destructor Called\n";
    }
};

int main()
{
    // Derived d;
    Derived d(5, 8);
    d.Display();
    return 0;
}
