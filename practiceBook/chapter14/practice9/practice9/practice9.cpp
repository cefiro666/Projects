// arrover1.cpp
// демонстрация создания безопасного массива, проверяющего
// свои индексы при использовании
// используются отдельные функции для установки и получения значения
#include <iostream>
using namespace std;
#include <process.h>    // для функции exit
const int LIMIT = 10;  // размер массива
///////////////////////////////////////////////////////////
class safearray
{
private:
	int arr[LIMIT];
public:
	class exeption
	{
	public:
		exeption(int i) : index(i) {}

		int index;
	};
	// установка значения элемента массива
	void putel(int n, int elvalue)
	{
		if (n < 0 || n >= LIMIT)
		{
			throw exeption(n);
		}
		arr[n] = elvalue;
	}
	// получение значения элемента массива
	int getel(int n) const
	{
		if (n < 0 || n >= LIMIT)
		{
			throw exeption(n);
		}
		return arr[n];
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");

	try {
		safearray sa1;

		// задаем значения элементов
		for (int j = 0; j < LIMIT; j++)
			sa1.putel(j, j * 10);

		// показываем элементы
		for (int j = 0; j < LIMIT + 1; j++)
		{
			int temp = sa1.getel(j);
			cout << "Элемент " << j << " равен " << temp << endl;
		}
	}
	catch (safearray::exeption ex) {
		cout << "Error! Index - " << ex.index << endl;
	}


	return 0;
}


