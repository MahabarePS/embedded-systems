/*
Program :
- Demonstrate Multiple Inheritance in C++
- One Derived Class (Admin) inherits from Multiple Base Classes (Employee and Date classes)
*/

#include <iostream>
#include <string>
using namespace std;

/*
Base Class 1 : Employee
- Stores employee-related details
- Provides base salary handling
*/
class Employee
{
protected:
	int id;
	string name;
	double basicSal;

public:
	// Default constructor
	Employee() : id(0), name(""), basicSal(0) {}

	// Parameterized constructor
	// Another important thing to remember : good coding
	// - int, char, double: 	Pass by value since small memory (4bytes) , no need for const since its by value
	// (copy is made), Cheap, simple
	// - string, vector, map	:	const &	, will avoid copy

	Employee(int id, const string &nm, double bs)
		: id(id), name(nm), basicSal(bs) {}

	// Display employee details
	void Disp() const
	{
		cout << "ID : " << id << endl;
		cout << "Name : " << name << endl;
		cout << "Basic Salary : " << basicSal << endl;
	}
};

/*
Base Class 2 : Date
- Stores date information
*/
class Date
{
protected:
	int dd, mm, yy;

	bool IsValid() const
	{
		return (dd >= 1 && dd <= 31 &&
				mm >= 1 && mm <= 12 &&
				yy > 1900);
	}

public:
	// Default constructor
	Date() : dd(0), mm(0), yy(0) {}

	// Parameterized constructor
	Date(int d, int m, int y)
		: dd(d), mm(m), yy(y) {}

	// Display date
	void Disp() const
	{
		cout << "Date : " << dd << "/" << mm << "/" << yy << endl;
	}
};

/*
Derived Class : Admin
- Inherits from Employee and Date
- Adds incentive-based salary calculation
*/
class Admin : public Employee, public Date
{
	double incentive;

private:
	// Salary calculation (hidden logic)
	double CalSal() const
	{
		return basicSal + incentive;
	}

public:
	// Default constructor
	Admin() : incentive(0) {}

	// Parameterized constructor
	// Calls both base class constructors explicitly
	Admin(int i, const string &nm, double b, int d, int m, int y, double inc)
		: Employee(i, nm, b),
		  Date(d, m, y),
		  incentive(inc) {}

	// Display complete admin details including salary
	void Disp() const
	{
		Employee::Disp(); // Employee information

		if (IsValid())
			Date::Disp();
		else
			cout << "Date : Invalid Date" << endl;

		cout << "Incentive : " << incentive << endl;
		cout << "Total Salary : " << CalSal() << endl;
	}
};

int main()
{
	Admin a1(1, "XYZ", 10000, 2, 13, 2010, 2090);
	a1.Disp();

	return 0;
}
