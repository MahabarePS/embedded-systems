/*
Problem Statement : Same Code as Assignment_1 , but use functions

Note :
- Dynamic Arrays are passed to functions using pointers
- Inside the function, arr[i] works normally.
- Any modification to elements affects the original array, because the pointer points to the same memory.
- Always pass the size, without which the function cannot know the array length.
*/

#include <iostream>
using namespace std;

// Function to calculate sum
int arraySum(int *arr, int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    return sum;
}

// Function to find maximum
int arrayMax(int *arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;
}

// Function to find minimum
int arrayMin(int *arr, int n)
{
    int min = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }

    return min;
}

// Function to calculate average
double arrayAverage(int *arr, int n)
{
    int sum = arraySum(arr, n);
    return static_cast<double>(sum) / n;
}

// Function to print array
void printArray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()
{
    int n;
    cout << "Plesae Enter Array Size: ";
    cin >> n;

    int *arr = new int[n];

    cout << "Please Enter Array Elements : ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "\nArray elements Are : ";
    printArray(arr, n);

    cout << "Sum = " << arraySum(arr, n) << endl;
    cout << "Maximum = " << arrayMax(arr, n) << endl;
    cout << "Minimum = " << arrayMin(arr, n) << endl;
    cout << "Average = " << arrayAverage(arr, n) << endl;

    delete[] arr;
    arr = nullptr;

    return 0;
}
