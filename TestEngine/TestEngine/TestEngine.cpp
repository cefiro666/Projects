#include <iostream>
#include "Stand.h"
#include "InterСombEngine.h"
#include "TestOverheat.h"

int main()
{
	// коэффициент зависимости скорости нагрева от 
	// крутящего момента
	double cMoment = 0.01;

	// коэффициент зависимости скорости нагрева от 
	// скорости вращения коленвала
	double cRotatSpeed = 0.0001;

	// коэффициент зависимости скорости охлаждения 
	// от температуры двигателя и окружающей среды
	double cTemp = 0.1;

	// момент инерции двигателя
	double Inert = 10;

	// температура перегрева двигателя
	double tempOverheat = 110;

	// зависимость крутящего момента от скорости
	// вращения вала
	std::map<double, double> addiction = { {0, 20}, {75, 75}, {150, 100},
		{200, 105}, {250, 75}, {300, 0} };

	Engine* interСombEngine = new InterСombEngine(cMoment, cRotatSpeed,
		cTemp, Inert, tempOverheat, addiction);

	double T;
	std::cout << "Input T";
	std::cin >> T;

	Test* testOverhead = new TestOverheat(T);
	Stand stand(interСombEngine);
	stand.startTest(testOverhead);
}