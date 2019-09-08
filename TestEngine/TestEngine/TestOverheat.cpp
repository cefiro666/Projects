#include "TestOverheat.h"
#include <iostream>
#include <iomanip>

TestOverheat::TestOverheat(double mediumTemp) : mediumTemp(mediumTemp) {}

void TestOverheat::startTest(Engine* engine)
{
	std::cout << " \n ���� �� ��������...\n\n";

	engine->engineTemp = engine->mediumTemp = mediumTemp;

	double maxSpeed = engine->addiction.rbegin()->first - 0.01;
	
	while (engine->engineTemp < engine->overheatTemp)
	{
		engine->stepSimulation();

		if (engine->rotatSpeed >= maxSpeed)
		{
			std::cout << " - ���������� ������������ �������� �������� ����!\n"
				"   ���� ����������.\n\n";
			break;
		}
	}
	
	std::cout << std::setiosflags(std::ios::fixed) << std::setprecision(1);
	std::cout << " - ��������� ���������� " << engine->engineTime << " ������\n";
	std::cout << " - ����������� ��������� � ������ ��������� - " << 
		engine->engineTemp << " ��������\n";
	std::cout << " - �������� �������� ���� ��������� � ������ ��������� - " <<
		engine->rotatSpeed << " ����/���\n\n";
}