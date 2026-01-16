#include<iostream>
#include<fstream>
using namespace std;
//serialization: with "write" object into a binary format
//deserialization: with "read" raw binary data into an object
//when you write, size of the data members should be fixed
//strings are not fixed so you have to use char
class Student{
public:
    int roll;
    char name[20];
    float marks;
};
int main(){
    Student s = {1,"Prasad",88.5};
    ofstream fout("student.dat", ios::binary);
    fout.write((char *)&s, sizeof(s));
    fout.close();
    cout<<"Binary data written. \n";
    Student s1;
    ifstream fin("student.dat",ios::binary);
    if(!fin){
        cout<<"Error:\n";
        return 0;
    }
    fin.read((char *)&s1, sizeof(s1));
    fin.close();

    cout<<"Roll: "<<s1.roll<<endl;
    cout<<"Name: "<<s1.name<<endl;
    cout<<"Marks: "<<s1.marks<<endl;
    return 0;
}