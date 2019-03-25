#include "pch.h"
#include "Test.h"

using namespace std;

void overheating_time(Engine& engine)
{
	cout << "\n -Запущен тест на перегрев...\n";

	// запуск двигателя
	engine.start();

	// пока работает двигатель
	while (engine.condition)
	{
		// если двигатель перегрелся
		if (engine.engine_temp >= engine.temp_overheat)
		{
			engine.stop();
			cout << "\n Двигатель проработал " << fixed << setprecision(1)
				<< engine.engine_time << " сек и перегрелся\n";
		}
		// если достигнута максимальная скорость вращения вала
		if (engine.rotat_speed >= (engine.rotat_speed_arr[5] - 0.02))
		{
			engine.stop();
			cout << "\n Двигатель проработал "
				<< fixed << setprecision(1) << engine.engine_time
				<< " сек и достиг максимальной\n скорости вращения вала\n";
		}
	}
	// критичиские данные во время остановки
	cout << "\n Температура двигателя в момент остановки: " << fixed
		<< setprecision(1) << engine.engine_temp << " градусов\n";

	cout << " Скорость вращения вала в момент остановки: " << fixed
		<< setprecision(1) << engine.rotat_speed << " радиан/сек\n";
}