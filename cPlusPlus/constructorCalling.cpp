#include<iostream>
using namespace std;
class Base{
    protected:
        int x;
    public:
        Base(){
            cout<<"Base class deafult Cons"<<endl;
            x=0;
        }
        Base(int x){
            cout<<"Base class para Cons"<<endl;
            this->x = x;
            cout<<"x: "<<x<<endl;
        }
        ~Base(){}
};
class Derived: public Base{
    protected:
        int y;
    public: 
        Derived(){
            cout<<"Derived class deafult Cons"<<endl;
        }
        Derived(int x, int y):Base(x){
            cout<<"Dervived class para cons"<<endl;
            this->y=y;
            cout<<"y: "<<y<<endl;
        }
        void display(){
            cout<<"x: "<<x<<endl;
            cout<<"y: "<<y<<endl;
        }
        ~Derived(){}
};
int main(){
    Base b, b1(5);
    Derived d,d1(3,4);
    d.display();
    return 0;
}