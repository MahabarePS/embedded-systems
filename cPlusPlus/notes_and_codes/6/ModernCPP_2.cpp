/*
In this Code we will look at :
1. NULL Vs nullptr
2. Problem with NULL in function overloading

IMPORTANT CONCEPT:
 - NULL looks like a pointer, but behaves like an integer.
    - In C++, NULL is typically defined as 0.
    - This can confuse the compiler when functions are overloaded.
- nullptr clearly tells the compiler "this is a pointer".
*/

#include <iostream>
using namespace std;

void f(int x)
{
  cout << "int version called\n";
}

void f(int *p)
{
  cout << "pointer version called\n";
}

int main()
{

  /*
    Using NULL:
    - NULL is treated as 0 (integer).
    - So the compiler cannot decide whether to call:
      - f(int)  or
      - f(int*)
    - This causes ambiguity.
  */

  // f(NULL);   // ERROR: ambiguous call

  /*
    Using nullptr:
    - nullptr is a C++ keyword (introduced in C++11).
    - It represents a null POINTER ONLY.
    - It is NOT an integer.
    - Hence, the compiler clearly selects f(int*).
  */

  f(nullptr); // pointer version called

  return 0;
}
