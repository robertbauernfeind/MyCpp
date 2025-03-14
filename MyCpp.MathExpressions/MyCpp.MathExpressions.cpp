#include <iostream>
using namespace std;

int main()
{
	// math expressions
	int x = 10, y = 3;

	// addition
	cout << "x + y = " << x + y << endl;

	// subtraction
	cout << "x - y = " << x - y << endl;

	// multiplication
	cout << "x * y = " << x * y << endl;

	// division
	// integer division will always be an integer
	// 10 / 3 = int 3
	cout << "x / y = " << x / y << endl;

	// division 2
	// res as double and casting a variable to double 
	// will result in a double division
	double res = (double)x / y;
	cout << "x / y = " << res << endl;

	// modulo
	cout << "x % y = " << x % y << endl;
}