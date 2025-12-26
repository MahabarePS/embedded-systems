#include<iostream>
#include<string>
using namespace std;
class Person{
    protected:
        string name="";
        int age =0;
    public:
        Person(const string &n, int a){
            if(n.empty()){
                name = "Unkown";
                cout<<"[Warning] Name cannot be empty. Setting default.";
            }else{
                name =n;
            }
            if(a<0){
                age = 0;
                cout<<"[Warning] Invalid age. Setting default.";
            }else{
                age = a;
            }
        }
        void displayPersonInfo() const{
            cout<< "\nName: "<<name<<"\nAge: "<<age<<endl;
        }
};  
//Derived class 1
class Student: public Person{
    private:
        int roll_number =0;
        string course = "";
    public:
        Student(const string &n, int a, int r, const string &c): Person (n,a){
            if(c.empty()){
                course = "Unkown";
                cout<<"\n[Warning] Course cannot be empty. Setting default.";
            }else{
                course =c;
            }
            if(r<=0){
                roll_number = 0;
                cout<<"\n[Warning] Invalid roll number. Setting default.";
            }else{
                roll_number = r;
            }
        }
        void displayStudentInfo() const{
            Person::displayPersonInfo();
            cout<<"Course: "<<course<<"\nRoll Number: "<<roll_number<<endl;
        }
};
//Derived class 2
class Teacher: public Person{
    private:
        int empID=0;
        string subject="";
    public:
        Teacher(const string &n, int a, int id, const string &sub):Person(n,a){
            if(sub.empty()){
                subject = "Unkown";
                cout<<"\n[Warning] Course cannot be empty. Setting default."<<endl;
            }else{
                subject =sub;
            }
            if(id<=0){
                empID = 0;
                cout<<"\n[Warning] Invalid roll number. Setting default."<<endl;
            }else{
                empID = id;
            }
        }
        bool isSeniorTeacher() const{
            return age >=40;
        }
        void displayTeacherInfo() const{
            Person::displayPersonInfo();
            cout<<"EmpID: "<<empID
                <<"\nSubject: "<<subject<<endl;

            cout<<"Senior Teacher Status: "
                <<(isSeniorTeacher()?"Yes":"No")<<endl;
        }
};
int main(){
    cout<<"---------Student Info--------";
    Student s1("Prasad",21,1001,"CS");
    s1.displayStudentInfo();

    //invalid
    cout<<"---------Student Info--------";
    Student s2("Majed",21,0,"CS");
    s2.displayStudentInfo();

    cout<<"---------Teacher Info--------\n";
    Teacher t1("Dilshad",45,1323,"C++");
    t1.displayTeacherInfo();

    //invalid
    cout<<"---------Teacher Info--------\n";
    Teacher t2("",45,1323,"C++");
    t2.displayTeacherInfo();
    
    return 0;
}