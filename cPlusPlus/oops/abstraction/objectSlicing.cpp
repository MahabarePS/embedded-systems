#include<iostream>
using namespace std;
class Employee{
    protected:
        int id;
    public:
        Employee(int i){
            id =i;
        }
        virtual void display(){
            cout<<"EmployeeID: "<<id<<endl;
        }
};
class Manager: public Employee{
    protected:
        int bonus;
    public:
        Manager(int i, int b): Employee(i){
            bonus = b;
        }
        virtual void display(){
            cout<<"Employee ID: "<<id<<endl;
            cout<<"Bonus: "<<bonus<<endl;
        }
        void print(Employee e){
            e.display();
        }
};
int main(){
    Manager m(201,5000);
    cout<<"Using derived object directly!"<<endl;
    m.display();

    cout<<"After Object Slicing: "<<endl;
    Employee e = m;//directly copying derived object to base - Object Slicing
    e.display();
    
    //
    cout<<"Using Base Class Pointer: "<<endl;
    Employee *ptr = &m;
    ptr->display(); // manager:Display()

    //
    cout<<"Using Base Class referencec: "<<endl;
    Employee &ref = m;
    ref.display();// manager:Display()

    return 0;
}