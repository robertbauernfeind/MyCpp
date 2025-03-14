#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// seed random generator with elapsed time since 1970
	srand(time(0));
	// % 10 will give us a number between 0 and 9
    int number = rand() % 10;

	cout << number << endl;

	// Exercice
	// random dice

	cout << endl << "== Exercise ==" << endl;
	const short minValue = 1, maxValue = 6;

	short first = (rand() % (maxValue - minValue + 1)) + minValue;
	short second = (rand() % (maxValue - minValue + 1)) + minValue;

	cout << "First dice: " << first << endl;
	cout << "Second dice: " << second << endl;
}