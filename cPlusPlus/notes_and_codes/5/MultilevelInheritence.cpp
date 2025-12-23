/*
Program :
1. Demonstrate Multilevel Inheritance in C++ (Inheritance chain: A → B → C)
   Person → Student → EngineeringStudent

2. Show object initialization using setter methods instead of constructors.
(Using setter , object is first created, and then data is assigned later)

In this code , we are using setter methods to intialise the objects (instead of Constructors)
There are multiple ways  to doing this :
 1. Have independant  setter methods in each calss , invoke all theree setter methods in main ,
    using 'EngineeringStudent' object

2. setter method of final derived class (EngineeringStudent) , internally calls setter methods of parent(Student)
   and grandparent (Person)
   EngineeringStudent object invokes only its own setter method in main()

3. Chained setters - EngineeringStudent setter calls Student setter , Student setter calls Person setter
   EngineeringStudent object invokes only its own setter method in main()
   Each class handles only its own data, and passes the rest up the chain.
   This is a clean, extensible, and modular design.

Another New Concept : Inclass Initialisation :
Earlier we used default constructors to initialize members.
In modern C++, we can initialize data members directly where they are declared, so explicit default constructors
are often unnecessary — but we can still write = default to make our intent clear.

= default : "Please generate the compiler’s default constructor for me." - to create the object

Please Note : the compiler generated constructor DOES NOT ALWAYS initialise values. Primitive datatypes are not initialised
Hence inclass initialisation is required.

Member type	    What defaulted (compiler generated) constructor does
int, double	    Garbage
string, vector	Properly initialized

*/

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
protected:
    // In-class initialization (modern C++)
    // Ensures safe default values even before setters are called
    // u do not really need a default constructor , the compiler generated constructor is sufficiant to crate the object
    string name = "";
    int age = 0;

public:
    // Default constructor explicitly requested (Compiler-generated constructor)
    // u really do not require to write this this .. just teaching you wat it means
    // Even if u dont write it , compiler will generate a constructor to create the object
    Person() = default;

public:
    // Setter for Person data
    void setDetails(const string &n, int a)
    {
        name = n;
        age = a;
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
    // In-class initialization
    int rollNumber = 0;
    string college = "";

public:
    // Default constructor explicitly requested
    Student() = default;

    // Chained: calls Person's setter
    void setDetails(const string &n, int a, int roll, const string &col)
    {
        Person::setDetails(n, a); // delegate to Person
        rollNumber = roll;
        college = col;
    }

    // Display Student data
    void display() const
    {
        Person::display(); // delegate to Person
        cout << "Roll Number: " << rollNumber << "\nCollege: " << college << endl;
    }
};

// Most derived class
class EngineeringStudent : public Student
{
private:
    // In-class initialization
    string branch = "";
    int year = 0;

public:
    // Default constructor explicitly requested
    EngineeringStudent() = default;

    // Chained: calls Student's setter
    void setDetails(const string &n, int a, int roll, const string &col, const string &b, int y)
    {
        Student::setDetails(n, a, roll, col); // delegate to Student
        branch = b;
        year = y;
    }

    // Display complete Engineering Student data
    void display() const
    {
        Student::display(); // delegate to Student
        cout << "Branch: " << branch << "\nYear: " << year << endl;
    }
};

int main()
{
    EngineeringStudent engStu;

    string name, college, branch;
    int age, roll, year;

    // Get the data from the User

    // IMP :
    // cin >> name , will only take read upto the first whitespace character
    // getline(cin,name) , will accept whitespaces also
    cout << "Enter name: ";
    getline(cin, name);

    cout << "Enter age: ";
    cin >> age;

    cout << "Enter roll number: ";
    cin >> roll;

    // important before getline
    // cin >> age;         // user types: 21⏎
    // getline(cin, name); // reads until it sees a newline , immediately sees \n , so assumes name = ""
    // cin.ignore(); // discards one char from the input buffer (the '\n' char) , so buffer is now clean
    cin.ignore();

    cout << "Enter college: ";
    getline(cin, college);

    // No need to put a cin.ignore() here , because getline(cin, college) has already consumed the '\n'
    // and input buffer is empty
    // cin.ignore() is needed only when switching from cin >> to getline() ; not needed between two getline() calls

    cout << "Enter branch: ";
    getline(cin, branch);

    cout << "Enter year: ";
    cin >> year;

    engStu.setDetails(name, age, roll, college, branch, year);
    engStu.display();
}
