#include "pch.h"
#include "Test.h"

using namespace std;

float overheating_time(float temp, Engine& engine)
{
	cout << "\n ������� ���� �� ��������...\n";
	// ��������� ����������� ���������� �����
	engine.medium_temp = temp;
	// ������ ���������
	engine.start();
	// ���� �������� ���������
	while (engine.condition)
	{
		// ���� �������� ��� ������� ������������ �������� - ���������� ���������
		if (engine.engine_temp >= engine.temp_overheat
			|| engine.rotat_speed > (engine.rotat_speed_arr[5] - 1))
		{
			engine.stop();
		}
	}
	// ������� ����� ������ ���������
	return engine.engine_time;
}