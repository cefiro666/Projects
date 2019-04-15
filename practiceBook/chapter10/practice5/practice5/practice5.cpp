#include "pch.h"
#include <iostream>

using namespace std;

const int LEN = 5;

int main()
{
	void addarrays(int*, int*, int*, int);

	int arr1[LEN] = { 4,6,2,7,8 };
	int arr2[LEN] = { 8,7,4,8,3 };
	int arr3[LEN];

	addarrays(arr1, arr2, arr3, LEN);

	for (int i = 0; i < LEN; i++)
	{
		cout << *(arr3 + i) << endl;
	}
}

void addarrays(int* arr1, int* arr2, int* arr3, int len)
{
	for (int i = 0; i < len; i++)
	{
		*(arr3 + i) = *(arr1 + i) + *(arr2 + i);
	}
}