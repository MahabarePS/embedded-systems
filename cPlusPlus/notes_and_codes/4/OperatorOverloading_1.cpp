/*
COMPILE-TIME POLYMORPHISM : OPERATOR OVERLOADING

OPERATOR OVERLOADING:
- Operator overloading allows C++ operators (+, -, *, /, etc.)
  to work with user-defined data types (classes).
- It is a form of compile-time (static) polymorphism.
- The operator function to be called is decided at compile time.

WHY OPERATOR OVERLOADING?
- Improves code readability and usability.
- Makes user-defined objects behave like built-in data types.

WITHOUT OPERATOR OVERLOADING:
	ix = i1.Add(i2);
	iy = i3.Subtract(i4);
	i5 = ix.Divide(iy);

WITH OPERATOR OVERLOADING:
	i5 = (i1 + i2) / (i3 - i4);

IMPORTANT RULES:
- Only existing operators can be overloaded.
- Operator overloading does NOT change the meaning of operators,
  it only extends their behavior to user-defined types.
- Operators work on objects only if explicitly overloaded.
*/

#include <iostream>
#include <string.h>
using namespace std;

/*
COMPLEX NUMBER CLASS
- Demonstrates overloading of binary '+' operator
*/
class Complex
{
private:
	int real, imag;

public:
	// Default constructor
	Complex()
	{
		real = 0;
		imag = 0;
	}

	// Parameterised constructor
	Complex(int r, int i)
	{
		real = r;
		imag = i;
	}

	/*
	Without operator overloading, we would need an explicit
	member function like Add() to add two Complex objects.
	*/
	Complex Add(Complex obj)
	{
		Complex r;
		r.real = this->real + obj.real;
		r.imag = this->imag + obj.imag;
		return r;
	}

	/*
	OPERATOR OVERLOADING:
	- This function is automatically called when '+' is used
	  between two Complex objects.
	- c1 + c2 is internally treated as: c1.operator+(c2)
	*/
	Complex operator+(Complex obj)
	{
		Complex res;
		res.real = real + obj.real; // this->real + obj.real
		res.imag = imag + obj.imag; // this->imag + obj.imag
		return res;
	}

	void printcomplex()
	{
		cout << real << " + i" << imag << endl;
	}
};

/*
STRING CLASS
- Demonstrates operator overloading for binary '+' operator
*/
#include <iostream>
using namespace std;

class String
{
private:
	string str;

public:
	// Default constructor
	String()
	{
		str = " ";
	}

	// Parameterised constructor
	String(string s)
	{
		str = s;
	}

	// Overloading '+' using C++ string functions
	String operator+(String obj)
	{
		String res;
		res.str = str;			 // assignment replaces strcpy
		res.str.append(obj.str); // append replaces strcat
		return res;
	}

	void printstring()
	{
		cout << "The Concatenated String Is " << str << endl;
	}
};

int main()
{
	Complex c1(10, 5), c2(2, 4);
	Complex c3, c4;

	cout << "c1 : ";
	c1.printcomplex();

	cout << "c2 : ";
	c2.printcomplex();

	// Without operator overloading
	// c3 = c1.Add(c2);
	// c3.printcomplex();

	// With operator overloading
	c3 = c1 + c2; // calls c1.operator+(c2)
	cout << "c1 + c2 is : ";
	c3.printcomplex();

	// Chaining of overloaded operators
	c4 = c1 + c2 + c3;
	cout << "c1 + c2 + c3 is : ";
	c4.printcomplex();

	/*
	// For Strings
	String s1("Hello");
	String s2("World!!");
	String s3, s4; // s3 and s4 will be 1 space

	// Operator chaining for strings
	s4 = s1 + s3 + s2;
	s4.printstring(); */

	return 0;
}
