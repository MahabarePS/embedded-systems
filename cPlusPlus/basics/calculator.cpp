/*
PS: create a calculator and take the operator as a choice from user
*/
#include<iostream>
using namespace std;
int main(){
    char ch;
    do{
    cout<<"-----Calculator-----"<<endl;
    int op1;
    cout<<"Enter 1st operand: ";
    cin>>op1;

    int op2;
    cout<<"Enter 2nd operand: ";
    cin>>op2;

    int result;
    
    cout<<"Operator list:"<<endl;
    cout<<"Enter the operator from the above list: ";
    cin>>ch;
    switch(ch){
        case '+': result = op1 + op2;
                    cout<<"Addition is: "<<result<<endl; 
                    break;
        case '-': result = op1 - op2;
                    cout<<"Subtraction is: "<<result<<endl; 
                    break;
        case '/': if(op2!=0){
                    result = op1 / op2;
                    cout<<"Division is: "<<result<<endl;
                    } 
                    else{
                        cout<<"cannot be divided by zero!"<<endl;
                    }
                    break;
        case '*': result = op1 * op2;
                    cout<<"Multiplication is: "<<result<<endl; 
                    break;
        case '%': result = op1 % op2;
                    cout<<"Modulus is: "<<result<<endl; 
                    break;
        default:
                cout<<"Invalid operator!"<<endl;
                break;
    }
}while(ch!=' ');
    return 0;
}