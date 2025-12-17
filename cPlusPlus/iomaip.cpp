#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double pi =3.14159;
    cout<<"Pi value: " << setprecision(2) << pi << endl;
    cout<<"Pi value: " << fixed <<setprecision(2) << pi << endl;

    cout<< setw(10) << 25 << endl;
    cout<< setw(5) << 123456 << endl;
    return 0;
}