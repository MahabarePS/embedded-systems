#include<iostream>
using namespace std;
class Employee{
    protected:
        static int id;
        string name;
        double basicSal;
    public:
        Employee(): name(""), basicSal(0.0){}

        Employee(const string &nm, const double &bs)
        : name(nm), basicSal(bs){}

        void Disp() const{
            cout<<"----------------------------------"<<endl;
            cout <<"ID          : "<<id<<endl;
            cout <<"Name        : "<<name<<endl;
            cout <<"Basic Salary: "<<basicSal<<endl;
        }
};
int Employee::id=0;
class Date{
    protected:
        int dd, mm, yyyy;
        bool IsValid() const{
            return (dd>=1 && dd<=31 &&
                    mm>=1 && mm<=12 &&
                    yyyy>1990);}
    public: 
                //default
                Date():dd(0),mm(0),yyyy(0) {}
                // para
                Date(int d, int m, int y)
                : dd(d), mm(m), yyyy(y){}
                
                void Disp() const{
                    cout<<"Date: "<<dd<<"/"<<mm<<"/"<<yyyy<<endl;
                }
};
class Admin: public Employee, public Date{
    double incentive;
    private:
        double calSal() const{
            return basicSal + incentive;
        }
    public:
        Admin(): incentive(0){ }

        Admin(const string &nm, const double b, int d, int m, int y, double inc)
        :   Employee(nm, b),
            Date(d,m,y),
            incentive(inc) {
                id++;
            }

        void Disp() const{
            Employee::Disp();
                if(IsValid()){
                        Date::Disp();
                }else{
                    cout<<"Date        : Invalid Date"<<endl;
                }
                cout<<"Incentive   : "<< incentive<<endl;
                cout<<"Total Salary: "<<calSal()<<endl;
        }
};

int main(void){
    Admin a1("Jeff",10000,2,13,1800,2090);
    a1.Disp();
    Admin a2("Majed",20000,2,13,100,2090);
    a2.Disp();
    return 0;
}