/*
Problem Statement
Design a C++ program to demonstrate function overloading by creating a class that
performs addition operations on different data types and different numbers of operands.
The same function name should be used to add integers, floating-point numbers, double
values, and strings.
Requirements
1. Create a class named AddDemo.
2. Implement overloaded add() functions to:
o Add two integers
o Add three integers
o Add two floats
o Add three floats
o Add two doubles
o Add three doubles
o Concatenate two strings
3. Ensure that:
o All functions use the same function name
o The functions differ only in number and/or type of parameters
4. Demonstrate the working of each overloaded function in the main() function.
*/
#include<iostream>
#include<string>
using namespace std;
class AddDemo{
    public:
        //Add two integers
        void add(int, int);
        //Add three integers
        void add(int, int, int);
        //Add two floats
        void add(float, float);
        //Add three floats
        void add(float, float, float);
        //Add two doubles
        void add(double, double);
        //Add three doubles
        void add(double, double, double);
        //Concatenate two strings
        void add(string, string);
};
void AddDemo::add(int num1, int num2){
    cout <<"Addition of two integers: "<< num1 + num2;
}
void AddDemo::add(int num1, int num2, int num3){
    cout<<"Addition of three integers: "<< num1 + num2 + num3;
}
void AddDemo::add(float num1, float num2){
    cout<<"Addition of two float: "<< num1 + num2;
}
void AddDemo::add(float num1, float num2, float num3){
    cout<<"Addition of three float: "<< num1 + num2 + num3;
}
void AddDemo::add(double num1, double num2){
    cout<<"Addition of two double: "<< num1 + num2;
}
void AddDemo::add(double num1, double num2, double num3){
    cout<<"Addition of three double: "<< num1 + num2 + num3;
}
void AddDemo::add(const string str1, const string str2){
    cout<<"Concatenation:    "<< str1 + str2;
}
int main(){
    int ch;
    //creating class object
    AddDemo ad;
    do{
    cout<<"-----function overloading------"<<endl;
    cout<<"1. Add two integers "<<endl;
    cout<<"2. Add three integers "<<endl;
    cout<<"3. Add two float "<<endl;
    cout<<"4. Add three float "<<endl;
    cout<<"5. Add two double "<<endl;
    cout<<"6. Add three double "<<endl;
    cout<<"7. Add two Strings"<<endl;
    cout<<"8. Exit"<<endl;
    cout<<"-------------------------------"<<endl;
    cout<<"Enter your choice:   ";
    cin>>ch;
    switch(ch){
        case 1: {int num1, num2;
                cout<<"Enter two integers:  ";
                cin>>num1>>num2;
                ad.add(num1,num2);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 2: {int num1, num2, num3;
                cout<<"Enter three integers:  ";
                cin>>num1>>num2>>num3;
                ad.add(num1,num2,num3);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 3: {float num1, num2;
                cout<<"Enter two float:  ";
                cin>>num1>>num2;
                ad.add(num1,num2);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 4: {float num1, num2, num3;
                cout<<"Enter three float:  ";
                cin>>num1>>num2>>num3;
                ad.add(num1,num2,num3);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 5: {double num1, num2;
                cout<<"Enter two double:  ";
                cin>>num1>>num2;
                ad.add(num1,num2);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 6: {double num1, num2, num3;
                cout<<"Enter three double:  ";
                cin>>num1>>num2>>num3;
                ad.add(num1,num2,num3);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 7: {string str1, str2;
                cout<<"Enter two strings:  ";
                cin>>str1;
                cin>>str2;
                ad.add(str1,str2);
                cout<<"\n-------------------------------"<<endl;
                break;}
        case 8: cout<<"Exiting program..."<<endl;
                break;
        default: cout<<"Invalid choice!  ";
                break;
        }
    }while(ch!=8);
    return 0;
}