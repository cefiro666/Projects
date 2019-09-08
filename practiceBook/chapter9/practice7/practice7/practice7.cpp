#include "pch.h"
// counten2.cpp
// конструкторы в производных классах
#include <iostream>
using namespace std;
///////////////////////////////////////////////////////////
class Counter
{
protected:                         // заметьте, что тут не следует использовать private
	unsigned int count;              // счетчик
public:
	Counter() : count(0)          // конструктор без параметров
	{ }
	Counter(int c) : count(c)  // конструктор с одним параметром
	{ }
	unsigned int get_count() const // получение значения
	{
		return count;
	}
	Counter operator++ ()           // оператор увеличения
	{
		return Counter(++count);
	}
};
///////////////////////////////////////////////////////////
class CountDn : public Counter
{
public:
	CountDn() : Counter()        // конструктор без параметров
	{ }
	CountDn(int c) : Counter(c)// конструктор с одним параметром
	{ }

	using Counter::operator++;

	CountDn operator-- ()           // оператор уменьшения
	{
		return CountDn(--count);
	}
	
	CountDn operator-- (int)           // оператор уменьшения
	{
		return CountDn(count--);
	}

	CountDn operator++ (int)           // оператор уменьшения
	{
		return CountDn(count++);
	}
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");
	CountDn c1;                            // переменные класса CountDn
	CountDn c2(100);

	cout << "\nc1 = " << c1.get_count(); // выводим значения на экран
	cout << "\nc2 = " << c2.get_count();

	++c1; ++c1; ++c1;                      // увеличиваем c1
	cout << "\nc1 = " << c1.get_count(); // показываем результат

	--c2; --c2;                            // уменьшаем c2
	cout << "c2 = " << c2.get_count();   // показываем результат

	CountDn c3 = --c2;                     // создаем переменную c3 на основе c2
	cout << "\nc3 = " << c3.get_count(); // показываем значение

	cout << endl;

	return 0;
}

