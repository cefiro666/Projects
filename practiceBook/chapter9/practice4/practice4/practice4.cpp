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
		std::cout << "Введите объем продаж за: " << std::endl;
		for (int i = 0; i < sizeof(sales) / sizeof(sales[0]); i++)
		{
			std::cout << i + 1 << " месяц - ";
			std::cin >> sales[i];
		}
	}

	void putData()
	{
		std::cout << "Стоимость за последние три месяца: " << std::endl;
		for (int i = 0; i < sizeof(sales) / sizeof(sales[0]); i++)
		{
			std::cout << i + 1 << " месяц - " << sales[i] << std::endl;
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

class Disk : public Publication, public Sales
{
private:
	enum Type {CD, DVD};
	Type disk;

public:
	void getData()
	{
		Publication::getData();
		char a;
		std::cout << "Выберите тип диска(d - DVD, c - CD): ";
		std::cin >> a;
		switch (a)
		{
		case 'c':
			disk = CD;
			break;
		case 'd':
			disk = DVD;
			break;
		default:
			break;
		}
		Sales::getData();
		std::cin.ignore();
	}

	void putData()
	{
		Publication::putData();
		std::cout << "Тип диска - ";
		switch (disk)
		{
		case CD:
			std::cout << "CD" << std::endl;
			break;
		case DVD:
			std::cout << "DVD" << std::endl;
			break;
		default:
			break;
		}
		Sales::putData();
	}
};

int main()
{
	system("chcp 1251");
	Book book;
	Type type;
	Disk disk;
	book.getData();
	type.getData();
	disk.getData();
	book.putData();
	type.putData();
	disk.putData();
}