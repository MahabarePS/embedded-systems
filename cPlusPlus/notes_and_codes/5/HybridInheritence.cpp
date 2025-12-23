/*
Program : Hybrid Inheritance in C++


Hybrid Inheritance is a combination of two or more types of inheritance. In this example, we see:

Hierarchical Inheritance
   base - d1
   base - d2

Multiple Inheritance
   d3 inherits from both d1 and d2

This creates a "Diamond Structure":

            base
           /    \
         d1      d2
           \    /
             d3

Problem:
Without using virtual inheritance, class d3 would get TWO copies of class base:
- One via d1
- One via d2

This causes ambiguity when accessing members of base.

Solution:
Use virtual inheritance while inheriting base in d1 and d2 so that only ONE shared copy of base exists in d3.
*/

#include <iostream>
using namespace std;

/*
Base class
Contains a single integer variable 'i'.
This class will be shared by both d1 and d2.
*/
class base
{
protected:
    int i = 5; // Accessible in derived classes
};

/*
Derived class d1
- Inherits from base
- Uses VIRTUAL inheritance to avoid duplicate base
*/
class d1 : virtual public base
{
protected:
    int j = 6;
};

/*
Derived class d2
- Also inherits from base
- Uses VIRTUAL inheritance for the same reason
*/
class d2 : virtual public base
{
protected:
    int k = 7;
};

/*
Derived class d3
- Inherits from both d1 and d2
- Because d1 and d2 use virtual inheritance, d3 contains ONLY ONE copy of base
*/
class d3 : public d1, public d2
{
private:
    int sum;

public:
    // Function: calSum() : Adds values of i, j, and k inherited from base, d1, and d2 respectively.
    int calSum()
    {
        return (i + j + k);
    }
};

int main()
{
    d3 ob;
    cout << "Sum = " << ob.calSum();
    return 0;
}
