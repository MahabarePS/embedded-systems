#include<iostream>
using namespace std;
class Base{
    public:
        virtual void show(){
            cout<<"Base Show()!"<<endl;
        }
};  
class Derived: public Base{
    public:
        void show() override final{
            cout<<"Derived show()!"<<endl;
        }
};
class Child: public Derived{
    public:
    // void show(){
    //     cout<<"Derived show()"<<endl;
    // }
        void display(){
            cout<<"Child show()"<<endl;
        }
};
//Final base class demo
class Utility final{
    public:
        void helper(){
            cout<<"Utitlity helper()"<<endl;
        }
};
// class Electriticy: public Utility{

// };
int main(){
    Base *b;
    b->show();//calls Base:show()

    Derived d;

    b = &d;
    b->show();//calls Derived:show()

    Utility u;
    u.helper();//normal objedt

    return 0;
}