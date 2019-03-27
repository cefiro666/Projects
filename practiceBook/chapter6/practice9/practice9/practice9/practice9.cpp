#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;
	
public:
	void setFraction()
	{
		string num;
		string denom;
		cout << "Input fraction (x/y) - ";
		getline(cin, num, '/');
		getline(cin, denom);
		numerator = stoi(num);
		denominator = stoi(denom);
	}

	void showFraction()
	{
		cout << numerator << "/" << denominator << endl;
 	}

	void addFraction(Fraction add1, Fraction add2)
	{
		numerator = (add1.numerator * add2.denominator)
			+ (add1.denominator * add2.numerator);

		denominator = add1.denominator * add2.denominator;
		
	}
};

int main()
{
	Fraction fr1, fr2, fr3;
	char answer;
	do {
		fr1.setFraction();
		fr2.setFraction();
		fr3.addFraction(fr1, fr2);
		fr3.showFraction();
		cout << "To repeat? (y/n)... ";
		cin >> answer;
	} while (answer == 'y');
}
