#include "pch.h"
#include <iostream>

using namespace std;

const int NUM = 10;
const int MAX = 10;

int main()
{
	int* ap[NUM];

	for (int i = 0; i < NUM; i++)
	{
		*(ap + i) = new int[MAX];
	}

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
}