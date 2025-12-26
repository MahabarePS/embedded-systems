#include<iostream>
using namespace std;
int main(){
    int a,b;
    cout<<"Enter the Integers:";
    cin>>a>>b;

    try{
        if(b==0){
            throw 0;
        }
        if(a<0 || b<<0){
            throw "Negative Values";
        }
        if(a>9999){
            throw 3.14; //double
        }
        if(b>9999){
            throw 3.19f; //float
        }
        cout<<"Result = "<<a/b<<endl;
    }
    catch(int){
        cout<<"Error: Division by zero!"<<endl;
    }
    catch(const string msg){
        cout<<"Error: "<<msg<<endl;
    }
    catch(...){
        cout<<"Unknown: Catpured unknown exception"<<endl;
    }
    cout<<"Program continues normally!"<<endl;
    return 0;
}