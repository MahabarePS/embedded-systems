// Goal :
// - Basic Structure of a CPP program

// - Using cin and cout
//   - iostream : Header for input/output operations
//     Provides: cin , cout , cerr
//   - namespace std : All standard library features are inside std
//     Without namespace: we will need to prefix std everytime (std::cout << "Hello";)
// - Manipulators (#include <iomanip>)
//   - endl             : newline (can also use \n like C)
//   - setw(n)	        : set width ; sets the minimum width of the next output only.
//     (one shot)         Output is right-aligned by default
//                        if value is smaller than width → spaces added on the left
//                        If value is bigger → width is ignored
//   - fixed (sticky)   : display floating-point numbers in fixed-point notation
//                      : VIMP : fixed (once set) stays active until changed
//                        to  remove fixed, you would need: cout << defaultfloat;
//   - setprecision(n)  : Without fixed : precision = total digits
//     (sticky)           With fixed : precision = digits after decimal
//                        VIMP : setprecision (once set) stays active until changed
//                        to reset it u need to : cout << defaultfloat << setprecision(6);

// RULE : Anytime formatting is done, reset it immediately after

// Compile and run:
// - goto the correct folder with cd
// - g++ prg1.cpp , and then ./a (since default executatble is a.exe)
// - g++ prg1.cpp -o prg1 and then ./prg1 (that will be the executable)

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << "Hello, C++!" << endl;

    double pi = 3.14159;

    cout << "Pi value with setprecision(2) without fixed: " << setprecision(2) << pi << endl;
    cout << "Pi value with setprecision(3) with fixed: " << fixed << setprecision(3) << pi << endl;

    // Note : fixed stays active till changed ..so actually 'fixed' is ON
    cout << "Pi value with setprecision(3) without fixed: " << setprecision(3) << pi << endl;

    // Removing fixed
    cout << defaultfloat;
    cout << "Pi value with setprecision(3) without fixed (after removing): " << setprecision(3) << pi << endl;

    // setw() : one shot manipulator - affects only the next output.
    cout << "setw(10) with 25 : " << setw(10) << 25 << endl;
    // Note : since setprecision is still active , value is 3.14 , which is what is being displayed
    cout << "setw(10) with pi : " << setw(10) << pi << endl;
    cout << "setw(5) with 123456 : " << setw(5) << 123456 << endl;

    // setting pi to default
    cout << defaultfloat << setprecision(6);
    cout << "setw(10) with pi after resetting default : " << setw(10) << pi << endl;
    // successful execution
    return 0;
}
