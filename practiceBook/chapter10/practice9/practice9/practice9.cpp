#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int a0[10];
	int a1[10];
	int a2[10];
	int a3[10];
	int a4[10];
	int a5[10];
	int a6[10];
	int a7[10];
	int a8[10];
	int a9[10];

	int* ap[10] = {a0, a1, a2, a3, a4, a5, a6, a7, a8, a9};

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