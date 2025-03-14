#include <iostream>
using namespace std;

int main()
{
	// naming convetions:
	// * snake case : my_variable 	=> Variables
	// * camel case : myVariable	=> Functions
	// * pascal case: MyVariable	=> Classes
	// * hungarian notation: iMyVariable (not recommended)



	cout << "== VARIABLES ==" << endl;
	// initialize variables
	int a = 1;
	int b = 2;

	// also possible like this
	//int a = 1, b = 2;

	// print variables
	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << "swapping..." << endl;

	// to swap variables, we ned a extra variable 
	// to store value a so we can assign it to b
	int swap = a;
	a = b;
	b = swap;

	cout << "a: " << a << endl;
	cout << "b: " << b << endl;

	cout << endl;

	cout << "== CONSTANTS ==" << endl;
	// const prevent reassigning a variable
	const double pi = 3.15;
	//pi = 4; // error: assignment of read-only variable 'pi'

	return 0;
}