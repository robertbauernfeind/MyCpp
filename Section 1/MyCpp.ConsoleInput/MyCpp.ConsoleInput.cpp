#include <iostream>

// STL = Standard Template Library
using namespace std;

int main()
{
	cout << "Enter values for x and y: ";
	double x, y;

	// cin -> [c]aracter [in]put
	// option 1
	/*cin >> x;
	cin >> y;*/

	// option 2
	// chain input
	cin >> x >> y;

	cout << x + y;

	// Exercice
	// calculate fahrenheit to celsius

	cout << endl << "== Exercise ==" << endl;
	cout << "Enter fahrenheit: ";
	double fahrenheit;
	cin >> fahrenheit;

	double celsius = (fahrenheit - 32) * 5 / 9;
	cout << "Celsius: " << celsius << endl;
}