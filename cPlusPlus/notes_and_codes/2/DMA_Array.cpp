// Program :
// DMA for an Array

#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter size: ";
    cin >> n;

    int *arr = new int[n]; // dynamic array allocation

    cout << "Please Enter the Array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Array Elements Are : ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    delete[] arr; // IMPORTANT - NOT delete arr[]
    arr = nullptr;

    return 0;
}
