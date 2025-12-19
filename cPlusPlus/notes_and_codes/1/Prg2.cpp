// Goal :
// - Data Types in CPP
// - variables and constants
// - Diff Between const and #define
// - Type Conversion (Implicit and Explicit)

#include <iostream>
using namespace std;

#define macropi 3.14
#define SQR(x) x *x // IMP : never end a macro with a ';' as it will get substituted in the code

int main()
{
    int age = 20;
    float marks = 85.5;
    char grade = 'A';
    bool isPassed = true;

    const double pi = 3.14159;

    age = 30; // allowed
    // pi = 3.5; // not allowed

    cout << "Value of Age is : " << age << endl;
    cout << "Value of pi is : " << pi << endl;
    cout << "Value of macroPi is " << macropi << endl; // here both const and #define work kind of the same

    // Const vs #define - where they differ
    // Note : Macros don’t calculate — they only replace text

    const int value1 = 3 + 2;
    cout << "With const : " << value1 * value1 << endl; // correct result - 25
    cout << "With macro : " << SQR(3 + 2) << endl;      // wrong result : direct substitution 3 + 2 * 3 + 2 = 11

    // Type Conversion
    // 1. Implicit
    int a = 10;
    double b = a; // automatic

    cout << "Integer Division : " << a / 3 << endl;
    cout << "Float Division : " << b / 3 << endl;

    // 2. Explicit (type casting)
    double x = 9.8;
    int y = (int)x; // 9

    cout << "Value of x is : " << x << endl;
    cout << "Value of y is : " << y << endl;

    //
}