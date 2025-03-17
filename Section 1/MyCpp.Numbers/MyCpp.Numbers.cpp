#include <iostream>

using namespace std;

int main()
{
	// decimal
	//int number = 255
	// binary
	//int number = 0b11111111;
	// hex
	int number = 0xff;
	cout << number << endl;

	// unsigned int
	// not recommended
	// what does this do
	unsigned int number2 = 0;
	number2--;
	cout << number2 << endl;


	// Narrowing
	cout << endl << "Narrowing" << endl;
	short n1 = 100;
	int a1 = n1;

	cout << a1 << endl;
}