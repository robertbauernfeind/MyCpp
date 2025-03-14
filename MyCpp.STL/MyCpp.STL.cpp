#include <iostream>

using namespace std;

int main()
{
    // 2^3
    double result = pow(2, 3);
    cout << "2^3 = " << result << endl;

    // ceil
	double ceilResult = ceil(4.2);
	cout << "ceil(4.2) = " << ceilResult << endl;

	// floor
	double floorResult = floor(4.8);
	cout << "floor(4.8) = " << floorResult << endl;

	// Exercice
	// calculate the area of a circle

	cout << endl << "== Exercise ==" << endl;
	cout << "Enter the radius of the circle: ";
	double radius;
	cin >> radius;

	double area = pow(radius, 2) * 3.14159;
	cout << "The aria of the circle is: " << area << endl;
}