#include "pch.h"
#include <iostream>

using namespace std;

class Class
{
private:
	static int count;
	int number;

public:
	Class() 
	{
		count++;
		number = count;
	}

	void showNumber() const
	{
		cout << "Object number - " << number << endl;
	}
};

int Class::count = 0;

int main()
{
	Class a, b, c;

	a.showNumber();
	b.showNumber();
	c.showNumber();
}