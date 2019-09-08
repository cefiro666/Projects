#include "pch.h"
// stakaray.cpp
// класс стек
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Queue
{
private:
	enum { MAX = 10 }; // немного нестандартный синтаксис
	int st[MAX];    // стек в виде массива
	int tail;
	int count;

public:
	Queue() 
	{
		count = 0;
		tail = MAX - 1;
	}
	void put(int var) // поместить в стек
	{
		if (count == MAX)
		{
			for (int i = 0; i < MAX; i++)
			{
				if (i != tail)
				{				
					st[i] = st[i + 1];
				} else {
					st[i] = var;
				}
			}
		} else {
			st[count++] = var;
		}
	}
	int get() // взять из стека
	{
		int value = st[0];
		for (int i = 0; i < count; i++)
		{
			st[i] = st[i + 1];
		}
		if (count > 0)
		{
			count--;
			return value;
		} else {
			return -1;
		}
	}
};
///////////////////////////////////////////////////////////
int main()
{
	Queue q;
	q.put(4);
	q.put(7);
	q.put(12);
	q.put(45);
	q.put(3);
	q.put(23);
	q.put(11);
	q.put(7867);
	q.put(52);
	q.put(45);
	q.put(33);
	q.put(89);
	cout << q.get() << endl;
	cout << q.get() << endl;
	cout << q.get() << endl;
}


