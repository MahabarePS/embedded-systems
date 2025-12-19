// Pointers and Refrences
// Refer Notes for Differences between Pointers and References

#include <iostream>
using namespace std;

int main()
{

	// Pointer Variables
	// Holds the address of another variable

	/*
	int x, y;
	x = 12;
	y = 15;

	int *ptr;
	ptr = &x;

	cout << "POINTERS ..... \n";
	cout << "Address of x is : " << ptr << endl;
	cout << "Value of Pointer (address of x) is : " << ptr << endl;
	cout << "Value of x (using pointer and dereferencing) is : " << *ptr << endl;

	*ptr = 5; // Dereference ; changes the value at the address ptr points to ; to 5

	cout << "New Value of x (using pointer and dereferencing) is : " << *ptr << endl;

	// Can change pointer to point to a different variable
	ptr = &y;
	cout << "Address of y is " << &y << endl;
	cout << "Value of Pointer (address of y) is : " << ptr << endl;
	cout << "Value of y (using pointer and dereferencing) is : " << *ptr << endl;

	// Can assign NULL to a pointer
	ptr = NULL;
	cout << "Pointer Value (after assigning NULL) is : " << ptr << endl;

	// Reference variable = alias for another variable
	// Contains the address of a variable 	(like a pointer)
	// No need to perform any dereferencing (unlike a pointer)

	cout << "\nREFERENCES ..... \n";

	/* int &ref = x; // Declaration Of Reference Variable

	cout << "Address of Varible x is : " << &x << endl;
	cout << "Address of Ref Varible is : " << &ref << endl;
	cout << "Value of Ref Varible is : " << ref << endl;

	// Reference Cannot be changed to refer to a different variable once set
	// changes value of 'x' to 15, doesn't rebind ref to y
	// Reference variable is still refereing to the original address

	ref = y;
	cout << "Address of Varible y is : " << &y << endl;
	cout << "Address of Ref Varible is : " << &ref << endl;
	cout << "Value of Ref Varible is : " << ref << endl;
	cout << "Value of x  is : " << ref << endl;*/

	char x = 'a';
	int &ref = (int &)(x);

	cout << "value of x is : " << x << endl;
	cout << "value of ref is : " << ref << endl;
}
