/*
 Program: Temperature Control Logic (Embedded Style)
 Purpose:
 - Read temperature value (simulating sensor input)
 - Decide heater and fan status using boolean flags
 - Demonstrates real firmware-style decision logic
*/

#include <iostream>
using namespace std;

int main()
{
    int temperature;     // Simulated temperature sensor reading
    bool heater = false; // Heater control flag
    bool fan = false;    // Fan control flag

    // Read temperature input
    cout << "Enter temperature: ";
    cin >> temperature;

    // Decision logic
    if (temperature < 20)
    {
        heater = true;
        fan = false;
    }
    else if (temperature > 30)
    {
        fan = true;
        heater = false;
    }
    else
    {
        heater = false;
        fan = false;
    }

    // Output system status
    cout << "\nSystem Status:\n";
    cout << "Heater: " << (heater ? "ON" : "OFF") << endl;
    cout << "Fan   : " << (fan ? "ON" : "OFF") << endl;

    return 0;
}
