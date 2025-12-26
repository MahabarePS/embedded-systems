/*
PS: read 3 values from user and print the largest one
*/
#include<iostream>
using namespace std;
int main(){
    //get the values from the user
    int v1;
    cout << "Enter integer value_1: ";
    cin >> v1;

    int v2;
    cout << "Enter integer value_2: ";
    cin >> v2;

    int v3;
    cout << "Enter integer value_3: ";
    cin >> v3;

    cout<<endl;
    //compare values with each other 
    int max = v1 > v2 ? (v1>v3? v1:v3) : (v2>v3? v2:v3);
    cout << max << " Is the greatest of all the 3 values!"<<endl;
    return 0;
}