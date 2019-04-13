#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Sterling
{
private:
	long int pounds;
	int shillings;
	int pence;

public:
	Sterling() {};

	Sterling(double pounds)
	{
		this->pounds = static_cast<long int> (pounds);
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

int main()
{
	Sterling var1(5, 7, 5);
	Sterling var2, var3;
	var2.getSterling();
	var3 = var1 + var2;
	var3.putSterling();
}