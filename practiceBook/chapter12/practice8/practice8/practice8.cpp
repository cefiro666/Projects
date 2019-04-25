// linklist.cpp
// список
#include <iostream>
#include <fstream>

using namespace std;

///////////////////////////////////////////////////////////
struct link   // один элемент списка
{
	int data;   // некоторые данные
	link* next; // указатель на следующую структуру
};
///////////////////////////////////////////////////////////
class linklist // список
{
private:
	link* first;
public:
	linklist()            // конструктор без параметров
	{
		first = NULL;
	}     // первого элемента пока нет
	void additem(int d); // добавление элемента
	void display();       // показ данных

	void writeFile()
	{
		fstream file;
		file.open("link.dat", ios::out);
		link* current = first;           // начинаем с первого элемента
		while (current)                 // пока есть данные
		{
			file << current->data << endl; // печатаем данные
			current = current->next;       // двигаемся к следующему элементу
		}

		file.close();
	}

	void readFile()
	{
		fstream file;
		file.open("link.dat", ios::in);

		int value;
		while (!file.eof())
		{
			file >> value;
			if (file) additem(value);
		}

		file.close();
	}
};
///////////////////////////////////////////////////////////
void linklist::additem(int d) // добавление элемента
{
	link* newlink = new link;      // выделяем память
	newlink->data = d;             // запоминаем данные
	newlink->next = first;         // запоминаем значение first
	first = newlink;               // first теперь указывает на новый элемент
}
///////////////////////////////////////////////////////////
void linklist::display()
{
	link* current = first;           // начинаем с первого элемента
	while (current)                 // пока есть данные
	{
		cout << current->data << endl; // печатаем данные
		current = current->next;       // двигаемся к следующему элементу
	}
}
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");

	linklist list;
	char ch;

	while (true)
	{
		cout << "\nВыберите действие:\n";
		cout << "1. Добавить ссылку в список\n";
		cout << "2. Показать данные по всем ссылкам\n";
		cout << "3. Записать в фаил\n";
		cout << "4. Считать данные из файла\n";
		cout << "5. Выход\n";
		cout << "\nВаш вариант... ";

		cin >> ch;

		switch (ch)
		{
		case '1':
			int value;
			cout << "Введите целое число для добавления... ";
			cin >> value;
			list.additem(value);
			break;
		case '2':
			cout << "Данные:\n";
			list.display();
			break;
		case '3':
			list.writeFile();
			cout << "Данные записаны.\n";
			break;
		case '5':
			return 0;
			break;
		case '4':
			linklist list2;
			list2.readFile();

			cout << "Данные считаны. Вот список: \n";
			list2.display();
			break;
		}
	}
}


