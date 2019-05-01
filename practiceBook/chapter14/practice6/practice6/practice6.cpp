// arrover3.cpp
// демонстрация создания безопасного массива, проверяющего
// свои индексы при использовании
// используется перегрузка операции [ ]
#include <iostream>
using namespace std;
#include <process.h>      // для функции exit
const int LIMIT = 100;    // размер массива
///////////////////////////////////////////////////////////
template <class T>
class safearray
{
private:
	T arr[LIMIT];
public:
	// обратите внимание, что функция возвращает ссылку!
	T& operator[ ] (int n)
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
	system("chcp 1251");

	safearray<int> sa1;

	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa1[j] = j * 10;    // используем функцию слева от знака =

	  // показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1[j]; // используем функцию справа от знака =
		cout << "Элемент " << j << " равен " << temp << endl;
	}

	safearray<float> sa2;

	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa2[j] = static_cast<float>(j) * 10.5F;    // используем функцию слева от знака =

	  // показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		float temp = sa2[j]; // используем функцию справа от знака =
		cout << "Элемент " << j << " равен " << temp << endl;
	}

	return 0;
}


