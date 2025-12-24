/*
Hybrid Inheritance – University Structure
Problem Statement
A university system maintains information about people associated with the institution.
A person can be a student, a staff member, or an intern.
An Intern is both:
 A Student (has a roll number)
 A Staff member (has an employee ID)
This creates a diamond inheritance structure, which must be handled carefully to avoid duplicate
base class objects.
Inheritance Structure
Person
/ \
Student Staff
\ /
Intern
Class Design Requirements
Base Class: Person
Data Members:
 name
 email
Responsibilities:
 Store common personal details
 Provide a function to display personal information

Derived Class: Student
Inheritance Type:
 Virtually inherit from Person
Data Members:
 rollNumber
Responsibilities:
 Initialize student-specific data

 Display student details
Derived Class: Staff
Inheritance Type:
 Virtually inherit from Person
Data Members:
 employeeId
Responsibilities:
 Initialize staff-specific data
 Display staff details

Derived Class: Intern
Inheritance Type:
 Inherit from both Student and Staff
Data Members:
 assignedProject
Responsibilities:
 Initialize all inherited data members
 Display complete intern details
 Access Person, Student, and Staff members without ambiguity

Constructor Requirements
 Each class must have a parameterized constructor
 The Intern constructor must:
o Initialize Person, Student, and Staff
o Demonstrate correct constructor initialization order
 Avoid duplicate initialization of Person

Main Function Requirements
In main():
1. Create an Intern object with:
o Name

o Email
o Roll number
o Employee ID
o Assigned project
2. Call a function to display:
o Personal details
o Student details
o Staff details
o Intern project details
3. Ensure there is:
o No ambiguity
o No compiler errors
o Clear, correct output

Expected Output (Sample)
Name: Ananya Sharma
Email: ananya@university.edu
Roll Number: ST202
Employee ID: EMP451
Assigned Project: AI Research System
*/
#include<iostream>
#include<string>
using namespace std;
class Person{
    protected:
        string name;
        string email;
    public:
        //store common person details
        Person(const string &nm, const string &eml){
            //validation for name
            if(nm.empty()){
                name="             Unknown";
                cout<<"\n[Warning] Name cannot be empty! Setting default.";
            }else{
                name = nm;
            }
            //validation for email
            if(eml.empty()){
                email="Unknown";
                cout<<"[Warning] email cannot be empty. Setting default.";
            }
            else{
                email = eml;
            }
        }
        //function to display personal details
        void showPersonDetails(){
            cout<<"name             : "<<name<<endl;
            cout<<"email            : "<<email<<endl;
        }
};
//Virtually inherit from Person
class Student: virtual public Person{
    protected:
        string roll_number;
    public:
        //Initialize student-specific data
        Student(const string &r, const string &nm, const string &eml):Person(nm,eml){
            if(r.empty()){
                roll_number="Unknown";
                cout<<"[Warning] Invalid Roll number! Setting default.";
            }else{
                roll_number=r;
            }
        }
        //Display student details
        void showStudentDetails(){
            cout<<"Roll Number      : "<<roll_number<<endl;
        }
};
//Virtually inherit from Person
class Staff: virtual public Person{
    protected:
        string employeeId;
    public:
    //Initialize staff-specific data
    Staff(const string &emp, const string &nm, const string &eml):Person(nm, eml){
        if(emp.empty()){
            employeeId="Unknown";
            cout<<"[Warning] Invalid EmployeeId! Setting default.";
        }else{
            employeeId=emp;
        }
    }
    //Display staff details
    void showEmployeeDetails(){
        cout<<"Employee Id      : "<<employeeId<<endl;
    }
};
class Intern: public Student, public Staff{
    protected:
        string assignedProject;
    public:
    //Initialize all inherited data members
    Intern (const string &nm, const string &eml,const string &emp , const string &r, const string &ap)
    : Person(nm, eml),
      Student(r, nm, eml),
      Staff(emp, nm, eml)
      {
        if(ap.empty()){
            assignedProject="Unknown";
            cout<<"[Warning] Assigned Project cannot be empty. Setting default.";
        }else{
            assignedProject=ap;
        }

      }
    //Display complete intern details
    const void showInternDetails(){
        cout<<"Assigned Project : "<<assignedProject<<endl;
    }
};
int main(){
    //Create an Intern object with:
    Intern i("Ananya Sharma","ananya@university.edu", "ST202", "EMP451", "AI Research System");
    //Access Person, Student, and Staff members without ambiguity
    i.showPersonDetails();
    i.showStudentDetails();
    i.showEmployeeDetails();
    i.showInternDetails();
    return 0;
}