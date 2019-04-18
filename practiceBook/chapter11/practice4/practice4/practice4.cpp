// clarray.cpp
// создает класс-массив
#include <iostream>

using namespace std;
///////////////////////////////////////////////////////////
class Array                  //моделирует обычный массив C++ 
{
private:
	int* ptr;                //указатель на содержимое Array
	int size;                //размер Array
public:

	Array(int s)             //конструктор с одним аргументом
	{
		size = s;              //аргумент – размер Array 
		ptr = new int[s];      //выделить память под Array 
	}

	Array(Array& arr)             //конструктор с одним аргументом
	{
		size = arr.size;              //аргумент – размер Array 
		ptr = new int[size];      //выделить память под Array 
	}

	~Array()                 //деструктор
	{
		delete[] ptr;
	}

	int& operator [] (int j)
	{
		return *(ptr + j);
	}

	Array& operator = (Array& arr)
	{
		size = arr.size;              //аргумент – размер Array 
		ptr = new int[size];      //выделить память под Array 
		return *this;
	}
};
///////////////////////////////////////////////////////////
int main()
{
	const int ASIZE = 10;      //размер массива
	Array arr1(ASIZE);          //создать массив

	for (int j = 0; j < ASIZE; j++) //заполнить его j^2
		arr1[j] = j * j;

	for (int j = 0; j < ASIZE; j++)     //вывести его содержимое
		cout << arr1[j] << ' ';
	cout << endl;
	Array arr2(arr1);
	for (int j = 0; j < ASIZE; j++) //заполнить его j^2
		arr2[j] = j * j;

	for (int j = 0; j < ASIZE; j++)     //вывести его содержимое
		cout << arr2[j] << ' ';
	cout << endl;

	Array arr3(ASIZE);
	arr3 = arr1;
	for (int j = 0; j < ASIZE; j++) //заполнить его j^2
		arr3[j] = j * j;

	for (int j = 0; j < ASIZE; j++)     //вывести его содержимое
		cout << arr3[j] << ' ';
	cout << endl;
	return 0;
}


