/*
Problem Statement
Design a Student class to store student details and marks in three subjects.
The program should calculate total marks, assign grades, and maintain shared information such as
the total number of students and the student with the highest total marks.
Requirements
1. Create a Student class with private data members:
o Student name
o Roll number
o Class/Section
o Marks in three subjects (individual variables)
2. Implement:
o A constructor to initialize student details and marks
o A member function to calculate total marks
o A member function to calculate grade based on total marks
o A member function to update marks (Note: While updating student marks, the
updated marks for all three subjects must be provided at the same time.
This ensures that the total marks and grade are recalculated correctly)
o A member function to display student details, total marks, and grade
3. Use static data members to:
o Store the total number of students
o Store the highest total marks
o Store the name of the student with the highest marks
4. Use static member functions to:
o Display total number of students
o Display the highest scorer details (name and marks)
5. Demonstrate the program by creating multiple student (at least 3) objects and performing
updates.
*/
#include<iostream>
using namespace std;
class Student{
    private:
        char grade;
        int roll_no;
        string name, section;
        double PIC,m8051,coding, tot_marks;
        //static data members
        static int total_no_students;
        static double highest_total_marks;
        static string std_name_high_marks;
    public:
        Student(string _name, string _section, double _PIC, double _m8051, double _coding):
        //data member (constructor parameter)
        name(_name),
        section(_section),
        PIC(_PIC),
        m8051(_m8051),
        coding(_coding)
        { 
            //increment the student count
            total_no_students++;
            //To generate a roll number
            roll_no = 100 + total_no_students;
        }
        //member functions
        double total_marks();
        char calculate_grade();
        // double update_marks();
        void indi_records();
        static void high_score_display(){
            cout<<"\n-------Student Record-------"<<endl;
            cout<<"Total number of students: "<<total_no_students<<endl;
            cout<<"Highest scorer details: ";
            cout<<"Name     : "<<std_name_high_marks<<endl;
            cout<<"                        Marks    : "<<highest_total_marks<<endl;
        }
        
};
double Student::total_marks(){
    tot_marks = PIC + m8051 + coding;
    // if the current total is higher than the previous
    if(tot_marks>highest_total_marks){
        highest_total_marks = tot_marks;
        std_name_high_marks = name;
    }
    return tot_marks;
}
char Student::calculate_grade(){
    
    if(tot_marks>180){  //>60%
        return grade ='A';
    }
    else if(tot_marks<180 && tot_marks>120){ // >60 <40
        return grade = 'B';
    }
    else{
        return grade = 'C';
    }
}
// double Student::update_marks(){

// }
void Student::indi_records(){
    cout<<"------- Student "<<total_no_students<<" -------"<<endl;
    cout<<"Roll No      : "<<roll_no<<endl;
    cout<<"Name         : "<<name<<endl;
    cout<<"total Marks  : "<<tot_marks<<endl;
}
//initializing static variables
int Student::total_no_students=0;
double Student::highest_total_marks=0;
string Student::std_name_high_marks=" ";

int main(void){
    Student s1("Prasad","SepOffline",78.5,82.0,90.0); //250.5
    s1.total_marks();
    s1.calculate_grade();
    s1.indi_records();
    Student s2("Jeff","SepOffline",72.5,52.0,60.0); //184.5
    s2.total_marks();
    s2.calculate_grade();
    s2.indi_records();
    Student s3("Majed","SepOffline",54.5,82.0,40.0); //176.5
    s3.total_marks();
    s3.calculate_grade();
    s3.indi_records();
    // Student s4("Geethika","SepOffline",89.5,91.0,94.0); //274.5
    // s4.total_marks();
    // s4.calculate_grade();

    s1.high_score_display();
    return 0;
}