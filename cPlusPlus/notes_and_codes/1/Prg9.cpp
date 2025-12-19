// WAP to check whether a number is Armstrong number.
// 3 digit number :	e.g 153  : 1^3 + 5^3 + 3^3 = 153
// 4 digit number : e.g 1634 : 1^4 + 6^4 + 3^4 + 4^4 = 1634

#include <iostream>

using namespace std;

void armstrong(int);

int main()
{
    int n;
    cout << "Please Enter a number : ";
    cin >> n;
    armstrong(n);
    return 0;
}

void armstrong(int x)
{
    int sum = 0, d, temp, no_of_digits = 0;

    temp = x; // save the number

    // Find out no Of Digits
    while (x > 0)
    {
        no_of_digits++;
        x = x / 10;
    }

    cout << "No Of Digits is : " << no_of_digits << endl;

    x = temp; // reassign the number

    while (x > 0)
    {
        d = x % 10; // digit in units place

        // this loop is for raising d to the power of (no_of_digits)
        int pow = 1;
        for (int i = 1; i <= no_of_digits; i++)
        {
            pow = pow * d;
        }

        sum = sum + pow;
        x = x / 10; // remove last digit, and get the new num
    }

    if (temp == sum)
        cout << temp << " is an Armstrong  number" << endl;
    else
        cout << temp << " is NOT an Armstrong  number" << endl;
}