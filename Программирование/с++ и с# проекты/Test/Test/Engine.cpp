#include "pch.h"
#include "Engine.h"

void Engine::start()
{
	condition = true;
	// ������ ��������� � ����������� �� ���� ���������
	switch (type)
	{
		case 1:
			cout << " ��� ������������ ��������� - ���\n";
			thread simulation(&Engine::int_comb_simulation, this);
			simulation.detach();
			break;
	}
}

void Engine::stop() { condition = false; }

void Engine::int_comb_simulation()
{
	// ���� ��������� ��������
	while (condition)
	{	
		// ������ ��������� ������� � ����������� �� ������� ��������
		// � ������� �����������
		if ((rotat_speed_arr[0] <= rotat_speed)
			&& (rotat_speed <= rotat_speed_arr[1]))
		{
			M = rotat_speed * (M_arr[1] - M_arr[0])
				/ (rotat_speed_arr[1] - rotat_speed_arr[0])
				+ M_arr[1] - (M_arr[0] - M_arr[0])
				/ (rotat_speed_arr[1] - rotat_speed_arr[0])
				* rotat_speed_arr[1];
		}

		if ((rotat_speed_arr[1] <= rotat_speed)
			&& (rotat_speed <= rotat_speed_arr[2]))
		{
			M = rotat_speed * (M_arr[2] - M_arr[1])
				/ (rotat_speed_arr[2] - rotat_speed_arr[1])
				+ M_arr[2] - (M_arr[2] - M_arr[1])
				/ (rotat_speed_arr[2] - rotat_speed_arr[1])
				* rotat_speed_arr[2];
		}

		if ((rotat_speed_arr[2] <= rotat_speed)
			&& (rotat_speed <= rotat_speed_arr[3]))
		{
			M = rotat_speed * (M_arr[3] - M_arr[2])
				/ (rotat_speed_arr[3] - rotat_speed_arr[2])
				+ M_arr[3] - (M_arr[3] - M_arr[2])
				/ (rotat_speed_arr[3] - rotat_speed_arr[2])
				* rotat_speed_arr[3];
		}

		if ((rotat_speed_arr[3] <= rotat_speed)
			&& (rotat_speed <= rotat_speed_arr[4]))
		{
			M = rotat_speed * (M_arr[4] - M_arr[3])
				/ (rotat_speed_arr[4] - rotat_speed_arr[3])
				+ M_arr[4] - (M_arr[4] - M_arr[3])
				/ (rotat_speed_arr[4] - rotat_speed_arr[3])
				* rotat_speed_arr[4];
		}

		if ((rotat_speed_arr[4] <= rotat_speed)
			&& (rotat_speed <= rotat_speed_arr[5]))
		{
			M = rotat_speed * (M_arr[5] - M_arr[4])
				/ (rotat_speed_arr[5] - rotat_speed_arr[4])
				+ M_arr[5] - (M_arr[5] - M_arr[4])
				/ (rotat_speed_arr[5] - rotat_speed_arr[4])
				* rotat_speed_arr[5];
		}
		// ������ ����������
		a = M / I;
		heat_rate = M * coef_M + rotat_speed * rotat_speed * coef_rotat_speed;
		cool_rate = C * (medium_temp - engine_temp);
		engine_temp += heat_rate + cool_rate;
		// ����� ������� ���������� �� ���� �������� - 0.01 �������
		rotat_speed += a / 100;
		engine_time += 0.01F;
	}
}