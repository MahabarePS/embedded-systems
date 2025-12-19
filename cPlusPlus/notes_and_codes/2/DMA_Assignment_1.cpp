/*
Problem Statement : Write a C++ program that:
- Asks the user for the size of an array (n).
- Dynamically allocates an array of integers of size n using new.
- Takes n integer inputs from the user and stores them in the array.
- Performs the following operations:
    - Find the sum of all elements.
    - Compute the average of the elements.
    - Find the maximum and minimum elements.
    - Displays the array and the results.
- Properly deallocates the memory using delete[].
*/

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Please Enter Array Size: ";
    cin >> n;

    // Dynamically allocate array
    int *arr = new int[n];

    // Input elements
    cout << "Please Enter Array Elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Initialize sum, max, min
    int sum = 0;
    int max = arr[0];
    int min = arr[0];

    // Compute sum, max, min
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }

    // C++ style which is better , C style is double average = (double)(sum) / n
    double average = static_cast<double>(sum) / n;

    // Display results
    cout << "\nArray elements: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\nSum = " << sum;
    cout << "\nMaximum = " << max;
    cout << "\nMinimum = " << min;
    cout << "\nAverage = " << average << endl;

    // Deallocate memory
    delete[] arr;
    arr = nullptr; // good practice

    return 0;
}
