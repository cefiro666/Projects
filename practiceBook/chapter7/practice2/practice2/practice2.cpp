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
		cin.clear();
		cout  << "Input name: ";
		getline(cin, name);
		cin.clear();
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
		arr[count].getData();
		count++;
		cout << "Repeat? ";
		cin.clear();
		a = getchar();
		putchar(a);
	} while (a != 'n');

	for (int i = 0; i < count; i++)
	{
		arr[i].putData();
	}
}