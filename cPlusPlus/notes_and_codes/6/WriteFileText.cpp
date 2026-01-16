/*
File Streams in C++

What is File Handling?
File handling allows a C++ program to store data permanently in files and retrieve it later,
instead of losing data when the program ends.

File Stream Classes : C++ provides these classes from <fstream>:
Class	        Purpose
-------------------------------
ifstream	    Read from files
ofstream	    Write to files
fstream	        Read + Write

File Opening Modes :
Mode	        Meaning
---------------------------------
ios::in	        Read
ios::out	    Write
ios::app	    Append
ios::binary	    Binary mode
ios::trunc	    Clear file contents

*/

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Note :
    // - ofstream stands for Output File Stream; It is a class provided by C++
    //   It is used to WRITE data into a file
    // - fout is an object (variable) of type ofstream; u can call it anything ((file, outFile, etc.)
    //   we just normally use fout becuase it matches cout (by convention)
    //   u can very well do this :
    //      ofstream data("sample.txt");
    //      data << "C++ File Handling";
    // - "sample.txt" is the file name
    //      Exists - it will be opened and overwritten
    //      Does not exist - it will be created
    //      The file is created in the same folder as your program (unless a path is given)

    // ofstream uses default file open modes automatically , so no modes explicityly required
    // Defaults :
    // ios::out - open for writing
    // ios::trunc - overwrite the file if it already exists
    // text mode (not binary)

    ofstream fout("sample.txt");

    fout << "Name: RahulNew\n";
    fout << "Age: 21\n";
    fout << "Marks: 85\n";

    fout.close();
    cout << "Data written to file.\n";
    return 0;
}
