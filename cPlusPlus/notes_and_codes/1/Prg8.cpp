// Max of 3 nos

#include <iostream>
using namespace std;

int main()
{
    int a, b, c, max;
    cout << "Please Enter 3 nos : ";
    cin >> a >> b >> c;

    if (a > b)
    {
        if (a > c)
            max = a;
        else
            max = c;
    }
    else
    {
        if (b > c)
            max = b;
        else
            max = c;
    }

    cout << max << " is the Greatest - Using if-else" << endl;

    // Conditional Operator
    max = a > b ? (a > c ? a : c) : (b > c ? b : c);
    cout << max << " is the Greatest - Using Ternary Operator" << endl;
    return 0;
}