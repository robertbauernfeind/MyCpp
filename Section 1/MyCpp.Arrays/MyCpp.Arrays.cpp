#include <iostream>

using namespace std;

int main()
{
	// declare array
	int numbers[5];

	// prints memory address
	cout << numbers << endl;

	// unassigned value index 0
	cout << numbers[1] << endl;

	numbers[1] = 10;
	cout << numbers[1] << endl;

	// print index out of array bound
	// does not throw an indexOutOfRange exception
	// just prints some garbage value
	// intelisense shows a warning
	cout << numbers[10] << endl;

	// initializing a array without specifying the size
	// will automatically set the size of the given values
	int numbers2[] = { 1, 2, 3, 4, 5 };

	// prints the first value of the array
	cout << numbers2[0] << endl;

	// again, when printing value out of bound, 
	// intelisense will show warning and print garbage value
	cout << numbers2[10] << endl;

	// assigning a value to an index out of bound
	// does not let you compile your code, error
	//numbers2[10] = 10;

	// == Exercise ==
	// create an array for 3 names, ask for 
	// user input and print first name

	cout << "== Exercise ==" << endl;
	string names[3];

	cout << "Enter first name: ";
	cin >> names[0];

	cout << "Enter second name: ";
	cin >> names[1];

	cout << "Enter third name: ";
	cin >> names[2];

	cout << "First name: " << names[0] << endl;
}