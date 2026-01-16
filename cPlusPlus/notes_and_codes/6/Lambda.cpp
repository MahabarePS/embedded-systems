/*
What is a Lambda Expression?
A lambda is a small, anonymous function that you can write inline, without giving it a name.
Lambda = function written at the place where it is used.

Why do we need lambdas? Before lambdas, you had to:
- write a separate function, or
- create a function object (class)

Lambdas let you:
- write quick logic at the place of use
- avoid unnecessary function definitions

Syntax:
[capture](parameters)
{
    // function body
};

Capture list [] - For now, remember this rule:

[]      - use nothing from outside
[x]     - use variable x by value
[&x]    - use variable x by freference
[=]     - capture everything by value
[&]     - capture everything by reference

When to use lambdas ?
 - Logic is small
 - Used only once
 - Used with STL algorithms

Diff Between Lambdas and Inline Functions

Inline : Inline functions are reusable named functions.
- A named function
- Defined once, used many times
- inline is a hint to the compiler (inline does not mean "this function will definitely be inlined".)
- Inline function cannot use local variables

Lambdas : Lambdas are small, local, one-time functions.
- An anonymous function object
- Usually used at the place of use
- Stored in a variable
- Lambda can capture local variables
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
Regular Function:
- Defined separately
- Has a name
*/
bool isEven(int x)
{
    return x % 2 == 0;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6};

    // USING REGULAR FUNCTION
    // count_if counts how many elements in a range satisfy a condition.
    int count1 = count_if(v.begin(), v.end(), isEven);

    cout << "Even numbers (using regular function): " << count1 << endl;

    // USING LAMBDA FUNCTION
    int count2 = count_if(v.begin(), v.end(),
                          [](int x)
                          {
                              return x % 2 == 0;
                          });

    cout << "Even numbers (using lambda): " << count2 << endl;

    // Example 2: Capture By Value  - We want a lambda to use a variable defined ouside it
    //  - [limit] copies the variable limit into the lambda.
    //  - Lambda gets its own copy
    //  - Original limit cannot be changed inside the lambda

    int limit = 3;

    int count = count_if(v.begin(), v.end(),
                         [limit](int x) { // capture limit by VALUE
                             return x > limit;
                         });

    cout << "Numbers greater than " << limit << " = " << count << endl;

    // Example 2: Capture By Reference - Lambda uses the same variable, not a copy
    count = count_if(v.begin(), v.end(),
                     [&limit](int x) { // capture limit by reference
                         return x > limit;
                     });
    cout << "Numbers greater than " << limit << " = " << count << endl;

    // Example 3: Capture All By Value - capture all used variables (in the scope) by value
    int a = 10;
    int b = 20;

    // why auto ? lambda is a function object with an unnamed type
    // The lambda has a compiler-generated, anonymous type
    // auto deduces the lambda’s type, not the return type
    // Note : lam - the lambda (function object) , not the function return
    auto lam = [=]()
    {
        return a + b; // a and b are captured by value
    };

    // Call the lamda function
    cout << "Addition is :" << lam();
    return 0;
}
