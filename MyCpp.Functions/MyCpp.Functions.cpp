#include <iostream>
#include "greet.hpp"

using namespace std;

int increaseByValueNoRef(int value)
{
	return ++value;
}

void increaseByValueRef(int& value)
{
	++value;
}

void greetModify(string& name) {
	cout << "Hello " << name << endl;
	name = "Changed";
}

// Function decleration (function prototype)
void testFunction();

int main()
{
	// without reference
	// value is copied into function, which uses double the memory
	int value = 5;
	value = increaseByValueNoRef(value);
	cout << "Value after increaseByValue: " << value << endl;

	// with reference
	// value reference is given to function, which uses the same memory
	// it has no return type because same variable is modified
	int value2 = 5;
	increaseByValueRef(value2);
	cout << "Value after increaseByValue: " << value2 << endl;

	// with numbers, this is not a big deal
	// strings can use more space, so it is better to use reference
	// to avoid copying the string
	// warning: when passing values by reference, the value can
	// be modified by the function which affects the original value
	string value3 = "Fred";
	cout << "Value before greet: " << value3 << endl;
	greet(value3);

	// modify value3 by reference
	greetModify(value3);
	cout << "Value after greetModify: " << value3 << endl;

	// When writing a function after the main function, the function
	// has to be delcared before the main function
	// and defined after the main function

	cout << "Function decleration: " << endl;
	testFunction();
}

// Function definition
void testFunction()
{
	cout << "This is a test function" << endl;
}