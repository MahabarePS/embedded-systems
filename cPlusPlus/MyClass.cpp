#include<iostream>
using namespace std;
class MyClass{
    public:
    int myNum;
    string myString;
};

int main(){
    MyClass obj;
    //access attributes and set values
    obj.myNum = 15;
    obj.myString = "some text";
    //printing attricutes
    cout<<"-----Class Demo-----"<<endl;
    cout<<obj.myNum<<endl;
    cout<<obj.myString<<endl;
    return 0;
}