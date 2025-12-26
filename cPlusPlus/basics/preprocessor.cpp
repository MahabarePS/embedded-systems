/*
PS: why to use const than preprocessor 
*/
#include<iostream>
#include<iomanip>
using namespace std;
#define PI 3.14
#define SQR(X) X*X
int main(){
    int age = 20;
    float marks = 85.5;
    char grade = 'A';
    bool isPassed = true;

    //const
    cout << "Value of age is: "<< age << endl;
    cout << "Value of marks is: "<< marks << endl;

    //macro
    const int value = 3+2;
    cout<< "Pi" << SQR(3+2) << endl;

    //Implicit type casting
    int x1 = 10;
    double y = 3;
    cout << "Division: " << x1/y << endl;
    //Explicit type casting
    int x = 10;
    double z = (int)y;
    cout << "Division: " << x/y << endl;
    return 0;
}