#include "pch.h"
#include <iostream>

using namespace std;

class SafeAray
{
private:
	static const int X = 10;
	static const int Y = 10;
	int arr[X][Y];

public:
	SafeAray(int x, int y)
	{
		arr[x][y];
	}

	void putEl(int x, int y, int value)
	{
		if (x >= 0 && x <= X - 1 && y >= 0 && y <= Y - 1)
		{
			arr[x][y] = value;
		}
		else {
			cout << "Array overflow!";
		}
	}

	int getEl(int x, int y)
	{
		if (x >= 0 && x <= X - 1 && y >= 0 && y <= Y - 1)
		{
			return arr[x][y];
		}
		else {
			cout << "Array overflow!";
		}
	}
};

int main()
{
	SafeAray arr(5,6);
	arr.putEl(0, 5, 123);
	arr.putEl(6, 4, 34);
	int temp = arr.getEl(0,5);
	cout << temp;
	temp = arr.getEl(8, 5);
	cout << temp;
}