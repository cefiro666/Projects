#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

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

	void showValue()
	{
		cout << setiosflags(ios::fixed)
			<< setiosflags(ios::showpoint)
			<< setprecision(2)
			<< "Value - " << value;
	}

	void showMany()
	{
		cout << "Amount many - " << sValue << endl;
	}

	void ldtoms(long double value)
	{
		if (value <= 9999999999999990.00)
		{
			stringstream ss;
			ss << setiosflags(ios::fixed)
				<< setiosflags(ios::showpoint)
				<< setprecision(2) << value;

			char temp[19] = ss.str();
			sValue.push_back('$');
			for (int i = 0; i < 19 - temp.size(); i++)
			{
				if (i == 1) { sValue.push_back(','); }
				if (i == 4) { sValue.push_back(','); }
				if (i == 7) { sValue.push_back(','); }
				if (i == 10) { sValue.push_back(','); }
				if (i == 13) { sValue.push_back(','); }
				sValue.push_back('0');
			}
			sValue.push_back(temp.at(i));
		} else {
			cout << "Amount over!" << endl;
		}
	}
};

int main()
{
	Money money;
	money.ldtoms(3456.78);
	money.showMany();
}