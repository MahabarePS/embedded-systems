// Constructors and Destructor

// Constructor - A constructor is a special member function of a class that is automatically
// called when an object of that class is created.
// - It has the same name as the class.
// - It does not have a return type (not even void).
// - It’s used to initialize objects when they are created.
// - You can define multiple constructors using constructor overloading.
// 		- Default Contructor
//      - Parameterised Contructor
//      - Copy Contructor .. using reference object

// Destructor  -  A destructor is a special member function that is called automatically
// when an object goes out of scope (i.e., is destroyed). Used to release resources (memory , file etc.)

#include <iostream>
#include <string.h>

using namespace std;

class Employee
{
private:
	int empid;
	char empname[20];
	float empsal;

public:
	// Default Constructor
	Employee()
	{
		cout << "Default Constructor Called , Emplyee getting Created" << endl;
		empid = 0;
		strcpy(empname, "");
		empsal = 0.0;
	}

	// Parameterised Constructor
	Employee(int id, const char *name, float sal)
	{
		cout << "Parameterised Constructor Called , Emplyee getting Created" << endl;
		empid = id;
		strcpy(empname, name);
		empsal = sal;
	}

	// Copy Constructor
	Employee(Employee &e)
	{
		cout << "Copy Constructor Called , Emplyee getting Created" << endl;
		empid = e.empid;
		strcpy(empname, e.empname);
		empsal = e.empsal;
	}

	~Employee()
	{
		cout << "\nEmployee Destructor Called";
	}

	void printdata()
	{
		cout << "The EmpId is " << empid << endl;
		cout << "The EmpName is " << empname << endl;
		cout << "The EmpSal is " << empsal << endl;
	}
};

int main()
{

	Employee emp; // Default Constructor Called
	emp.printdata();

		Employee emp1(100, "Dilshad", 1000.65); // Parameterised Constructor Called
	emp1.printdata();

	/*
	Employee emp3(emp1); // Copy Constructor Called , copies values of emp1
	emp3.printdata(); */

	return 0;
}
