/*
File Handling using fstream (Read + Write)

1. fstream is a file stream class in C++ that allows BOTH reading and writing to files.
2. It combines the functionality of:
   - ifstream (input / read)
   - ofstream (output / write)
3. File open modes used here:
   - ios::out → open file for writing
   - ios::in  → open file for reading
4. After writing to a file, it is good practice to close the file before opening it again for reading.
5. Text files use formatted I/O (<< and getline).
   Binary files use unformatted I/O functions read() and write().
*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    fstream file;

    // WRITE to file
    file.open("data.txt", ios::out); // open file for writing

    file << "Name: Rahul\n";
    file << "Age: 21\n";
    file << "Marks: 85\n";

    file.close(); // close file after writing

    // READ from file
    file.open("data.txt", ios::in); // open file for reading

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close(); // close file after reading

    return 0;
}
