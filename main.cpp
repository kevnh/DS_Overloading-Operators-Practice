// Name: Kevin Huynh
// Filename: main.cpp
// Description: Shows off the overrided operators for the Fraction class

#include <iostream>

#include "fraction.h"

using namespace std;

int main() {
	Fraction x, y, z;										// Initializes three Fraction variables

	cout << "Enter two fractions (in the form numerator/denominator): ";	// Prompt for the next two inputs
	cin >> x;
	cin >> y;

	/*if (x > y) {											// Unused code
		cout << x << " is bigger than " << y << endl;
	}
	else if (x < y) {
		cout << x << " is less than " << y << endl;
	}
	else if (x == y) {
		cout << x << " is equivalent to " << y << endl;
	}*/
	z = x + y;												// Uses the overrided + operator
	cout << x << " + " << y << " = " << z << endl;
	z.reduce();												// Simplifies z
	cout << "Reduced: " << z << endl << endl;
	z = x - y;												// Uses the overrided - operator
	cout << x << " - " << y << " = " << z << endl;
	z.reduce();
	cout << "Reduced: " << z << endl << endl;
	z = x * y;												// Uses the overrided * operator
	cout << x << " * " << y << " = " << z << endl;
	z.reduce();
	cout << "Reduced: " << z << endl << endl;
	z = x / y;												// Uses the overrided / operator
	cout << x << " / " << y << " = " << z << endl;
	z.reduce();
	cout << "Reduced: " << z << endl << endl;
	cout << x << " as a double is " << (double)x << endl;	// Uses the overrided (double) operator

	system("pause");
	return 0;
}