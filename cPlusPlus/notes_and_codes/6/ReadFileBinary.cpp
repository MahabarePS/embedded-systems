#include <iostream>
#include <fstream>
using namespace std;

class Student
{
public:
    int roll;
    char name[20];
    float marks;
};

int main()
{
    // create object s , memory allocated but all members have garbage value
    Student s;

    ifstream fin("student.dat", ios::binary);

    // File stream is in fail state - File Does Not Exist
    if (!fin)
    {
        cout << "Error: File does not exist!\n";
        return 0;
    }

    // Syntax : read(address, number_of_bytes);
    //  - Read bytes from file and copy them into memory starting at address
    // (char*)&s
    //  - &s - address of object s in memory
    //  - (char*) - treat this memory as raw bytes
    // VIMP :
    // - Binary file handling using read() and write() works only for objects containing fixed-size data members
    // - So data member CANNOT be String (since this is not fixed size  dynamically allocated) , HAS TO BE  char[]

    // IMP:
    // The read() function copies the binary data from the file directly into the memory of object s, reconstructing the object.
    // Reads entire object in one shot
    // This is Basically "Binary Deserialization"

    fin.read((char *)&s, sizeof(s));
    fin.close();

    cout << "Roll: " << s.roll << endl;
    cout << "Name: " << s.name << endl;
    cout << "Marks: " << s.marks << endl;

    return 0;
}
