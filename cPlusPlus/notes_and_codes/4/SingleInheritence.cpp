/*
Program :
- Demonstrate Single Inheritance in C++
- One Derived class (Employee) inherits from one Base class (Person)
- Demonstrate updating base class data using a derived class object

Note :
- We are now going to use a more modern way of writing constructors using an initialisation list.
(insted of initialising daya members in the body of the constructor)

Person() : name(""), address("") {}
This means :
- initalise name and address to blanks
- data members are created and directly initialised values
- then constructor body is executed , where u may do some computations etc
*/

#include <iostream>
#include <string> // For std::string
using namespace std;

/*

Base Class : Person
- Stores common details like name and address
- Provides constructors and a display function
*/
class Person
{
protected:
    string name;    // Person's name
    string address; // Person's address

public:
    // Default constructor
    // This is now the modern way of writing a constructor using initialisation list
    // name and addressed initialsed to blank
    Person() : name(""), address("") {}

    // Parameterized constructor
    // const string& :
    //  - const  : value cannot be modified inside this function
    //  - &      : passed by reference (no copy, better performance)
    Person(const string &nm, const string &add)
        : name(nm), address(add) {}

    // Update address of the person
    void UpdateAddress(const string &newAddress)
    {
        address = newAddress;
    }

    // Making a base class display function protected improves encapsulation by allowing only derived classes
    // to access and control how base class data is displayed.
    // This is better OPPS design

    // Make this method 'public' only if u want to treat Person (base class) as a standalone class, and
    // allow an object of this class to be created in main().
protected:
    // Display function for Person details
    void Disp() const
    {
        cout << "Name : " << name << endl;
        cout << "Address : " << address << endl;
    }
};

/*

Derived Class : Employee
- Inherits from Person
- Adds employee-specific data like id and salary details
*/
class Employee : public Person
{
    int id;
    double basicSal, hra, ta, da;

public:
    // Default constructor
    Employee()
        : id(0), basicSal(0), hra(0), ta(0), da(0) {}

    // Parameterized constructor
    // - Base class constructor is called and nm and add are passed to it
    // - other data members are initialised using initialization list
    // - computations done in the body of the constructor
    Employee(int id, const string &nm, const string &add, double bs)
        : Person(nm, add), id(id), basicSal(bs)
    {
        // Salary component calculations
        ta = basicSal * 0.10;
        da = basicSal * 0.20;
        hra = basicSal * 0.15;
    }

    // Display function for Employee details
    // the const here means : This member function is NOT allowed to modify the object’s data members.
    void Disp() const
    {
        cout << "Employee Id : " << id << endl;
        Person::Disp(); // Call base class function

        cout << "Salary Details : " << endl;
        cout << "Basic Salary : " << basicSal << endl;
        cout << "HRA : " << hra << endl;
        cout << "TA  : " << ta << endl;
        cout << "DA  : " << da << endl;

        // call the private method calSal() , to calculate total salary
        cout << "Total Salary : " << calSal() << endl;
    }

private:
    // Calculate total salary
    // Salary calculation is an internal responsibility ; Outside code cannot interfere
    // Hide internal logic and expose only what the user needs (Better Encapsulation and Abstarction)
    double calSal() const
    {
        return basicSal + hra + ta + da;
    }
};

int main()
{
    Employee e1(101, "ABC", "Pune", 10000);
    e1.Disp();

    // Calling base-class method using derived-class object
    e1.UpdateAddress("Mumbai");

    cout << "\n--- After Address Update ---" << endl;
    e1.Disp();

    return 0;
}
