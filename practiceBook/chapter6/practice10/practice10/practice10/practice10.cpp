#include "pch.h"
#include <iostream>


using namespace std;

const char GRAD = '\xF8';

class Angle
{
private:
	int deg;
	float minute;
	char dir;

public:
	Angle() {};
	Angle(int deg, float minute, char dir) : deg(deg), minute(minute), dir(dir) {};
	void showAngle() const
	{
		cout << deg << GRAD << minute << "' " << dir << endl;
	}
	void setAngle()
	{
		cin >> deg >> minute >> dir;
	}
};

class Ship
{
private:
	static int count;
	int number;
	Angle latitude;
	Angle longitude;

public:
	Ship()
	{
		count++;
		number = count;
	};

	void setShip()
	{
		cout << "Input coordinate for Ship " << number << "..." << endl;
		cout << "Input latitude (angle, minute, and direction of the point through the gap)... ";
		latitude.setAngle();
		cout << "Input longtitude (angle, minute, and direction of the point through the gap)... ";
		longitude.setAngle();
	}

	void showShip() const
	{
		cout << "Ship " << number << endl;
		cout << "Input latitude ";
		latitude.showAngle();
		cout << "Input longtitude ";
		longitude.showAngle();
	}
};

int Ship::count = 0;

int main()
{
	Ship sh1, sh2, sh3;

	sh1.setShip();
	sh2.setShip();
	sh3.setShip();

	sh1.showShip();
	sh2.showShip();
	sh3.showShip();
}