/*
What is "Modern C++" ? "
- Modern C++ (from C++11 onwards) introduced features to:
- Reduce bugs
- Improve memory safety
- Make code cleaner and shorter
- Replace unsafe old practices (raw pointers, NULL, manual memory)

In this Code we will look at :
1. auto keyword
2. range based loop

*/

#include <iostream>
#include <vector>
using namespace std;

int main()
{

    /* auto keyword :
    - auto tells the compiler: "Figure out the data type automatically"
    - auto is NOT for saving typing.
    - auto is for correctness, safety, and readability in complex types.
    */

    // Here it is of little advantage
    // old method
    // int x = 8;
    // int y = 9;

    // using auto
    // auto x = 8; // compiler knows x is int
    // auto y = 9; // compiler knows y is int

    // Where 'auto' really helps
    vector<int> v = {1, 2, 3};

    // Without auto - we need to put 'vector<int>::iterator it' (datatype of iterator) every time
    for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // With auto (modern C++)
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    // Traditional for loop
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i];
        cout << x << " ";
    }

    // Range-based for loop WITHOUT auto
    for (int x : v) // type written explicitly
    {
        cout << x << " ";
    }
    cout << endl;

    // Range-based for loop WITH auto - This is the simplest and cleanest
    for (auto x : v) // compiler deduces int
    {
        cout << x << " ";
    }
    cout << endl;
}