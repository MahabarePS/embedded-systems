// Goal : Control Flow Statements
// if - else
// if-else ladder
// nested if

#include <iostream>
using namespace std;

int main()
{

    // if - else
    int voltage = 11;

    if (voltage >= 12)
        cout << "Battery OK";
    else
        cout << "Battery LOW";

    // if-else ladder - Conditions checked top to bottom.
    int speed = 65;

    if (speed < 30)
        cout << "Low speed";
    else if (speed <= 60)
        cout << "Normal speed";
    else
        cout << "Over speed";

    // nested if

    int temp = 35;
    int humidity = 80;

    if (temp > 30)
    {
        if (humidity > 70)
            cout << "Turn ON cooler" << endl;
    }
    else
    {
        if (humidity > 70)
            cout << "Turn ON fan" << endl;
        else
            cout << "its comfortable as is !!" << endl;
    }
}