/*
Program :
1. Demonstrate Hierarchical Inheritance in C++
   (Multiple derived classes inherit from one base class)

   Base Class     : Person
   Derived Classes: Student, Teacher

2. Demonstrate object initialization using parameterized constructors.

3. Demonstrate validation logic inside constructors. Note : Constructors cannot return bool (like we did with setters)
So valudation logic will be added , and error messages will be displayed , and some default value will be set for
invalid data - all in the constructor itself

4. Show how common data is initialized in the base class
   and specialized data is handled by derived classes.
*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
protected:
    string name = "";
    int age = 0; // in-class initialization

public:
    // Parameterized constructor with validation
    Person(const string &n, int a)
    {
        if (n.empty())
        {
            name = "Unknown";
            cout << "[Warning] Name cannot be empty. Setting default.\n";
        }
        else
        {
            name = n;
        }

        if (a <= 0)
        {
            age = 0;
            cout << "[Warning] Invalid age. Setting age to 0.\n";
        }
        else
        {
            age = a;
        }
    }

    void displayPersonInfo() const
    {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Derived class 1
class Student : public Person
{
private:
    int rollNumber = 0;
    string course = "";

public:
    // Parameterized constructor with validation
    Student(const string &n, int a, int roll, const string &c) : Person(n, a)
    {
        if (roll <= 0)
        {
            rollNumber = 0;
            cout << "[Warning] Invalid roll number. Setting to 0.\n";
        }
        else
            rollNumber = roll;

        if (c.empty())
        {
            course = "Not Assigned";
            cout << "[Warning] Course cannot be empty. Setting default.\n";
        }
        else
            course = c;
    }

    void displayStudentInfo() const
    {
        displayPersonInfo();
        cout << "Roll Number: " << rollNumber
             << "\nCourse: " << course << endl;
    }
};

// Derived class 2
class Teacher : public Person
{
private:
    int empID = 0;
    string subject = "";

public:
    // Parameterized constructor with validation
    Teacher(const string &n, int a, int id, const string &subj) : Person(n, a)
    {
        if (id <= 0)
        {
            empID = 0;
            cout << "[Warning] Invalid Employee ID. Setting to 0.\n";
        }
        else
            empID = id;

        if (subj.empty())
        {
            subject = "Not Assigned";
            cout << "[Warning] Subject cannot be empty. Setting default.\n";
        }
        else
            subject = subj;
    }

    // Computed behavior
    bool isSeniorTeacher() const
    {
        return age >= 40;
    }

    void displayTeacherInfo() const
    {
        displayPersonInfo();
        cout << "Employee ID: " << empID
             << "\nSubject: " << subject << endl;

        cout << "Senior Teacher Status: "
             << (isSeniorTeacher() ? "Yes" : "No") << endl;
    }
};

int main()
{

    cout << "\n---- Student Info ----\n";
    Student s("Dilshad", 21, 1001, "Computer Science");
    s.displayStudentInfo();

    cout << "\n---- Teacher Info ----\n";
    Teacher t("Mrs. Iyer", 45, 1001, "Mathematics");
    t.displayTeacherInfo();

    cout << "\n---- Student Info ----\n";
    Student s1("", -1, 1001, "Computer Science"); // invalid data
    s1.displayStudentInfo();

    return 0;
}
