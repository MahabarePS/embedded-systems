// Goal :
// - using cin to get user input
// - Arithmatic Operators
//   - + , - , * , / , %
// - Increment and Decrement OPerators (pre and post)
// - sizeof() operator

#include <iostream>
using namespace std;

int main()
{
    int age;
    cout << "Please Enter Your Age : ";
    cin >> age;

    cout << "Your age is: " << age << endl;

    int a, b;
    cin >> a >> b;
    cout << "Sum = " << a + b;
    // Do for the rest of the Arithmatic operators

    // Operator Precedence
    int x;
    x = 18 + (7 - 3) * 9 % 2 * 5 - 2;
    cout << "The Value of x is : " << x << endl;

    // Increment / Decremmet Operators - pre and post

    a = 5;
    x = (++a) + 2 + a;
    cout << "Value of x (pre-inc) = " << x << endl;

    a = 5;
    x = (a++) + 2 + a;
    cout << "Value of x (post-inc) = " << x << endl;

    a = 5;
    x = (--a) + 6 - a;
    cout << "Value of x (pre-dec) = " << x << endl;

    a = 5;
    x = (a--) + 6 - a;
    cout << "Value of x (post-dec) = " << x << endl;

    // sizeof() operator
    cout << "Size of Integer is : " << sizeof(int);
    cout << "Size of Double is : " << sizeof(double);

    return 0;
}
