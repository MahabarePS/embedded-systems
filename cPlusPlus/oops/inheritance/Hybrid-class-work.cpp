#include<iostream>
using namespace std;
class Employee{
    protected:
        static int empid;
        string name, address;
    public:
        Employee(const string &nm, const string &ad){
            //name validation
            if(nm.empty()){
                cout<<"\n[Warning]:***Enter Employee Name! ***"<<endl;
            }else{
                name = nm;
            }
            //address validation
            if(ad.empty()){
                cout<<"\n[Warning]:***Enter Employee Address! ***"<<endl;
            }else{
                address = ad;
            }
            //auto incrementing the employee Id
            empid++;
        }
        //Concrete function
        void displayEmployeeDetails(){
            cout<<"-----------------------"<<endl;
            cout<<"Employee ID: "<<empid<<endl;
            cout<<"Name: "<<name<<endl;
            cout<<"Address: "<<address<<endl;
        }
        //Pure virtual functions
        virtual double calSal() = 0;
};
int Employee::empid=1000;
class Salaried final override: public Employee {
    protected:
        double basicSal=0.0;
        double HRA=0.0;
        double TA=0.0;
        double DA=0.0;
    public:
        Salaried(const string &nm, const string &ad, double bs)
        :Employee(nm, ad){
            basicSal = bs;
            TA = basicSal * 0.10;
            DA = basicSal * 0.20;
            HRA = basicSal * 0.15;
        }
        //Overriding calSal()
        double calSal() override{
            return basicSal + HRA + TA + TA;
        }
        const void displaySalariedEmp(){
            Employee::displayEmployeeDetails();
            cout<<"Regular Salary: "<<calSal()<<endl;
        }
};
class Contractual final override: public Employee{
    protected:
        double rate = 0.0;
        int hrs_worked=0;
        public:
            Contractual(const string &nm, const string &ad, double rt, int hrs)
            : Employee(nm, ad){
                rate = rt;
                hrs_worked = hrs;
             }
            //overriding calSal()
            double calSal() override{
                return rate * hrs_worked;
            }
            //show contractual
            const void displayContractualDetails(){
                Employee::displayEmployeeDetails();
                cout<<"Contractual Salary is: "<<calSal()<<endl;
            }
};
int main(){
    // base class pointer
    Employee *e;
    //Constructor(Name, Address, Salary)
    Salaried s("Jeff","Indiana",200000.0);
    e = &s;
    e->calSal();
    s.displaySalariedEmp();
    //Constructor(Name, Address, rate, salary)
    Contractual c("Majed","Chicago",7.0,30000.0);
    e = &c;
    e->calSal();
    c.displayContractualDetails();
    return 0;
}