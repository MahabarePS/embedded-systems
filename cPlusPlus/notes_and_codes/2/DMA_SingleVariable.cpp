// Program :
// DMA for a single variable

#include <iostream>
using namespace std;

int main()
{
    int *ptr = new int; // dynamic allocation , may have garbage
    *ptr = 25;

    cout << "1. Value of *ptr is : " << *ptr << endl;
    delete ptr; // free memory

    // NOTE : do not try and access the memory after u free it
    cout << "Value of *ptr after free is : " << *ptr << endl; // may give junk , because u already freed the memory

    // We can also do this
    int *p1 = new int(); // initialises to 0
    cout << "2. Value of *p1 is : " << *p1 << endl;

    // AND .. We can also do this
    int *p2 = new int(30); // initialises to 30
    cout << "3. Value of *p2 is : " << *p2 << endl;

    // good practice : assign all pointers to null
    ptr = p1 = p2 = nullptr;

    return 0;
}
