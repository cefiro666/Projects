#include "pch.h"
#include <iostream>

using namespace std;

int maxInt(int arr[100], int count)
{
	int max = arr[0];
	int maxIndex = 0;

	for (int i = 1; i < count; i++)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			maxIndex = i;
		}
	}
	return maxIndex;
}

int main()
{
	int arr[100];
	char a;
	int count = 0;

	for (int i = 0; i < 100; i++)
	{
		cout << "Enter an integer: "; 
		cin >> arr[count++];
		cout << "Repeat? y/n ";
		cin >> a;
		if (a == 'n') break;
	}

	int maxIndex = maxInt(arr, count);
	cout << "Maximum number - " << arr[maxIndex]
		<< ", his index - " << maxIndex;
}