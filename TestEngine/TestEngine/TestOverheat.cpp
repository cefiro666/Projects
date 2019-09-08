#include "TestOverheat.h"
#include <iostream>
#include <iomanip>

TestOverheat::TestOverheat(double mediumTemp) : mediumTemp(mediumTemp) {}

void TestOverheat::startTest(Engine* engine)
{
	std::cout << " \n Тест на перегрев...\n\n";

	engine->engineTemp = engine->mediumTemp = mediumTemp;

	double maxSpeed = engine->addiction.rbegin()->first - 0.01;
	
	while (engine->engineTemp < engine->overheatTemp)
	{
		engine->stepSimulation();

		if (engine->rotatSpeed >= maxSpeed)
		{
			std::cout << " - Достигнута максимальная скорость вращения вала!\n"
				"   Тест остановлен.\n\n";
			break;
		}
	}
	
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
	std::cout << " - Двигатель проработал " << engine->engineTime << " секунд\n";
	std::cout << " - Температура двигателя в момент остановки - " << 
		engine->engineTemp << " градусов\n";
	std::cout << " - Скорость вращения вала двигателя в момент остановки - " <<
		engine->rotatSpeed << " град/сек\n\n";
}