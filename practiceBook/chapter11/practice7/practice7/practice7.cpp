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
	bMoney() {};

	explicit bMoney(long double var) : value(var) {};

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
		}
		else {
			sValue = "Amount over!";
		}
		cout << "Amount many - " << sValue << endl;
	}

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

	friend long double operator* (long double var, bMoney & mon);

	friend long double operator/ (long double var, bMoney & mon);

	friend bMoney round(bMoney& mon);
};

bMoney round(bMoney& mon)
{
	long double var;
	return modfl(mon.value, &var) < 0.5 ? bMoney(var) : bMoney(var + 1.0);
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
	long double var1, var2, var3;
	char a;
	do {
		mon1.getMoney();
		mon2.getMoney();
		cout << "Input long double: ";
		cin >> var2;

		mon3 = mon1 + mon2;
		mon3.putMoney();
		mon3 = mon1 - mon2;
		mon3.putMoney();
		mon3 = mon1 * var2;
		mon3.putMoney();
		mon3 = mon1 / var2;
		mon3.putMoney();
		var1 = mon1 / mon2;
		cout << var1 << endl;
		var3 = var1 * mon1;
		cout << var3 << endl;
		var3 = var1 / mon1;
		cout << var3 << endl;
		mon1 = round(mon3);
		mon1.putMoney();
		cout << "Repeat? y/n ";

		cin >> a;
	} while (a != 'n');
}