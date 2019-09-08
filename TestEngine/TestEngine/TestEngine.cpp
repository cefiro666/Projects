#include <iostream>
#include <Windows.h>
#include "Stand.h"
#include "InterСombEngine.h"
#include "TestOverheat.h"

int main()
{
	//установка параметров локали (только для windows)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	std::cout << "\n\t  Программа тестирования\n"
		" =========================================\n\n";

	double mediumTemp;
	std::cout << " Введите температуру окружающей среды: ";
	std::cin >> mediumTemp;

	// Входные данные для двигателя внутреннего сгорания
	//==========================================================

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
	double overheatTemp = 110;

	// зависимость крутящего момента от скорости
	// вращения вала (V, M)
	std::map<double, double> addiction = { {0, 20}, {75, 75}, {150, 100},
		{200, 105}, {250, 75}, {300, 0} };

	//==========================================================

	// создаем нужный двигатель с известными данными
	Engine* interСombEngine = new InterCombEngine(cMoment, cRotatSpeed,
		cTemp, Inert, overheatTemp, addiction);

	// создаем нужный тест с необходимым параметром
	Test* testOverhead = new TestOverheat(mediumTemp);

	// создаем стенд и грузим в него двигатель
	Stand stand(interСombEngine);

	// запускаем стенд с выбранным тестом
	stand.startStand(testOverhead);

	system("pause");
}