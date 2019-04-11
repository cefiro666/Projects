#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class Sterling;

class bMoney
{
private:
	long double value;

public:
	bMoney() {};

	bMoney(long double var) : value(var) {};

	void getMoney()
	{
		string sValue;
		cout << "Enter the amount in the form $1,000,000.00: ";
		cin >> sValue;

		string tempValue;
		for (unsigned int i = 0; i < sValue.size(); i++)
		{
			if (sValue.at(i) == '0' || sValue.at(i) == '1' || sValue.at(i) == '2' ||
				sValue.at(i) == '3' || sValue.at(i) == '4' || sValue.at(i) == '5' ||
				sValue.at(i) == '6' || sValue.at(i) == '7' || sValue.at(i) == '8' ||
				sValue.at(i) == '9' || sValue.at(i) == '.')
			{
				tempValue.push_back(sValue.at(i));
			}
		}
		value = stold(tempValue);
	}

	void putMoney()
	{
		string sValue;
		if (value <= 9999999999999990.00)
		{
			stringstream ss;
			ss << setiosflags(ios::fixed)
				<< setiosflags(ios::showpoint)
				<< setprecision(2) << value;

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

			sValue.push_back('$');
			sValue.append(temp);
		}
		else {
			sValue = "Amount over!";
		}
		cout << "Amount many - " << sValue << endl;
	}

	operator Sterling();

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
};


class Sterling
{
private:
	long pounds;
	int shillings;
	int pence;

public:
	Sterling() {};

	Sterling(double pounds)
	{
		this->pounds = static_cast<long> (pounds);
		double despounds = pounds - this->pounds;
		shillings = static_cast <int> (despounds * 20);
		pence = static_cast<int>(despounds * 240 - shillings * 12);
	}

	Sterling(long pounds, int shillings, int pence) : pounds(pounds), shillings(shillings), pence(pence) {}

	void getSterling()
	{
		stringstream ss;
		string sValue;
		string sPounds, sShillings, sPence;
		cout << "Enter the amount in the form J17.9.6: ";
		cin >> sValue;

		string tempValue;
		for (unsigned int i = 0; i < sValue.size(); i++)
		{
			if (sValue.at(i) == '0' || sValue.at(i) == '1' || sValue.at(i) == '2' ||
				sValue.at(i) == '3' || sValue.at(i) == '4' || sValue.at(i) == '5' ||
				sValue.at(i) == '6' || sValue.at(i) == '7' || sValue.at(i) == '8' ||
				sValue.at(i) == '9' || sValue.at(i) == '.')
			{
				tempValue.push_back(sValue.at(i));
			}
		}
		ss << tempValue;
		getline(ss, sPounds, '.');
		pounds = stol(sPounds);
		getline(ss, sShillings, '.');
		shillings = stoi(sShillings);
		getline(ss, sPence, '.');
		pence = stoi(sPence);
	}

	void putSterling()
	{
		cout << "Result: J" << pounds << "." << shillings << "." << pence << endl;
	}

	operator double()
	{
		return static_cast<double>(pounds) + static_cast<double>(shillings / 20.0) + static_cast<double>(pence / 240.0);
	}

	operator bMoney()
	{
		return bMoney(static_cast<long double>(double(Sterling(pounds, shillings, pence) * 50.0)));
	}

	Sterling operator + (Sterling st)
	{
		return Sterling(double(Sterling(pounds, shillings, pence)) + double(st));
	}

	Sterling operator - (Sterling st)
	{
		return Sterling(double(Sterling(pounds, shillings, pence)) - double(st));
	}

	Sterling operator * (double var)
	{
		return Sterling(double(Sterling(pounds, shillings, pence)) * var);
	}

	double operator / (Sterling st)
	{
		return double(Sterling(pounds, shillings, pence)) / double(st);
	}

	Sterling operator / (double var)
	{
		return Sterling(double(Sterling(pounds, shillings, pence)) / var);
	}
};

bMoney::operator Sterling()
{
	return Sterling(double(value / 50.0));
}

int main()
{
	bMoney mon1, mon2;
	Sterling st1, st2;
	mon1.getMoney();
	st1.getSterling();
	mon2 = st1;
	cout << "J->$: ";
	mon2.putMoney();
	st2 = mon1;
	cout << "$->J: ";
	st2.putSterling();
}