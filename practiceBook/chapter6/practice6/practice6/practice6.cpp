#include "pch.h"
#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Date
{
private:
	int day;
	int month;
	int year;

public:
	void setDate()
	{
		string sDay;
		string sMonth;
		string sYear;
		cout << "Введите дату в формате dd/mm/yyyy: ";
		getline(cin, sDay, '/');
		getline(cin, sMonth, '/');
		getline(cin, sYear);
		day = stoi(sDay);
		month = stoi(sMonth);
		year = stoi(sYear);
	}

	void showDate() const
	{
		cout << day << "/" << month << "/" << year << endl;
	}
};

enum Etype { laborer, secretary, manager, accountant, executive };

class Employee
{
private:
	int number;
	float salary;
	Date date;
	Etype type;

public:
	void get_employee() const
	{
		cout << "Номер сотрудника " << number << endl;
		cout << "Оклад сотрудника " << salary << endl;
		cout << "Дата приема на работу "; date.showDate();

		cout << "Занимаемая должность ";
		switch (type)
		{
		case laborer:
			cout << "laborer" << endl;
			break;
		case secretary:
			cout << "secretary" << endl;
			break;
		case manager:
			cout << "manager" << endl;
			break;
		case accountant:
			cout << "accountant" << endl;
			break;
		case executive:
			cout << "executive" << endl;
			break;
		}
	}

	void set_employee()
	{
		cout << "Введите номер сотрудника ";
		cin >> number;

		cout << "Введите оклад сотрудника ";
		cin >> salary;

		cout << "Введите дату приема на работу сотрудника ";
		date.setDate();

		char var;
		cout << "Введите первую букву названия должности\n(laborer,secretary,manager,accountant,executive)... ";
		cin >> var;
		switch (var)
		{
		case 'l':
			type = laborer;
			break;
		case 's':
			type = secretary;
			break;
		case 'm':
			type = manager;
			break;
		case 'a':
			type = accountant;
			break;
		case 'e':
			type = executive;
			break;
		default:
			cout << "Неверный ввод!" << endl;
			break;
		}
	}
};

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Employee Jon, Stive, Don;

	Jon.set_employee();
	Stive.set_employee();
	Don.set_employee();

	Jon.get_employee();
	Stive.get_employee();
	Don.get_employee();
}