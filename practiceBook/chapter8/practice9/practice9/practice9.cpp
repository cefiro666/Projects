#include "pch.h"
// arrover3.cpp
// демонстрация создания безопасного массива, проверяющего
// свои индексы при использовании
// используется перегрузка операции [ ]
#include <iostream>
using namespace std;
#include <process.h>      // для функции exit
const int LIMIT = 100;    // размер массива
///////////////////////////////////////////////////////////
class safearray
{
private:
	int arr[LIMIT];
	
public:
	int low;
	int hight;
	safearray() {};
	safearray(int l, int h) : low(l), hight(h) {};
	// обратите внимание, что функция возвращает ссылку!
	int& operator[ ] (int n)
	{
		if (n < 0 || n >= LIMIT)
		{
			cout << "\nОшибочный индекс!"; exit(1);
		}
		return arr[n];
	}
};
///////////////////////////////////////////////////////////
int main()
{
	safearray sa1(30,70);

	// задаем значения элементов
	for (int j = sa1.low - LIMIT; j < sa1.hight; j++)
		sa1[j] = j * 10;    // используем функцию слева от знака =

	  // показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1[j]; // используем функцию справа от знака =
		cout << "Элемент " << j << " равен " << temp << endl;
	}

	return 0;
}


