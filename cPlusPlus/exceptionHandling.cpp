#include<iostream>
using namespace std;
int main(){
    int a,b;

    cout<<"Enter two integers:";
    cin>>a>>b;

    try{
        if(b==0){
            throw(1);
        }
        cout<<"Result = "<<a/b<<endl;
    }
    catch(int){
        cout<<"Error: Division by zero is not allowed!"<<endl;
    }
    cout<<"Program conitues normally.."<<endl;
    return 0;
}