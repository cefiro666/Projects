#include "pch.h"
#include "Test.h"

using namespace std;

float overheating_time(Engine& engine)
{
	cout << "\n -Запущен тест на перегрев...\n";
	// запуск двигателя
	engine.start();
	// пока работает двигатель
	while (engine.condition)
	{
		// если перегрев или развита максимальная 
		// скорость - остановить двигатель
		if (engine.engine_temp >= engine.temp_overheat
			|| engine.rotat_speed >= (engine.rotat_speed_arr[5] - 0.02))
		{
			engine.stop();
		}
	}
	// вернуть время работы двигателя
	return engine.engine_time;
}