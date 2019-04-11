#include "pch.h"
#include <iostream>

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

	Sterling(long pounds, int shillings, int pence): pounds(pounds), shillings(shillings), pence(pence) {}

	void getSterling()
	{
		cout << "Enter pounds: ";
		cin >> pounds;
		cout << "Enter shillings: ";
		cin >> shillings;
		cout << "and pens: ";
		cin >> pence;
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
	Sterling var1(5,7,5);
	Sterling var2, var3;
	var2.getSterling();
	var3 = var1 + var2;
	var3.putSterling();
}