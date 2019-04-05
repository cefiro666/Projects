#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Money
{
private:
	long double value;
	string sValue;

public:
	void setMoney()
	{
		cout << "Input money amount: ";
		cin >> sValue;
	}

	void mstdold()
	{
		string tempValue;
		for (int i = 0; i < sValue.size(); i++)
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

	void showMoney()
	{
		cout << setiosflags(ios::fixed)
			<< setiosflags(ios::showpoint)
			<< setprecision(2)
			<< "Amount - " << value;
	}
};

int main()
{
	Money money;
	money.setMoney();
	money.mstdold();
	money.showMoney();
}