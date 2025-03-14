#include <iostream>

int main()
{
	int x = 10;
	int y = 20;

	// writes all at one line
	/*std::cout << "x = " << x;
	std::cout << "y = " << y;*/

	// endl is a new line
	/*std::cout << "x = " << x << std::endl;
	std::cout << "y = " << y << std::endl;*/

	std::cout
		<< "x = " << x << std::endl
		<< "y = " << y << std::endl;

	// Excecise
	// salary = 95.000$
	// state tax = 4%
	// county tax = 2%

	std::cout << std::endl << "== Exercise ==" << std::endl;
	int sales = 95000;
	const double stateTax = 0.04, countyTax = 0.02;

	double stateTaxRate = sales * stateTax;
	std::cout << "State Tax: $" << stateTaxRate << std::endl;

	double countyTaxRate = sales * countyTax;
	std::cout << "Country Tax: $" << countyTaxRate << std::endl;

	double totalTax = stateTaxRate + countyTaxRate;
	std::cout << "Total Tax: $" << totalTax << std::endl;
}