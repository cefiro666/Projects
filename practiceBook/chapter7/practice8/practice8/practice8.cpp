#include "pch.h"
#include <iostream>

using namespace std;

const int LIMIT = 100;

class SafeAray
{
private:
	int arr[LIMIT];

public:
	void putEl(int index, int value)
	{
		if (index >= 0 && index <= LIMIT - 1)
		{
			arr[index] = value;
		} else {
			cout << "Array overflow!";
		}
	}

	int getEl(int index)
	{
		if (index >= 0 && index <= LIMIT - 1)
		{
			return arr[index];
		} else {
			cout << "Array overflow!";
		}
	}
};

int main()
{
	SafeAray arr;
	arr.putEl(0, 123);
	arr.putEl(122, 34);
	int temp = arr.getEl(0);
	cout << temp;
}