/*
 Program: Swap two numbers using Call by Reference (C++ Feature)
 note : C does not support call by reference because it does not have reference variables.
 The language was designed to be simple and close to hardware,
 so pointers were used instead to allow modification of actual variables.

 Concept:
 - Reference variables act as aliases (same memory location - 2 names)
 - No pointers required
 - Changes reflect in main()
 - Cleaner and Safer than pointers
*/

#include <iostream>
using namespace std;

void swapByReference(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 10, b = 20;

    cout << "Before swap (main): ";
    cout << "a = " << a << ", b = " << b << endl;

    swapByReference(a, b);

    cout << "After swap (main): ";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
