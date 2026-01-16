/*
What is a Binary File?
- Data stored in raw memory format
- Faster and more secure than text files
- Used for objects, structures, databases

Serialization :
- Serialization is the process of converting an object into a file (binary format) so that it can be stored permanently
and reconstructed later.
- Deserialization is the reverse process, where the data stored in a file is read back and converted into
an object in memory.

In C++, serialization and deserialization are commonly done using:
- write() → SERIALIZATION (object → file)
- read() → DESERIALIZATION (file → object)
*/

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
    Student s = {1, "Amit", 88.5};

    ofstream fout("student.dat", ios::binary);

    // write() is a member function of ofstream ;
    //   - Used ONLY for binary files
    //   - It writes bytes, not formatted text
    // Syntax : write(address, number_of_bytes);
    //   - &s gives the starting memory address of the object s (of class Student)
    //   - Why typecast to char*?
    //     - write() expects a pointer to bytes ; char is 1 byte
    //     - So char* means "pointer to raw bytes"
    // VIMP :
    // - Binary file handling using read() and write() works only for objects containing fixed-size data members
    // - So data member CANNOT be String (since this is not fixed size  dynamically allocated) , HAS TO BE  char[]

    // IMP:
    // The write function Takes the object s ; Converts it into a sequence of bytes and Stores those bytes into a file
    // This is Basically "Binary Serialisation"

    fout.write((char *)&s, sizeof(s));

    fout.close();

    cout << "Binary data written.\n";
    return 0;
}
