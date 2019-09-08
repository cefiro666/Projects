#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

class Employee
{
private:
	string name;
	long number;

public:
	void getData()
	{
		cout  << "Input name: ";
		cin >> name;
		cout << "Input number: ";
		cin >> number;
	}

	void putData()
	{
		cout << "Name - " << name
			<< ", Number - " << number << endl;
	}
};

int main()
{
	Employee arr[100];
	char a;
	int count = 0;

	do {
		arr[count++].getData();
		cout << "Repeat? ";
		cin >> a;
	} while (a != 'n');

	for (int i = 0; i < count; i++)
	{
		arr[i].putData();
	}
}