#pragma once
#include <map>

class Engine
{
public:
	virtual void step() = 0;

	// коэффициент зависимости скорости нагрева от 
	// крутящего момента
	double cMoment;

	// коэффициент зависимости скорости нагрева от 
	// скорости вращения коленвала
	double cRotatSpeed;

	// коэффициент зависимости скорости охлаждения 
	// от температуры двигателя и окружающей среды
	double cTemp;

	// температура окружающей среды
	double mediumTemp;

	// скорость вращения вала
	double rotatSpeed;

	// момент инерции двигателя
	double Inert;

	// температура перегрева двигателя
	double tempOverheat;

	// скорость нагрева охл. жидкости
	double heatRate;

	// скорость охлаждения охл. жидкости
	double coolRate;

	// зависимость крутящего момента от скорости
	// вращения вала
	std::map<double, double> addiction;
	std::map<double, double> ::iterator i, j;

	// крутящий момент
	double M;

	// ускорение вращения вала
	double a;

	// температура двигателя
	double engineTemp;

	// время работы двигателя
	double engineTime;
};

