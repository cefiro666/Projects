#include "pch.h"
#include <iostream>

using namespace std;

const int LEN = 80;       // максимальная длина имени
///////////////////////////////////////////////////////////
class student             // сведения об образовании
{
private:
	char school[LEN];   // название учебного заведения
	char degree[LEN];   // уровень образования
public:
	void getedu()
	{
		cout << "  Введите название учебного заведения: ";
		cin >> school;
		cout << "  Введите степень высшего образования\n";
		cout << "  (неполное высшее, бакалавр, магистр, кандидат наук): ";
		cin >> degree;
	}
	void putedu() const
	{
		cout << "\n  Учебное заведение: " << school;
		cout << "\n  Степень: " << degree;
	}
};
///////////////////////////////////////////////////////////
class employee            // некий сотрудник
{
private:
	char name[LEN];     // имя сотрудника
	unsigned long number; // номер сотрудника
public:
	void getdata()
	{
		cout << "\n  Введите фамилию: "; cin >> name;
		cout << "  Введите номер: ";     cin >> number;
	}
	void putdata() const
	{
		cout << "\n  Фамилия: " << name;
		cout << "\n  Номер: " << number;
	}
};
///////////////////////////////////////////////////////////
class manager : private employee, private student // менеджер
{
private:
	char title[LEN];    // должность сотрудника
	double dues;          // сумма взносов в гольф-клуб
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите должность: "; cin >> title;
		cout << "  Введите сумму взносов в гольф-клуб: "; cin >> dues;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  Должность: " << title;
		cout << "\n  Сумма взносов в гольф-клуб: " << dues;
		student::putedu();
	}
};
///////////////////////////////////////////////////////////
class scientist : private employee, private student // ученый
{
private:
	int pubs;             // количество публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите количество публикаций: "; cin >> pubs;
		student::getedu();
	}
	void putdata() const
	{
		employee::putdata();
		cout << "\n  Количество публикаций: " << pubs;
		student::putedu();
	}
};
///////////////////////////////////////////////////////////
class laborer : public employee // рабочий
{
};

class Executive : public manager
{
private:
	float premium;
	int purchase;

public:
	void getdata()
	{
		manager::getdata();
		cout << " Введите размер годовой премии: ";
		cin >> premium;
		cout << " Акций в пакете владения: ";
		cin >> purchase;
	}

	void putdata() const
	{
		manager::putdata();
		cout << " Размер годовой премии - " << premium << endl;
		cout << "\n Акций в пакете - " << purchase << endl;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");
	manager m1;
	scientist s1, s2;
	laborer l1;
	Executive e1;

	// введем информацию о нескольких сотрудниках
	cout << endl;
	cout << "\nВвод информации о первом менеджере";
	m1.getdata();

	cout << "\nВвод информации о первом управляющем";
	e1.getdata();

	cout << "\nВвод информации о первом ученом";
	s1.getdata();

	cout << "\nВвод информации о втором ученом";
	s2.getdata();

	cout << "\nВвод информации о первом рабочем";
	l1.getdata();

	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	m1.putdata();
	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	e1.putdata();
	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	s1.putdata();
	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	s2.putdata();

	// выведем полученную информацию на экран
	cout << "\nИнформация о первом менеджере";
	l1.putdata();
	cout << endl;
	return 0;
}


