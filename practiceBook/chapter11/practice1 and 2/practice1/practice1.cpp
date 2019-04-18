#include <iostream>
#include <string>

class Publication
{
private:
	std::string title;
	float price;

public:
	virtual void getData()
	{
		std::cout << "Введите название книги: ";
		std::getline(std::cin, title);
		std::cout << "Введите цену книги: ";
		std::cin >> price;
	}

	virtual void putData()
	{
		std::cout << "Название - " << title << std::endl;
		std::cout << "Цена - " << price << std::endl;
	}
};

class Book : public Publication
{
private:
	int numPages;

public:
	void getData()
	{
		Publication::getData();
		std::cout << "Введите количество страниц в книге: ";
		std::cin >> numPages;
		std::cin.ignore();
	}

	void putData()
	{
		Publication::putData();
		std::cout << "Количество страниц - " << numPages << std::endl;
	}
};

class Type : public Publication
{
private:
	float time;

public:
	void getData()
	{
		Publication::getData();
		std::cout << "Введите время записи в минутах: ";
		std::cin >> time;
		std::cin.ignore();
	}

	void putData()
	{
		Publication::putData();
		std::cout << "Время записи в минутах - " << time << std::endl;
	}
};

int main()
{
	system("chcp 1251");

	Publication* pubArr[100];

	int count = 0;
	char a;
	do {
		std::cout << "Обект какого типа необходимо создать? (b - book, t - type)... ";
		std::cin >> a;

		switch (a) {
			case 'b':
				pubArr[count] = new Book;
				break;
			case 't':
				pubArr[count] = new Type;
				break;
			default:
				break;
		}

		std::cin.ignore();
		pubArr[count++]->getData();

		std::cout << "Продолжить? (y/n)... ";
		std::cin >> a;

	} while (a != 'n');

	for (int i = 0; i < count; i++) {
		pubArr[i]->putData();
	}
}