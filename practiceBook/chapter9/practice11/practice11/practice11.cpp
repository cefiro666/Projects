#include "pch.h"
#include <iostream>

using namespace std;

struct Pair
{
	int x;
	int y;
};

class Stack
{
protected:              // Замечание: использовать private нельзя
	enum { MAX = 3 };     // размер стека
	int st[MAX];        // данные, хранящиеся в стеке
	int top;  

public:
	Stack()
	{
		top = -1;
	}

	void push(int var) // помещение числа в стек
	{
		st[++top] = var;
	}

	int pop()           // извлечение числа из стека
	{
		return st[top--];
	}
};
///////////////////////////////////////////////////////////
class Stack2 : public Stack
{
public:
	void push(int var)      // помещение числа в стек
	{
		if (top >= MAX - 1)  // если стек полон, то ошибка
		{
			cout << "\nОшибка: стек полон"; exit(1);
		}
		Stack::push(var);   // вызов функции push класса Stack
	}

	int pop()                // извлечение числа из стека
	{
		if (top < 0)         // если стек пуст, то ошибка
		{
			cout << "\nОшибка: стек пуст\n"; exit(1);
		}
		return Stack::pop(); // вызов функции pop класса Stack
	}
};

class PairStack : public Stack2
{
private:
	Pair pair;

public:
	void push(Pair pair)      // помещение числа в стек
	{
		Stack2::push(pair.x);
		Stack2::push(pair.y);
	}

	Pair pop()                // извлечение числа из стека
	{
		Pair pair;
		pair.x = Stack2::pop();
		pair.y = Stack2::pop();
		return pair;
	}
};

///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");
	PairStack s1;

	Pair pair, pair1;
	pair.x = 5;
	pair.y = 8;

	s1.push(pair);
	pair1 = s1.pop();
	cout << pair1.x << " " << pair1.y;

	return 0;
}


