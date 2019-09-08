#include "pch.h"
#include <iostream>

using namespace std;

const int NUM = 10;
const int MAX = 10;

class Arr
{
private:
	int* ap[NUM];

public:
	Arr()
	{
		for (int i = 0; i < NUM; i++)
		{
			*(ap + i) = new int[MAX];
		}
	}

	int* operator[] (int i)
	{
		return *(ap + i);
	}

	void set(int index, int index2, int value)
	{
		*(*(ap + index) + index2) = value;
	}

	int get(int index, int index2)
	{
		return *(*(ap + index) + index2);
	}
};

int main()
{
	Arr arr;

	for (int i = 0; i < NUM; i++)
	{
		for (int k = 0; k < MAX; k++)
		{
			arr[i]
		}
	}


	/*

	for (int i = 0; i < 10; i++)
	{
		for (int k = 0; k < 10; k++)
		{
			*((*(ap + i)) + k) = k * 10;
		}
	}

	for (int i = 0; i < 10; i++)
	{
		cout << "a" << i << endl;
		for (int k = 0; k < 10; k++)
		{
			cout << *(*(ap + i) + k) << endl;
		}
		cout << endl;
	}
	/*/
	
}