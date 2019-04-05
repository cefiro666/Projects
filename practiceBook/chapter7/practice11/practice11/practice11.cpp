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

	void showMoney()
	{
		cout << setiosflags(ios::fixed)
			<< setiosflags(ios::showpoint)
			<< setprecision(2)
			<< "Amount - " << value;
	}

	void ldtoms(long double value)
	{
		stringstream ss;
		string temp;
		if (value <= 9999999999999990.00)
		{
			ss << value;
			temp = ss.str();
			sValue.push_back('$');
			for (int i = 0; i < temp.size(); i++)
			{
				if (temp.at(i) == '0' || temp.at(i) == '1' || temp.at(i) == '2' ||
					temp.at(i) == '3' || temp.at(i) == '4' || temp.at(i) == '5' ||
					temp.at(i) == '6' || temp.at(i) == '7' || temp.at(i) == '8' ||
					temp.at(i) == '9' || temp.at(i) == '.')
				{
					sValue.push_back(temp.at(i));
				}
			}
		} else {
			cout << "Amount over!" << endl;
		}
	}
};

int main()
{
	Money money;
	money.setMoney();
	money.mstdold();
	money.showMoney();
}