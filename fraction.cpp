// Name: Kevin Huynh
// Filename: fraction.cpp
// Description: Defines the methods for Fraction class

#include <iostream>

#include "fraction.h"

using namespace std;

Fraction Fraction::operator++() {
	numerator = numerator + denominator;	// Adds the denominator to the numerator
	return 0;
}

Fraction Fraction::operator++(int) {
	numerator = numerator + denominator;	// Same as above
	return 0;
}

Fraction Fraction::operator+(Fraction secondOp) {		// Takes a second Fraction for the + operator
	int newNumerator, newDenominator;
	newNumerator = numerator * secondOp.denominator;
	newDenominator = denominator * secondOp.denominator;
	secondOp.numerator = secondOp.numerator * denominator;
	newNumerator = newNumerator + secondOp.numerator;
	return Fraction(newNumerator, newDenominator);		// Creates a new fraction with the resulting numerator and denominator
}

Fraction Fraction::operator-(Fraction secondOp) {		// Takes a second Fraction for the - operator
	int newNumerator, newDenominator;
	newNumerator = numerator * secondOp.denominator;
	newDenominator = denominator * secondOp.denominator;
	secondOp.numerator = secondOp.numerator * denominator;
	newNumerator = newNumerator - secondOp.numerator;
	return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator*(Fraction secondOp) {		// Takes a second Fraction for the * operator
	int newNumerator, newDenominator;
	newNumerator = numerator * secondOp.numerator;
	newDenominator = denominator * secondOp.denominator;
	return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::operator/(Fraction secondOp) {		// Takes a second Fraction for the / operator
	int newNumerator, newDenominator;
	newNumerator = numerator * secondOp.denominator;
	newDenominator = denominator * secondOp.numerator;
	return Fraction(newNumerator, newDenominator);
}

Fraction Fraction::reduce() {
	int d = gcd(numerator, denominator);			// Calls gcd() to find the greatest common denominator
	numerator = numerator / d;			// Uses the gcd to divide the numerator and denominator
	denominator = denominator / d;
	return 0;
}

Fraction::operator double() {
	return (double)numerator / (double)denominator;	// Casts the numerator and denominator separately then divides them
}

int Fraction::gcd(int m, int n) {		// Finds the greatest common denominator
	/*if (n == 0) {						// Recursive version (unused)
		return m;
	}
	else if (n > m) {
		return gcd(n, m);
	}
	else {
		return gcd(n, m % n);
	}*/
	int x = 0;
	m = abs(m);			// Prevents infinite loop with negative numbers
	n = abs(n);
	while (n != 0) {		// New while-loop version (used to prevent stack overflow)
		x = m;
		if (n > m) {
			m = n;
			n = x;
		}
		else {
			m = n;
			n = x % n;
		}
	}
	return m;
}

bool operator>(Fraction firstOp, Fraction secondOp) {	// Takes 2 Fractions (friend function)
	int x, y;
	x = firstOp.numerator * secondOp.denominator;
	y = secondOp.numerator * firstOp.denominator;
	if (x > y) {										// Compares the resulting numerators
		return true;
	}
	return false;
}

bool operator<(Fraction firstOp, Fraction secondOp) {	// Does the same as above except for < (friend function)
	int x, y;
	x = firstOp.numerator * secondOp.denominator;
	y = secondOp.numerator * firstOp.denominator;
	if (x < y) {
		return true;
	}
	return false;
}

bool Fraction::operator==(Fraction secondOp) {			// Does the same as above except for ==
	int x, y;
	x = numerator * secondOp.denominator;
	y = secondOp.numerator * denominator;
	if (x == y) {
		return true;
	}
	return false;
}

ostream& operator<<(ostream& out, Fraction& n) {
	cout << n.numerator << "/" << n.denominator;		// Prints numerator / denominator whenever using cout <<
	return out;
}

istream& operator>> (istream& in, Fraction& n) {
	char junk;
	cin >> n.numerator;								// Takes the first part of the input
	cin >> junk;									// Takes the second part of the input
	cin >> n.denominator;							// Takes the third part of the input
	return in;
}