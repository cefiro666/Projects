#include "pch.h"
#include <iostream>

using namespace std;

const int LIMIT = 100;    // размер массива
///////////////////////////////////////////////////////////
class safearray
{
protected:
	int arr[LIMIT];
public:
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

class Safehilo : public safearray
{
private:
	int low;
	int hi;

public:
	Safehilo()
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");
	safearray sa1;

	// задаем значения элементов
	for (int j = 0; j < LIMIT; j++)
		sa1[j] = j * 10;    // используем функцию слева от знака =

	  // показываем элементы
	for (int j = 0; j < LIMIT; j++)
	{
		int temp = sa1[j]; // используем функцию справа от знака =
		cout << "Элемент " << j << " равен " << temp << endl;
	}

	return 0;
}


