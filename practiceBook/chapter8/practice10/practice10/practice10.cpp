﻿#include "pch.h"
#include <iostream>
#include <cmath>

using namespace std;

class Polar
{
private:
	double radius;
	double grad;
	double x;
	double y;

public:
	Polar() {};

	Polar(double r, double g) : radius(r), grad(g) {};

	void polToDec()
	{
		x = radius * cos(grad);
		y = radius * sin(grad);
	}
	
	void decToPol()
	{
		radius = sqrt(x * x + y * y);
		grad = atan(y / x);
	}

	void showPolar()
	{
		cout << "Radius - " << radius << endl;
		cout << "Grad - " << grad << endl;
	}

	Polar operator+ (Polar pol2)
	{
		Polar temp;
		polToDec();
		pol2.polToDec();
		temp.x = x + pol2.x;
		temp.y = y + pol2.y;
		temp.decToPol();
		return temp;
	}
};

int main()
{
	Polar pol1(5, 45);
	Polar pol2(15, 15);
	Polar pol3 = pol1 + pol2;
	pol3.showPolar();
}