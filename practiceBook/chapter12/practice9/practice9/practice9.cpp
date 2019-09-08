#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Fraction
{
private:
	int numerator;
	int denominator;

public:
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
		Fraction temp(numerator, denominator);
		temp = lowterms(temp);
		numerator = temp.numerator;
		denominator = temp.denominator;
	}

	void showFraction()
	{
		cout << numerator << "/" << denominator << endl;
	}

	friend istream& operator >> (istream&, Fraction&);
	friend ostream& operator << (ostream&, Fraction&);

	Fraction operator+(Fraction add2)
	{
		Fraction temp;
		temp.numerator = (numerator * add2.denominator) + (denominator * add2.numerator);
		temp.denominator = denominator * add2.denominator;
		temp = lowterms(temp);
		return temp;
	}

	Fraction operator- (Fraction sub2)
	{
		Fraction temp;
		temp.numerator = (numerator * sub2.denominator) - (denominator * sub2.numerator);
		temp.denominator = denominator * sub2.denominator;
		temp = lowterms(temp);
		return temp;
	}

	Fraction operator* (Fraction mul2)
	{
		Fraction temp;
		temp.numerator = numerator * mul2.numerator;
		temp.denominator = denominator * mul2.denominator;
		temp = lowterms(temp);
		return temp;
	}

	Fraction operator/ (Fraction div2)
	{
		Fraction temp;
		temp.numerator = numerator * div2.denominator;
		temp.denominator = denominator * div2.numerator;
		temp = lowterms(temp);
		return temp;
	}

	bool operator== (Fraction div2)
	{
		return numerator == div2.numerator && denominator == div2.denominator;
	}

	bool operator!= (Fraction div2)
	{
		return numerator != div2.numerator || denominator != div2.denominator;
	}

	Fraction lowterms(Fraction var);

};

istream& operator >> (istream& in, Fraction& frac)
{
	char dummy;
	in >> frac.numerator >> dummy >> frac.denominator;
	return in;
}

ostream& operator << (ostream& out, Fraction& frac)
{
	out << frac.numerator << "/" << frac.denominator;
	return out;
}

Fraction Fraction::lowterms(Fraction var)
{
	long tnum, tden, temp, gcd;
	tnum = labs(var.numerator);
	tden = labs(var.denominator);

	if (tden == 0)
	{
		cout << "Недопустимый знаменатель!";
		exit(1);
	}
	else if (tnum == 0) {
		var.numerator = 0;
		var.denominator = 1;
		return var;
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
	var.numerator /= gcd;
	var.denominator /= gcd;
	return var;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Fraction fr1(1, 4);
	Fraction fr2(2, 4);
	Fraction fr3;
	fr3 = fr1 + fr2;
	fr3.showFraction();
	fr3 = fr1 - fr2;
	fr3.showFraction();
	fr3 = fr1 * fr2;
	fr3.showFraction();
	fr3 = fr1 / fr2;
	fr3.showFraction();

	cout << "Введите дробь... ";
	char op;
	cin >> fr1 >> op >> fr2;
	if (op == '+')
	{
		fr3 = fr1 + fr2;
		cout << "Результат - " << fr3;
	}
}