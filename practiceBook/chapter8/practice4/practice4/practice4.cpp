// practice4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>

using namespace std;

class Int
{
private:
	long double value;

public:
	Int() :value(0) {}

	Int(long double v)
	{
		value = v;
	}

	void print_value()
	{
		cout << value << endl;
	}

	Int operator+(Int val)
	{
		Int temp(value);
		if (temp.value + val.value <= 2147483648.0L
			&& temp.value + val.value >= -2147483648.0L)
		{
			temp.value += val.value;
		}
		else {
			cout << "Overflow!" << endl;
			exit(1);
		}
		return temp;
	}

	Int operator-(Int val)
	{
		Int temp(value);
		if (temp.value - val.value <= 2147483648.0L
			&& temp.value - val.value >= -2147483648.0L)
		{
			temp.value -= val.value;
		}
		else {
			cout << "Overflow!" << endl;
			exit(1);
		}
		return temp;
	}

	Int operator*(Int val)
	{
		Int temp(value);
		if (temp.value * val.value <= 2147483648.0L
			&& temp.value * val.value >= -2147483648.0L)
		{
			temp.value *= val.value;
		}
		else {
			cout << "Overflow!" << endl;
			exit(1);
		}
		return temp;
	}
	Int operator/(Int val)
	{
		Int temp(value);
		if (temp.value / val.value <= 2147483648.0L
			&& temp.value / val.value >= -2147483648.0L)
		{
			temp.value /= val.value;
		} else {
			cout << "Overflow!" << endl;
			exit(1);
		}
		return temp;
	}
};

int main()
{
	Int val1;
	Int val2 = 25;
	Int val3 = 45646345636654677;
	val1 = val2 + val3;
	val1.print_value();
	val1 = val2 - val3;
	val1.print_value();
	val1 = val2 * val3;
	val1.print_value();
	val1 = val2 / val3;
	val1.print_value();
}