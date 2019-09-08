#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
///////////////////////////////////////////////////////////
class person            // некоторый человек
{
protected:
	string name;        // имя
	float salary;

public:
	void setData()    // установка имени
	{
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите зарплату: ";
		cin >> salary;
	}

	void printData()  // показ имени
	{
		cout << endl << "Имя - " << name;
		cout << endl << "Зарплата - " << salary;

	}

	string getName()  // получение имени
	{
		return name;
	}

	float getSalary()  // получение имени
	{
		return salary;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");
	void bsort(person**, int); // прототип функции
	void salsort(person** pp, int n);
	person* persPtr[100];      // массив указателей на person
	int n = 0;                    // количество элементов в массиве
	char choice;                  // переменная для ввода символа

	do
	{
		persPtr[n] = new person;       // создаем новый объект
		persPtr[n]->setData();       // вводим имя
		n++;                              // увеличиваем количество
		cout << "Продолжаем ввод (д/н)?"; // спрашиваем, закончен ли ввод
		cin >> choice;
	} while (choice == 'д');

	cout << "\nНеотсортированный список:";
	for (int j = 0; j < n; j++) // покажем неотсортированный список
		persPtr[j]->printData();

	//bsort(persPtr, n);         // отсортируем указатели
	salsort(persPtr, n);

	cout << "\nОтсортированный список:";
	for (int j = 0; j < n; j++)     // покажем отсортированный список
		persPtr[j]->printData();
	cout << endl;

	return 0;
}
///////////////////////////////////////////////////////////
void bsort(person** pp, int n)
{
	void order(person**, person**); 

	for (int j = 0; j < n - 1; j++)      // внешний цикл
		for (int k = j + 1; k < n; k++)    // внутренний цикл
			order(pp + j, pp + k);      // сортируем два элемента
}
///////////////////////////////////////////////////////////
void order(person** pp1, person** pp2)
{
	if ((*pp1)->getName() > (*pp2)->getName()) // если первая строка больше второй,
	{
		person* tempptr = *pp1; // меняем их местами
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}

void salsort(person** pp, int n)
{
	for (int j = 0; j < n - 1; j++)
	{
		for (int k = j + 1; k < n; k++)
		{
			if ((*(pp+j))->getSalary() < (*(pp+k))->getSalary()) // если первая строка больше второй,
			{
				person* tempptr = *(pp+j); // меняем их местами
				*(pp+j) = *(pp+k);
				*(pp+k) = tempptr;
			}
		}
	}
}

