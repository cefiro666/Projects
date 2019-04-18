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

	bool virtual isOversize() = 0;
};

class Book : public Publication
{
private:
	int numPages;

public:
	void getData() override
	{
		Publication::getData();
		std::cout << "Введите количество страниц в книге: ";
		std::cin >> numPages;
		std::cin.ignore();
	}

	void putData() override
	{
		Publication::putData();
		std::cout << "Количество страниц - " << numPages << std::endl;
	}

	bool isOversize() override
	{
		return (numPages > 800);
	}
};

class Type : public Publication
{
private:
	float time;

public:
	void getData() override
	{
		Publication::getData();
		std::cout << "Введите время записи в минутах: ";
		std::cin >> time;
		std::cin.ignore();
	}

	void putData() override
	{
		Publication::putData();
		std::cout << "Время записи в минутах - " << time << std::endl;
	}

	bool isOversize() override
	{
		return (time > 90);
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
				std::cin.ignore();
				pubArr[count++]->getData();
				break;
			case 't':
				pubArr[count] = new Type;
				std::cin.ignore();
				pubArr[count++]->getData();
				break;
			default:
				std::cout << "Неверный ввод!\n";
				break;
		}

		std::cout << "Продолжить? (y/n)... ";
		std::cin >> a;

	} while (a != 'n');

	for (int i = 0; i < count; i++) {
		pubArr[i]->putData();
		if (pubArr[i]->isOversize())
		{
			std::cout << "Превышение лимита!\n";
		}
	}
}