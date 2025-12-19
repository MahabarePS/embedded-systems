#include <iostream>
using namespace std;

/*
 Program: Engine Start Authorization System
 Purpose:
 - Authorize engine start based on safety conditions
   Engine can start only if ALL conditions are satisfied:
    - Fuel level > 20%
    - Temperature < 90°C
    - Battery voltage ≥ 11.5V
*/

int main()
{
    int fuelLevel;        // Fuel percentage
    int temperature;      // Engine temperature (°C)
    float batteryVoltage; // Battery voltage (V)

    cout << "Enter fuel level (%): ";
    cin >> fuelLevel;

    cout << "Enter engine temperature (C): ";
    cin >> temperature;

    cout << "Enter battery voltage (V): ";
    cin >> batteryVoltage;

    if (fuelLevel > 20 && temperature < 90 && batteryVoltage >= 11.5)
    {
        cout << "\nEngine Start: AUTHORIZED" << endl;
    }
    else
    {
        cout << "\nEngine Start: DENIED" << endl;

        // Optional diagnostic messages
        if (fuelLevel <= 20)
            cout << "- Fuel level too low" << endl;
        if (temperature >= 90)
            cout << "- Engine temperature too high" << endl;
        if (batteryVoltage < 11.5)
            cout << "- Battery voltage low" << endl;
    }

    return 0;
}
