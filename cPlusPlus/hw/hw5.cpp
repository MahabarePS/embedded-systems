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
        int roll_number;
        string name;
        string section;
        double sub_PIC;
        double sub_8051;
        double sub_coding;
    public:
        Student(string name, string section, double _PIC, double _8051, double _coding){
            string name = name;
            string section = section;
        }
        double total_marks();
        char calculate();
};