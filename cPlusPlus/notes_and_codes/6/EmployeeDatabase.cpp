/*
Program : File-Based Employee Database using Binary Files

This program demonstrates FILE HANDLING in C++ using inary files. It allows the user to:
1. Add employee records
2. Display all employee records
3. Search employee by ID
4. Update an employee record
5. Delete an employee record

*/

#include <iostream>
#include <fstream>
using namespace std;

/* Employee class */
class Employee
{
public:
    int id;        // Employee ID
    char name[30]; // Employee name (fixed-size)
    float salary;  // Employee salary
};

/* Function to Add Employee */
void addEmployee()
{
    Employee e;
    ofstream fout("employee.dat", ios::binary | ios::app);

    cout << "\nEnter Employee ID: ";
    cin >> e.id;
    cin.ignore();

    cout << "Enter Employee Name: ";
    cin.getline(e.name, 30);

    cout << "Enter Employee Salary: ";
    cin >> e.salary;

    // SERIALIZATION
    fout.write((char *)&e, sizeof(e));
    fout.close();

    cout << "Employee added successfully.\n";
}

/* Function to Display All Employees */
void displayEmployees()
{
    Employee e;
    ifstream fin("employee.dat", ios::binary);

    if (!fin)
    {
        cout << "\nNo records found.\n";
        return;
    }

    cout << "\n----- Employee Records -----\n";
    while (fin.read((char *)&e, sizeof(e)))
    {
        cout << "ID     : " << e.id << endl;
        cout << "Name   : " << e.name << endl;
        cout << "Salary : " << e.salary << endl;
        cout << "----------------------------\n";
    }
    fin.close();
}

/* Function to Search Employee by ID */
void searchEmployee()
{
    Employee e;
    int searchId;
    bool found = false; // Flag to check if employee exists

    ifstream fin("employee.dat", ios::binary);

    if (!fin)
    {
        cout << "\nFile not found.\n";
        return;
    }

    cout << "Enter Employee ID to search: ";
    cin >> searchId;

    while (fin.read((char *)&e, sizeof(e)))
    {
        if (e.id == searchId)
        {
            cout << "\nEmployee Found:\n";
            cout << "ID     : " << e.id << endl;
            cout << "Name   : " << e.name << endl;
            cout << "Salary : " << e.salary << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "Employee not found.\n";

    fin.close();
}

/*
Function to Update Employee Record
Working:
1. Read each record from employee.dat
2. If ID matches - modify the record in memory
3. Write records (updated or unchanged) to temp.dat
4. Replace original file with temp file

Why temp file is needed ? Binary files cannot modify data in the middle , So we rewrite the entire file
*/
void updateEmployee()
{
    Employee e;
    int updateId;
    bool found = false; // Flag to check if employee exists

    // Open original file in READ mode
    ifstream fin("employee.dat", ios::binary);

    // Open temporary file in WRITE mode
    ofstream fout("temp.dat", ios::binary);

    // Check if original file exists
    if (!fin)
    {
        cout << "\nFile not found.\n";
        return;
    }

    cout << "Enter Employee ID to update: ";
    cin >> updateId;

    // Read records one by one from the original file ; Deserialization happens here
    while (fin.read((char *)&e, sizeof(e)))
    {

        // Check if current record matches the ID
        if (e.id == updateId)
        {

            // Take new data from user
            cout << "\nEnter New Name: ";
            cin.ignore(); // Clear input buffer
            cin.getline(e.name, 30);

            cout << "Enter New Salary: ";
            cin >> e.salary;

            found = true; // Mark that record was found
        }

        /*
          Write the record to temp file:
          - Updated record (if ID matched)
          - Original record (if ID did not match)
        */
        fout.write((char *)&e, sizeof(e));
    }

    // Close both files
    fin.close();
    fout.close();

    /*
      Replace old file with updated file:
      - Delete original employee.dat
      - Rename temp.dat to employee.dat
    */
    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    // Final message to user
    if (found)
        cout << "Employee record updated successfully.\n";
    else
        cout << "Employee not found.\n";
}

/* Function to delete employee record */
void deleteEmployee()
{
    Employee e;
    int deleteId;
    bool found = false; // Flag to check if employee exists

    ifstream fin("employee.dat", ios::binary);
    ofstream fout("temp.dat", ios::binary);

    if (!fin)
    {
        cout << "\nFile not found.\n";
        return;
    }

    cout << "Enter Employee ID to delete: ";
    cin >> deleteId;

    while (fin.read((char *)&e, sizeof(e)))
    {
        if (e.id == deleteId)
        {
            found = true;
            continue; // Skip writing this record
        }
        fout.write((char *)&e, sizeof(e));
    }

    fin.close();
    fout.close();

    remove("employee.dat");
    rename("temp.dat", "employee.dat");

    if (found)
        cout << "Employee record deleted successfully.\n";
    else
        cout << "Employee not found.\n";
}

/* Main menu */
int main()
{
    int choice;

    do
    {
        cout << "\n===== Employee Database Menu =====";
        cout << "\n1. Add Employee";
        cout << "\n2. Display Employees";
        cout << "\n3. Search Employee by ID";
        cout << "\n4. Update Employee";
        cout << "\n5. Delete Employee";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            addEmployee();
            break;
        case 2:
            displayEmployees();
            break;
        case 3:
            searchEmployee();
            break;
        case 4:
            updateEmployee();
            break;
        case 5:
            deleteEmployee();
            break;
        case 6:
            cout << "Exiting program...\n";
            break;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    } while (choice != 6);

    return 0;
}