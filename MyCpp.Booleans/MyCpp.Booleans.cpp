#include <iostream>

using namespace std;

int main()
{
	//bool isNewUser = false;
	bool isNewUser = 0;

	// prints out boolean as 0 or 1
	cout << "Print boolean without manipulator: "
		 << isNewUser << endl;

	// prints out boolean as true or false
	// boolalpha is a sticky manipulator, so it will 
	// affect all leading boolean outputs until it gets deactivated
	// with noboolalpha
	cout << "Print boolean with manipulator: "
		 << boolalpha << isNewUser << endl;

	// disable boolalpha
	noboolalpha(cout);

	cout << "Show sticky manipulator: "
		<< isNewUser << endl
		<< boolalpha << isNewUser << endl
		<< isNewUser << endl
		<< noboolalpha << isNewUser << endl;
}