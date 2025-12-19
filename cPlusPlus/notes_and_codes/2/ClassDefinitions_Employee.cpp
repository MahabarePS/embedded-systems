#include <iostream>
using namespace std;

#define size 4

class Employee
{
public:
	int empid;
	float empsal;

public:
	void getdata()
	{
		cout << "Enter EmpId : ";
		cin >> empid;
		cout << "Enter EmpSal : ";
		cin >> empsal;
	}

	void printdata()
	{
		cout << "The EmpId is : " << empid << endl;
		cout << "The EmpSal is: " << empsal << endl;
	}
};

int main()
{

	Employee e;
	// Employee emp[size];

	cout << "For Single Object" << endl;
	e.getdata();
	e.printdata();
	e.empid = 4;

	/*

	cout << "For Array of Objects" << endl;
	for (int i = 0; i < size; i++)
		emp[i].getdata();
	for (int i = 0; i < size; i++)
		emp[i].printdata(); */

	return 0;
}
