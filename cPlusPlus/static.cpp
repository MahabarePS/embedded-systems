#include<iostream>
using namespace std;

class MyClass{
    private:
        static int count;
        int id;
    public:
        MyClass(int x){
            id=x;
            count++;
        }
        void showDetails(){
            cout<<"ID = "<<id<<endl;
            //cout<<"COUNT = "<<id<<endl;
        }
        static void showStaticCount(){
            cout<<"COUNT = "<<count<<endl;
        }
};
int MyClass::count = 0;
int main(){
    MyClass a(101),b(102);

    a.showDetails();
    b.showDetails();

    MyClass::showStaticCount();

    return 0;
}