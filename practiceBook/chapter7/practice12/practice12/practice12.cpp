#include "pch.h"
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

class bMoney
{
private:
	long double value;

public:
	void getMoney()
	{
		string sValue;
		cout << "Input money amount: ";
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
		} else {
			sValue = "Amount over!";
		}
		cout << "Amount many - " << sValue << endl;
	}

	void mAdd(bMoney mon1, bMoney mon2)
	{
		value = mon1.value + mon2.value;
	}
};

int main()
{
	bMoney mon1, mon2, mon3;
	mon1.getMoney();
	mon2.getMoney();
	mon3.mAdd(mon1, mon2);
	mon3.putMoney();
}