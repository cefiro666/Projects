#include "pch.h"
#include <iostream>	
#include <Windows.h>

using namespace std;

const char GRAD = '\xF8';

class Angle
{
private:
	int deg;
	float minute;
	char dir;

public:
	Angle(int deg, float minute, char dir) : deg(deg), minute(minute), dir(dir) {};
	void scowAngle() const
	{
		cout << "Point coordinate " << deg << GRAD << minute << "' " << dir << endl;
	}
	void setAngle()
	{
		cout << "Enter the angle, minute, and direction of the point through the gap... ";
		cin >> deg >> minute >> dir;
	}
};

int main()
{
	Angle ang1(140, 56.7, 'N');
	ang1.scowAngle();

	while (true)
	{
		ang1.setAngle();
		ang1.scowAngle();
	}
}