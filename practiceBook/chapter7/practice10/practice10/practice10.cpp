#include "pch.h"
#include <iostream>

using namespace std;

class Matrix
{
private:
	static const int X = 10;
	static const int Y = 10;
	int arr[X][Y];
	int xSize;
	int ySize;

public:
	Matrix(int x, int y)
	{
		xSize = x;
		ySize = y;

	}

	void putEl(int x, int y, int value)
	{
		if (x >= 0 && x <= xSize - 1 && y >= 0 && y <= ySize - 1)
		{
			arr[x][y] = value;
		} else {
			cout << "Array overflow!" << endl;
		}
	}

	void getEl(int x, int y)
	{
		if (x >= 0 && x <= xSize - 1 && y >= 0 && y <= ySize - 1)
		{
			cout << "Item - "<< arr[x][y] << endl;
		} else {
			cout << "Array overflow!" << endl;
		}
	}
};

int main()
{
	Matrix matrix(5,6);
	matrix.putEl(0, 5, 123);
	matrix.putEl(6, 4, 34);
	matrix.getEl(0,5);
	matrix.getEl(8, 5);
}