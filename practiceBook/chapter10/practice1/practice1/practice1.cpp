#include "pch.h"
#include <iostream>

using namespace std;

const int MAX = 100;

int main()
{
	system("chcp 1251");
	cout << "Расчет среднего арифметического.\n";

	float arr[MAX];
	int count = 0;
	char a;
	do {
		cout << "Введите число: ";
		cin >> *(arr + count++);
		cout << "Продолжить? (y/n) ";
		cin >> a;
	} while (a != 'n');

	float summ = 0.0;
	for (int i = 0; i < count; i++)
	{
		summ += *(arr + i);
	}

	cout << "Среднее арифметическое равно - " << summ / count;
}
