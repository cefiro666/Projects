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

	bool isZeroDenom()
	{
		return denominator == 0;
	}

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

	Fraction fr1, fr2, fr3;
	char op;
	while (true)
	{
		cout << "Введите первую дробь... ";
		cin >> fr1;
		if (cin.good())
		{
			if (!fr1.isZeroDenom())
			{
				cin.ignore(10, '\n');
				break;
			}
			else {
				cin.clear();
				cout << "Знаменатель не может быть равен нулю!\n";
				cin.ignore(10, '\n');
			}
		}
		else {
			cin.clear();
			cout << "Неправильный формат данных!\n";
			cin.ignore(10, '\n');
		}
	}

	while (true)
	{
		cout << "Введите оператор... ";
		cin >> op;
		if (cin.good() && (op == '+' || op == '-' || op == '*' || op == '/'))
		{
			cin.ignore(10, '\n');
			break;
		}
		cin.clear();
		cout << "Неправильный формат данных!\n";
		cin.ignore(10, '\n');
	}

	while (true)
	{
		cout << "Введите вторую дробь... ";
		cin >> fr2;
		if (cin.good())
		{
			if (!fr2.isZeroDenom())
			{
				cin.ignore(10, '\n');
				break;
			}
			else {
				cin.clear();
				cout << "Знаменатель не может быть равен нулю!\n";
				cin.ignore(10, '\n');
			}
		}
		else {
			cin.clear();
			cout << "Неправильный формат данных!\n";
			cin.ignore(10, '\n');
		}
	}

	switch (op)
	{
	case '+':
		fr3 = fr1 + fr2;
		cout << "Результат - " << fr3;
		break;
	case '-':
		fr3 = fr1 - fr2;
		cout << "Результат - " << fr3;
		break;
	case '*':
		fr3 = fr1 * fr2;
		cout << "Результат - " << fr3;
		break;
	case '/':
		fr3 = fr1 / fr2;
		cout << "Результат - " << fr3;
		break;
	default:
		break;
	}
}