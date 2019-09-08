#include "pch.h"
#include <iostream>
#include <string>

class Date
{
private:
	int day;
	int month;
	int year;

public:
	void setDate()
	{
		std::string sDay;
		std::string sMonth;
		std::string sYear;
		std::cout << "Введите дату публикации в формате dd/mm/yyyy: ";
		std::getline(std::cin, sDay, '/');
		std::getline(std::cin, sMonth, '/');
		std::getline(std::cin, sYear);
		day = stoi(sDay);
		month = stoi(sMonth);
		year = stoi(sYear);
	}
	void showDate()
	{
		std::cout << day << "/" << month << "/" << year << std::endl;
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

class Publication2 : public Publication
{
private:
	Date date;

public:
	void getData()
	{
		Publication::getData();
		date.setDate();
	}

	void putData()
	{
		Publication::putData();
		std::cout << "Дата публикации - ";
		date.showDate();
	}
};

class Book : public Publication2
{
private:
	int numPages;

public:
	void getData()
	{

		Publication2::getData();
		std::cout << "Введите количество страниц в книге: ";
		std::cin >> numPages;
		std::cin.ignore();
	}

	void putData()
	{
		Publication2::putData();
		std::cout << "Количество страниц - " << numPages << std::endl;
	}
};

class Type : public Publication2
{
private:
	float time;

public:
	void getData()
	{
		Publication2::getData();
		std::cout << "Введите время записи в минутах: ";
		std::cin >> time;
		std::cin.ignore();
	}

	void putData()
	{
		Publication2::putData();
		std::cout << "Время записи в минутах - " << time << std::endl;
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