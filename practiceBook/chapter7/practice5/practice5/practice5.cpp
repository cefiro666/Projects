#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Fraction
{
public:
	int numerator;
	int denominator;

	Fraction() {};

	Fraction(int n, int d) : numerator(n), denominator(d) {};

	void setFraction()
	{
		string num;
		string denom;
		cout << "Input fraction (x/y) - ";
		getline(cin, num, '/');
		getline(cin, denom);
		numerator = stoi(num);
		denominator = stoi(denom);
		lowterms();
	}

	void showFraction()
	{
		cout << numerator << "/" << denominator << endl;
	}

	void addFraction(Fraction add1, Fraction add2)
	{
		numerator = (add1.numerator * add2.denominator) + (add1.denominator * add2.numerator);
		denominator = add1.denominator * add2.denominator;
		lowterms();
	}

	void subFraction(Fraction sub1, Fraction sub2)
	{
		numerator = (sub1.numerator * sub2.denominator) - (sub1.denominator * sub2.numerator);
		denominator = sub1.denominator * sub2.denominator;
		lowterms();
	}

	void mulFraction(Fraction mul1, Fraction mul2)
	{
		numerator = mul1.numerator * mul2.numerator;
		denominator = mul1.denominator * mul2.denominator;
		lowterms();
	}

	void divFraction(Fraction div1, Fraction div2)
	{
		numerator = div1.numerator * div2.denominator;
		denominator = div1.denominator * div2.numerator;
		lowterms();
	}

	void lowterms();
};

void Fraction::lowterms()
{
	long tnum, tden, temp, gcd;
	tnum = labs(numerator);
	tden = labs(denominator);

	if (tden == 0)
	{
		cout << "Недопустимый знаменатель!";
		exit(1);
	}
	else if (tnum == 0) {
		numerator = 0;
		denominator = 1;
		return;
	}

	while (tnum != 0)
	{
		if (tnum < tden)
		{
			temp = tnum;
			tnum = tden;
			tden = temp;
		}

		tnum -= tden;
	}

	gcd = tden;
	numerator /= gcd;
	denominator /= gcd;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction arr[100];
	
	char a;
	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		cout << "Enter an integer: ";
		arr[count++].setFraction();
		cout << "Repeat? y/n ";
		cin >> a;
		if (a == 'n') break;
	}

	Fraction average = arr[0];

	Fraction countFrac;
	countFrac.numerator = count;
	countFrac.denominator = 1;

	for (int i = 1; i < count; i++)
	{
		average.addFraction(average, arr[i]);
	}

	average.divFraction(average, countFrac);

	cout << "Average fraction - ";
	average.showFraction();
}