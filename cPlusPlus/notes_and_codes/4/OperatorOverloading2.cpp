/*
OPERATOR OVERLOADING IN C++

This program demonstrates operator overloading using a user-defined
Complex number class.

Operators overloaded in this program:
1. +   : Adds two complex numbers
         Note : Please add the overlaoding for - , * , / and %
2. ==  : Compares two complex numbers for equality
3. >   : Compares two complex numbers for greater-than (compare based on magnitude , obj with greater mag is greater)
     - mag^2 = real^2 + imag^2
4. ++  : Pre and Post Increment (increments real and imaginary parts)
 - Pre-increment returns "me after change"
 - Post-increment returns "me before change"
5. --  : Pre and Post Decrement (decrements real and imaginary parts)

The program follows better C++ practices:
- Uses const and reference parameters
Note :
  - Using const : Ensures obj is not modified
  - Using reference : Avoids copying (uses the same object) so faster & efficient
- Distinguishes between pre and post increment/decrement

*/

#include <iostream>
using namespace std;

class Complex
{
private:
    int real;
    int imag;

public:
    // DEfault Constructor
    Complex()
    {
        real = 0;
        imag = 0;
    }

    // Parameterised Constructor
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    // Display complex number
    void display() const
    {
        cout << real << " + " << imag << "i" << endl;
    }

    // Overload + operator
    // Adds two Complex numbers

    /*
    - const Complex &obj : Right-hand operand (obj) cannot be modified
    - Last const : Left-hand operand (this) cannot be modified
    - Return type Complex : Result is a new object
    */
    Complex operator+(const Complex &obj) const
    {
        Complex res;
        res.real = this->real + obj.real; // 'this' is actually implied, just putting it for clarity; Not done in other methods
        res.imag = this->imag + obj.imag;
        // try this :
        // this->real = 5; // not allowed bcoz of const
        // obj.real = 5;   // not allowed bcoz oif const
        return res;
    }

    // Overload == operator
    // Compares two Complex numbers
    bool operator==(const Complex &obj) const
    {
        return (real == obj.real && imag == obj.imag);
    }

    // Overload > operator
    // Compares two Complex numbers based on magnitude
    // mag^2 = real^2 + imag^2
    // Note: sqrt is avoided for efficiency
    bool operator>(const Complex &obj) const
    {
        int mag1 = (real * real) + (imag * imag);
        int mag2 = (obj.real * obj.real) + (obj.imag * obj.imag);
        return mag1 > mag2;
    }

    // Pre-increment (++obj)
    // Complex& : return a reference to an existing (the current) Complex object , not a new object
    // Note : we are not using const here , because we are moifying the same object
    // ++ obj : it modifies the original object and It then returns the modified object
    Complex &operator++()
    {
        real++;
        imag++;
        // IMP:
        // return the current object itself
        // this : pointer to current object
        // *this : the current object (dereferencing !)
        // return type is ref to a complex object - So the function returns a reference to the same object
        return *this;
    }

    // Post-increment (obj++)
    // int parameter is dummy supplied by the compiler
    // obj++ : Use the original value and then increment (so , Modify the object , But return the old value)
    // This means :
    //    Complex old = obj; (step1)
    //    obj = obj + 1; (step2)
    //    return old; (step3) - since this is a temporray variable , we cannot return it as a reference
    // How is the dummy int used in main()? V.IMP
    //   c1++; is translated by the compiler as c1.operator++(0);
    //   0 goes into the dummy int and is ignored. It Exists only for function signature differentiation

    Complex operator++(int)
    {
        Complex old = *this; // step1 ; *this is the current object ; so old is storing a copy of the current object
        real++;
        imag++;     // step2
        return old; // step3
    }

    // Pre-decrement (--obj)
    Complex &operator--()
    {
        real--;
        imag--;
        return *this;
    }

    // Post-decrement (obj--)
    Complex operator--(int)
    {
        Complex temp = *this;
        real--;
        imag--;
        return temp;
    }
};

int main()
{
    Complex c1(3, 4);
    Complex c2(1, 2);
    Complex c3(3, 4);
    Complex c4(5, 4);

    cout << "c1 = ";
    c1.display();

    cout << "c2 = ";
    c2.display();

    cout << "c3 = ";
    c3.display();

    cout << "c4 = ";
    c4.display();

    // + operator
    Complex cx = c1 + c2;
    cout << "c1 + c2 = ";
    cx.display();

    // == operator
    if (c1 == c2)
        cout << "c1 and c2 are equal" << endl;
    else
        cout << "c1 and c2 are NOT equal" << endl;

    // > operator
    if (c1 > c4)
        cout << "c1 is greater than c4" << endl;
    else
        cout << "c1 is NOT greater than c4" << endl;

    // Pre-increment
    ++c1;
    cout << "After ++c1: ";
    c1.display();

    // Post-increment
    // when we write c2++ , compiler translates it to c2.operator++(0); The 0 is auto-supplied by compiler.
    // so it binds to the method Complex operator++(int)
    // c2++ increments c2 ; but Returned value is ignored

    // try this :
    Complex temp = c2++;
    cout << "Return value (original) : ";
    temp.display();
    cout << "After c2++:  : ";
    c2.display();
    // c2++;
    // cout << "After c2++: ";
    // c2.display();

    // Pre-decrement
    --c3;
    cout << "After --c3: ";
    c3.display();

    // Post-decrement
    c4--;
    cout << "After c4--: ";
    c4.display();
    */

        return 0;
}
