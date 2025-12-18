#include<iostream>
using namespace std;
int main(){
    int *ptr = new int; // will contain garbage value
    cout<<"before assigning the value:"<<endl;
    cout<< "*ptr: "<<*ptr<<endl;
    cout<<"After asigning the value:"<<endl;
    *ptr = 25;
    cout<< "*ptr: "<<*ptr<<endl;
    delete ptr;

    int *p1 = new int(); // initialitized to 0
    cout<<"Initialized to 0"<<endl;
    cout<<"*p1: "<<*p1<<endl;
    delete p1;

    int *p2 = new int(30); // initialized to custom value
    cout<<"custom value for pointer"<<endl;
    cout<<"*p2: "<<*p2<<endl;
    delete p2;

    ptr = p1 = p2 = nullptr; // free the pointers 
    return 0;
}