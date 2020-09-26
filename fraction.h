// Name: Kevin Huynh
// Filename: fraction.h
// Description: Defines the Fraction class

#include <iostream>

using namespace std;

class Fraction {
private:
	int numerator;		// Self-explanatory
	int denominator;
public:
	Fraction(int n = 0, int d = 1) {numerator = n; denominator = d;}	// Default and can use two parameters for the constructor
	Fraction operator++();					// Overrides ++
	Fraction operator++(int);				// Overrides ++
	Fraction operator+(Fraction secondOp);	// Overrides +
	Fraction operator-(Fraction secondOp);	// Overrides -
	Fraction operator*(Fraction secondOp);	// Overrides *
	Fraction operator/(Fraction secondOp);	// Overrides /
	Fraction reduce();						// Simplifies the numerator and denominator
	operator double();						// Overrides (double)
	int gcd(int m, int n);					// Finds the greatest common denominator
	friend ostream& operator<<(ostream& out, Fraction& n);		// Overrides cout (<<)
	friend istream& operator>>(istream& in, Fraction& n);		// Overrides cin (>>)
	friend bool operator>(Fraction firstOp, Fraction secondOp); // Overrides >
	friend bool operator<(Fraction fristOp, Fraction secondOp);	// Overrides <
	bool operator==(Fraction secondOp);		// Overrides ==
};