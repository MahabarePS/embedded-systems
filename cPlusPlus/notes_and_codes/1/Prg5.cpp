/*
 Program: Find Maximum of Two Numbers
 Method 1 : Using if–else
 Method 2 : Using Conditional / Ternary Operator
            Syntax : condition ? value_if_true : value_if_false;
*/

#include <iostream>
using namespace std;

int main()
{
    int a, b, max;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    // if-else

    if (a > b)
        max = a;
    else
        max = b;
    cout << "Maximum value (using if-else) is: " << max << endl;

    // Ternary Operator
    max = (a > b) ? a : b;
    cout << "Maximum value (using ternary operator) is: " << max << endl;

    return 0;
}
