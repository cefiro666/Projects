#include "pch.h"
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
	linklist() : first(0) {}

	void additem(int d); // добавление элемента

	void display();       // показ данных

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
	link* newlink = new link;      
	newlink->data = d;   
	newlink->next = 0;

	if (first != 0)
	{
		link* current = first;
		while (current->next != 0)
		{
			current = current->next;
		}
		current->next = newlink;
	} else {
		first = newlink;
	}	
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
	linklist li;       // создаем переменную-список

	li.additem(25); // добавляем туда несколько чисел
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.additem(76);
	li.additem(36);
	li.additem(49);
	li.additem(64);
	li.additem(76);

	li.display();    // показываем список

	return 0;
}


