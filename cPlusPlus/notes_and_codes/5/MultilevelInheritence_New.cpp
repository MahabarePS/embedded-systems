/*
Program :
1. Demonstrate Multilevel Inheritance in C++ (Inheritance chain: A → B → C)
   Person → Student → EngineeringStudent

2. Show object initialization using setter methods instead of constructors.
   (Using setter, object is first created, and then data is assigned later)

NEWLY ADDED :

3. Demonstrate validation logic inside setter methods.

4. Demonstrate a computed member function (isFinalYear()) that represents
   behavior, not just data.

In this code , we are using setter methods to intialise the objects (instead of Constructors)
There are multiple ways  to doing this :
 1. Have independant setter methods in each calss , invoke all three setter methods in main ,
    using 'EngineeringStudent' object

 2. setter method of final derived class (EngineeringStudent) , internally calls setter methods
    of parent(Student) and grandparent (Person)
    EngineeringStudent object invokes only its own setter method in main()

 3. Chained setters - EngineeringStudent setter calls Student setter ,
    Student setter calls Person setter
    EngineeringStudent object invokes only its own setter method in main()
    Each class handles only its own data, and passes the rest up the chain.
    This is a clean, extensible, and modular design.
*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
protected:
    string name = "";
    int age = 0; // in-class initialization (modern C++)

public:
    // Setter with validation
    bool setDetails(const string &n, int a)
    {
        if (n.empty() || a <= 0)
            return false;

        name = n;
        age = a;
        return true;
    }

    // Display Person data
    void display() const
    {
        cout << "Name: " << name << "\nAge: " << age << endl;
    }
};

// Intermediate class
class Student : public Person
{
protected:
    int rollNumber = 0;
    string college = "";

public:
    // Chained setter with validation
    bool setDetails(const string &n, int a, int roll, const string &col)
    {
        if (!Person::setDetails(n, a))
            return false;

        if (roll <= 0 || col.empty())
            return false;

        rollNumber = roll;
        college = col;
        return true;
    }

    // Display Student data
    void display() const
    {
        Person::display();
        cout << "Roll Number: " << rollNumber
             << "\nCollege: " << college << endl;
    }
};

// Most derived class
class EngineeringStudent : public Student
{
private:
    string branch = "";
    int year = 0;

public:
    // Chained setter with validation

    bool setDetails(const string &n, int a, int roll,
                    const string &col, const string &b, int y)
    {
        if (!Student::setDetails(n, a, roll, col))
            return false;

        if (b.empty() || y < 1 || y > 4)
            return false;

        branch = b;
        year = y;
        return true;
    }

    // Computed method (behavior)
    bool isFinalYear() const
    {
        return year == 4;
    }

    // Display complete Engineering Student data
    void display() const
    {
        Student::display();
        cout << "Branch: " << branch
             << "\nYear: " << year << endl;

        cout << "Final Year Status: " << (isFinalYear() ? "Yes" : "No") << endl;
    }
};

int main()
{
    EngineeringStudent engStu;

    string name, college, branch;
    int age, roll, year;

    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter roll number: ";
    cin >> roll;

    cin.ignore(); // clear newline before getline

    cout << "Enter college: ";
    getline(cin, college);

    cout << "Enter branch: ";
    getline(cin, branch);

    cout << "Enter year: ";
    cin >> year;

    // Single call sets and validates everything
    if (!engStu.setDetails(name, age, roll, college, branch, year))
    {
        cout << "\nInvalid data entered. Please check your inputs.\n";
        return 0;
    }

    cout << "\n--- Student Details ---\n";
    engStu.display();

    return 0;
}
