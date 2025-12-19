/*
 Program: Swap two numbers using Call by Value
 Concept:
 - Copies of variables are passed to the function
 - Original values in main() do NOT change
*/

#include <iostream>
using namespace std;

void swapByValue(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a = 10, b = 20;

    cout << "Before swap (main): ";
    cout << "a = " << a << ", b = " << b << endl;

    swapByValue(a, b);

    cout << "After swap (main): ";
    cout << "a = " << a << ", b = " << b << endl;

    return 0;
}
