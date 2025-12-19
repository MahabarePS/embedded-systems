/*
 Program: Swap two numbers using Call by Address Using Pointers
 Concept:
 - Addresses of variables (with the help of pointers) are passed
 - values of actual arguments are changed in the function using pointers and dereferencing (Function modifies actual memory locations)
 - Changes reflect in main()
*/

#include <iostream>
using namespace std;

void swapByAddress(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main()
{
    int a = 10, b = 20;

    cout << "Before swap (main): ";
    cout << "a = " << a << ", b = " << b << endl;

    swapByAddress(&a, &b);

    cout << "After swap (main): ";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
