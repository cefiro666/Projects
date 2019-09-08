#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	system("chcp 1251");
	void bsort(const char** pp, int n);
	const char* arrptrs[7] = { "Понедельник", 
		"Вторник", "Среда", "Четверг", "Пятница", 
		"Суббота", "Воскресенье" };

	bsort(arrptrs, 7);

	for (int i = 0; i < 7; i++)
	{
		cout << *(arrptrs + i) << endl;
	}
}

void bsort(const char** pp, int n)
{
	void order(const char**, const char**);

	for (int j = 0; j < n - 1; j++)      // внешний цикл
		for (int k = j + 1; k < n; k++)    // внутренний цикл
			order(pp + j, pp + k);      // сортируем два элемента
}

void order(const char** pp1, const char** pp2)
{
	if (strcmp(*pp1, *pp2) > 0) // если первая строка больше второй,
	{
		const char* tempptr = *pp1; // меняем их местами
		*pp1 = *pp2;
		*pp2 = tempptr;
	}
}