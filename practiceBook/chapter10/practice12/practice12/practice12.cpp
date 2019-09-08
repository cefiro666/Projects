﻿#include "pch.h"
#include <iostream>

using namespace std;

float fMemory[100];
int pMemory[100];

class Float
{
private:
	int _addr;
	static int _fMemTop;

public:	
	Float(float value) 
	{
		_addr = _fMemTop;
		fMemory[_fMemTop++] = value;
	}

	int operator& ()
	{
		return _addr;
	}
};

class PtrFloat
{
private:
	int _addr;
	static int _pMemTop;

	
public:
	PtrFloat(int addres)
	{
		_addr = _pMemTop;
		pMemory[_pMemTop++] = addres;
	}

	float& operator* ()
	{
		return fMemory[pMemory[_addr]];
	}

	friend ostream& operator<< (ostream& out, const PtrFloat& ptr);
};

ostream& operator<< (ostream& out, const PtrFloat& ptr)
{
	out << pMemory[ptr._addr];
	return out;
}

int Float::fMemTop = 0;
int PtrFloat::pMemTop = 0;

int main()
{
	Float var1 = 1.234F;           // определяем и инициализируем
	Float var2 = 5.678F;           // две вещественные переменные

	PtrFloat ptr1 = &var1;        // определяем и инициализируем
	PtrFloat ptr2 = &var2;        // два указателя

	cout << " ptr1 = " << ptr1 << endl; // получаем значения переменных
	cout << " ptr2 = " << ptr2 << endl; // и выводим на экран

	cout << " *ptr1 = " << *ptr1 << endl; // получаем значения переменных
	cout << " *ptr2 = " << *ptr2 << endl; // и выводим на экран

	*ptr1 = 7.123F;                // присваиваем новые значения
	*ptr2 = 8.456F;                // переменным, адресованным через указатели

	cout << " *ptr1 = " << *ptr1 << endl; // снова получаем значения
	cout << " *ptr2 = " << *ptr2 << endl; // и выводим на экран

}