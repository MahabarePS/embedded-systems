#include<iostream>
using namespace std;
#define size 2

class Employee{
    private:
        int empid;
        float empsal;
    public:
        void getdata(){
            cout<<"Enter Empid: ";
            cin>>empid;
            cout<<"Enter Emsal: ";
            cin>>empsal;
        }
        void printdata(){
            cout<<" The empid: "<<empid<<endl;
            cout<<" The empsal: "<<empsal<<endl;
        }
};
int main(){
    Employee e;
    Employee emp[size];

    cout<<"For signle object"<<endl;
    e.getdata();
    e.printdata();

    for(int i=0;i<size;i++){
        emp[i].getdata();
    }
    for(int i=0;i<size;i++){
        emp[i].printdata();
    }
    return 0;
}