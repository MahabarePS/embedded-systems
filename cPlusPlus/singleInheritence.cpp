#include<iostream>
using namespace std;
class Person{
    protected:
        string name;
        string address;
        void disp() const{
            cout<<"Name     : "<<name<<endl;
            cout<<"Address  : "<<address<<endl;
        }
    public:
        //default
        Person(): name(" "),address(" "){};
        //parameterized
        Person(const string &nm, const string &add): name(nm), address(add){}
        void UpdatedAddress(const string &newAddress){
            address = newAddress;
        }
};
class Employee: public Person{
    int id;
    double basicSal, hra, ta, da;
        
    public:
        Employee():id(0),basicSal(0),hra(0),da(0){};
        Employee(int id, const string &nm, const string &add, double bs)
        : Person(nm, add), id(id), basicSal(bs){
            ta = basicSal * 0.10;
            da = basicSal * 0.20;
            hra = basicSal * 0.15;
        }

        void Disp() const{
            cout<<"Employee Id: "<<id<<endl;
            Person::disp();
            cout<<"Salary Details: "<<endl;
            cout<<"Basic Salary: "<<basicSal<<endl;
            cout<<"HRA: "<<hra<<endl;
            cout<<"TA: "<<ta<<endl;
            cout<<"DA: "<<da<<endl;

            cout<<"Total Salary: "<<calSal()<<endl;
        }
    private:
        double calSal() const{
            return basicSal + hra + ta + da;
        }
};
int main(){
    Employee E1(10,"Prasad","Pune",90000);
    E1.Disp();
    E1.UpdatedAddress("USA");
    E1.Disp();
    return 0;
}