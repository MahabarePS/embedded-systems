/*
hw3: Create a student class with default and paramterrized constructor.
     create a print and calculate  result method.
*/
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int rollNo;
    int m1, m2, m3;
    // Calculate result
    void calculateResult() {
        int total = m1 + m2 + m3;
        float percentage = total / 3.0;

        cout << "Total      : " << total << endl;
        cout << "Percentage : " << percentage << "%" << endl;

        if (percentage >= 40)
            cout << "Result     : PASS" << endl;
        else
            cout << "Result     : FAIL" << endl;
    }

public:
    // Default constructor
    Student() {
        name = " ";
        rollNo = 0;
        m1 = m2 = m3 = 0;
    }

    // Parameterized constructor
    Student(string n, int r, int a, int b, int c) {
        name = n;
        rollNo = r;
        m1 = a;
        m2 = b;
        m3 = c;
    }

    // Print student details
    void print() {
        cout << "Name       : " << name << endl;
        cout << "Roll No    : " << rollNo << endl;
        cout << "Marks      : " << m1 << ", " << m2 << ", " << m3 << endl;
        calculateResult();
    }

    
};

int main() {
    // Using default constructor
    cout<<"------------Student Records-------------"<<endl;
    Student s1;
    s1.print();

    cout << endl;

    // Using parameterized constructor
    Student s2("Prasad", 101, 75, 68, 80);
    s2.print();

    return 0;
}
