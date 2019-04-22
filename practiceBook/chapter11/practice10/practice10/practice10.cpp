
#include <iostream>

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
	linklist(linklist& li)
	{
		first = li.first;
		while (first)
		{
			link* newlink = new link;      // выделяем память
			newlink->data = li.first->data;             // запоминаем данные
			newlink->next = li.first->next;         // запоминаем значение first
			first = newlink;               // first теперь указывает на новый элемент
		}
	}

	linklist()            // конструктор без параметров
	{
		first = 0;
	}     // первого элемента пока нет
	void additem(int d); // добавление элемента

	void display();       // показ данных

	linklist& operator = (linklist& li)
	{
		linklist* li2 = new linklist;
		li2->first = li.first;
		while (li2->first)
		{
			link* newlink = new link;      // выделяем память
			newlink->data = li.first->data;             // запоминаем данные
			newlink->next = li.first->next;         // запоминаем значение first
			li2->first = newlink;               // first теперь указывает на новый элемент
		}
		return *li2;
	}

	~linklist()
	{
		link* current = first;
		while (current)
		{
			link* temp = current;
			current = current->next;
			delete temp;
			cout << "delete" << endl;
		}
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
	linklist* li = new linklist;       // создаем переменную-список

	li->additem(25); // добавляем туда несколько чисел
	li->additem(36);
	li->additem(49);
	li->additem(64);
	li->additem(64);
	li->additem(64);

	li->display();    // показываем список

	linklist* li2 = li;

	delete li;

	li2->display();
	return 0;
}


