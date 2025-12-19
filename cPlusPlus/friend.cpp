#include<iostream>
using namespace std;
class base2;
class base1{
    int val1;
    public:
        void get(){
            cout<<"Enter value of class Base1: ";
            cin>>val1;
        }
        friend float average(base1 obj1, base2 obj2);
};
class base2{
    int val2;
    public:
        void get(){
            cout<<"Enter value of class Base2: ";
            cin>>val2;
        }
        friend float average(base1 obj1, base2 obj2);
};
float average (base1 obj1, base2 obj2){
    return float(obj1.val1 + obj2.val2)/2;
}
int main(){
    base1 obj1;
    base2 obj2;
    obj1.get();
    obj2.get();
    cout<<"Average value is: "<<average(obj1, obj2);
    return 0;
}
