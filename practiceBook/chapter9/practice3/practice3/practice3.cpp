#include "pch.h"
#include <iostream>
#include <string>

class Sales
{
private:
	float sales[3];

public:
	void getData()
	{
		std::cout << "Введите стоимость за последние три месяца: " << std::endl;
		for (int i = 0; i < sizeof(sales)/sizeof(sales[0]); i++)
		{
			std::cin >> sales[i];
		}
	}

	void putData()
	{
		std::cout << "Стоимость за последние три месяца: " << std::endl;
		for (int i = 0; i < sizeof(sales) / sizeof(sales[0]); i++)
		{
			std::cout << i + 1 << " месяц - "  << sales[i] << std::endl;
		}
	}
};

class Publication
{
private:
	std::string title;
	float price;

public:
	void getData()
	{
		std::cout << "Введите название книги: ";
		std::getline(std::cin, title);
		std::cout << "Введите цену книги: ";
		std::cin >> price;
	}

	void putData()
	{
		std::cout << "Название - " << title << std::endl;
		std::cout << "Цена - " << price << std::endl;
	}
};

class Book : public Publication, public Sales
{
private:
	int numPages;

public:
	void getData()
	{
		Publication::getData();
		std::cout << "Введите количество страниц в книге: ";
		std::cin >> numPages;
		Sales::getData();
		std::cin.ignore();
	}

	void putData()
	{
		Publication::putData();
		std::cout << "Количество страниц - " << numPages << std::endl;
		Sales::putData();
	}
};

class Type : public Publication, public Sales
{
private:
	float time;

public:
	void getData()
	{
		Publication::getData();
		std::cout << "Введите время записи в минутах: ";
		std::cin >> time;
		Sales::getData();
		std::cin.ignore();
	}

	void putData()
	{
		Publication::putData();
		std::cout << "Время записи в минутах - " << time << std::endl;
		Sales::putData();
	}
};

int main()
{
	system("chcp 1251");
	Book book;
	Type type;
	book.getData();
	type.getData();
	book.putData();
	type.putData();
}