#include<iostream>
#include<string>
using namespace std;

class Base{
    public:
        virtual void show(){
            cout<<" Base class show"<<endl;
        }
};

class Derived: public Base{
    public:
        void show(){
            cout<<" Derived class show"<<endl;
        }
};
int main(){
    Base *ptr=nullptr;
    Base b;
    Derived d;

    ptr=&b;
    ptr->show();

    ptr=&d;
    ptr->show();
    return 0;
}