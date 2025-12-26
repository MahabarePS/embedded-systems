#include<iostream>
#include<string>
using namespace std;

class Person{
    protected:
        string name=" ";
        int age=0;
    public:
        bool setDetails(const string &n, int a){
            if(n.empty() || a<=0){
                return false;
            }else{
                name = n;
                age = a;
            return true;
            }
        }
        void Display() const{
            cout<<"Name: "<<name<<"\nAge"<<age<<endl;
        }
};
class Student: public Person{
    protected:
        int roll_number = 0;
        string college = "";
    public:
        bool setDetails(const string &n, int a, int roll, const string &col){
            if(!Person::setDetails(n,a)){
                return false;
            }
            else if(roll<=0 || col.empty()){
                return true;
            }else{
                roll_number = roll;
                college = col;
                return true;
            }
        }

        void Display() const{
            Person::Display();
            cout<<"Roll Number: "<<roll_number<<endl;
            cout<<"College: "<<college<<endl;
        }
};
class EngineeringStudent : public Student{
    private:
        string branch="";
        int year=0;        
    public:
        bool setDetails(const string &n, int a, int roll,
                        const string &col, const string &b, int y){
                            if(!Student::setDetails(n,a,roll,col)){
                                return false;
                            }
                            else if(b.empty() || y<1 || y>4){
                                return false;
                            }else{
                                branch = b;
                                year = y;
                                return true;
                            }
                        }
            bool isFinalYear() const{
                return year==4;
            }
        void Display() const{
            Student::Display();
            cout<<"Branch: "<<branch<<endl;
            cout<<"Year: "<<year<<endl;
            cout<<"Final Year Status: "<<(isFinalYear()?"Yes":"no")<<endl;
        }
};
int main(){
    EngineeringStudent engStu;
    string name,branch, college;
    int age, roll, year;

    cout<<"Enter name           : ";
    getline(cin,name);

    cout<<"Enter age            : ";
    cin>>age;

    cout<<"Enter Roll Number    : ";
    cin>>roll;

    cin.ignore();

    cout<<"Enter College        : ";
    getline(cin,college);

    cout<<"Enter branch         : ";
    getline(cin,branch);

    cout<<"Enter year           : ";
    cin>>year;

    if(!engStu.setDetails(name,age,roll,college,branch, year)){
        cout<<"Invalid data entered. Please check your inputs"<<endl;
        return 0;
    }

    return 0;
}