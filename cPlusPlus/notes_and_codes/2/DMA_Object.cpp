// Program :
// DMA for an Object

#include <iostream>
using namespace std;

class Student
{
public:
    int roll;

    Student()
    {
        roll = 0;
        cout << "Constructor called\n";
    }

    ~Student()
    {
        cout << "Destructor called\n";
    }
};

int main()
{
    Student *s = new Student; // constructor runs

    s->roll = 101;
    cout << s->roll;

    delete s; // destructor runs
}
