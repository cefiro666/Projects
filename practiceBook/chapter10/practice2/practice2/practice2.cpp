#include "pch.h"
#include <iostream>

using namespace std;

class String
{
private:
	char* str; 

public:
	String(const char* s)  // конструктор с одним параметром
	{
		int length = strlen(s);     // вычисляем длину строки
		str = new char[length + 1]; // выделяем необходимую память
		strcpy_s(str, length + 1, s);             // копируем строку
	}

	~String()         // деструктор
	{
		cout << "Delete str\n";
		delete[] str; // освобождаем память
	}

	void display()    // покажем строку на экране
	{
		cout << str << endl;
	}

	void upit()
	{
		int length = strlen(str);
		for (int i = 0; i < length; i++)
		{
			*(str + i) = toupper(*(str + i));
		}
	}
};

int main()
{
	String str = "tyuetruyeru";
	str.upit();
	str.display();
}