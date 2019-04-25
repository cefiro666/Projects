#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class bMoney
{
private:
	long double value;
	string sValue;

public:
	bMoney() {};

	explicit bMoney(long double var) : value(var) {};

	bMoney operator+ (bMoney mon2)
	{
		return bMoney(value + mon2.value);
	}

	bMoney operator- (bMoney mon2)
	{
		return bMoney(value - mon2.value);
	}

	bMoney operator* (long double var)
	{
		return bMoney(value * var);
	}

	long double operator/ (bMoney mon2)
	{
		return value / mon2.value;
	}

	bMoney operator/ (long double var)
	{
		return bMoney(value / var);
	}

	friend long double operator * (long double var, bMoney & mon);

	friend long double operator / (long double var, bMoney & mon);

	friend ostream& operator << (ostream&, bMoney&);

	friend istream& operator >> (istream&, bMoney&);

};

ostream& operator << (ostream& out, bMoney& money)
{
	if (money.value <= 9999999999999990.00)
	{
		stringstream ss;
		ss << setiosflags(ios::fixed)
			<< setiosflags(ios::showpoint)
			<< setprecision(2) << money.value;

		string temp = ss.str();

		for (unsigned int i = 0; i < temp.length() / 2; i++)
		{
			swap(temp[i], temp[temp.length() - i - 1]);
		}

		for (unsigned int i = 0; i < temp.length(); i++)
		{
			if (i == 6) temp.insert(i, ",");
			if (i == 10) temp.insert(i, ",");
			if (i == 14) temp.insert(i, ",");
			if (i == 18) temp.insert(i, ",");
			if (i == 22) temp.insert(i, ",");
		}

		for (unsigned int i = 0; i < temp.length() / 2; i++)
		{
			swap(temp[i], temp[temp.length() - i - 1]);
		}

		money.sValue.push_back('$');
		money.sValue.append(temp);
	}
	else {
		money.sValue = "Amount over!";
	}
	out << money.sValue;
	return out;
}

istream& operator >> (istream& in, bMoney& money)
{
	in >> money.sValue;
	string tempValue;
	for (unsigned int i = 0; i < money.sValue.size(); i++)
	{
		if (money.sValue.at(i) == '0' || money.sValue.at(i) == '1' || money.sValue.at(i) == '2' ||
			money.sValue.at(i) == '3' || money.sValue.at(i) == '4' || money.sValue.at(i) == '5' ||
			money.sValue.at(i) == '6' || money.sValue.at(i) == '7' || money.sValue.at(i) == '8' ||
			money.sValue.at(i) == '9' || money.sValue.at(i) == '.')
		{
			tempValue.push_back(money.sValue.at(i));
		}
	}
	money.value = stold(tempValue);
	return in;
}

long double operator * (long double var, bMoney & mon)
{
	return var * mon.value;
}

long double operator / (long double var, bMoney & mon)
{
	return var / mon.value;
}

int main()
{
	bMoney mon1, mon2, mon3;
	long double var2;
	char a;
	do {
		cout << "Input mon1: ";
		cin >> mon1;
		cout << "Input mon2: ";
		cin >> mon2;
		cout << "Input long double: ";
		cin >> var2;

		mon3 = mon1 + mon2;
		cout << "Result - " << mon3 << endl;
		mon3 = mon1 - mon2;
		cout << "Result - " << mon3 << endl;
		mon3 = mon1 * var2;
		cout << "Result - " << mon3 << endl;
		mon3 = mon1 / var2;
		cout << "Result - " << mon3 << endl;
		cout << "Repeat? y/n ";

		cin >> a;
	} while (a != 'n');
}