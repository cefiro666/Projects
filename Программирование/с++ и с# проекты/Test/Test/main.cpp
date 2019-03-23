#include "pch.h"
#include <iostream>
#include <iomanip>
#include "Test.h"
#include "Engine.h"
#include <Windows.h>

using namespace std;

int main()
{
	//установка параметров локали (только для windows)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << "\n	Программа тестирования\n";
	cout << " =====================================\n\n";

	cout << " Введите температуру окружающей\n среды (в градусах цельсия): ";
	float temp;
	cin >> temp;
	// создаем двигатель
	Engine int_comb_engine;

	// Вводные данные
	// ======================================================
	// установка типа двигателя (внутр. сгорания)
	int_comb_engine.type = 1;

	// коэффициент зависимости скорости нагрева от крутящего момента
	int_comb_engine.coef_M = 0.01F;

	// коэффициент зависимости скорости нагрева от скорости 
	// вращения коленвала
	int_comb_engine.coef_rotat_speed = 0.0001F;

	// коэффициент зависимости скорости охлаждения от температуры 
	// двигателя и окружающей среды
	int_comb_engine.C = 0.1F;

	// начальная скорость вращения вала
	int_comb_engine.rotat_speed = 0;

	// установка времени на ноль
	int_comb_engine.engine_time = 0;

	// момент инерции двигателя
	int_comb_engine.I = 10;

	// температура перегрева двигателя
	int_comb_engine.temp_overheat = 110;

	// зависимость крутящего момента от скорости вращения вала
	// (при добавлении или удалении точек зависимости необходимо
	// исправить код в классе Engine(изменить массив и рассчет М))
	int_comb_engine.M_arr =           { 20, 75, 100, 105,  75,  0 };
	int_comb_engine.rotat_speed_arr = { 0, 75, 150, 200, 250, 300 };

	// ======================================================

	// запуск теста
	// ======================================================
	float time = overheating_time(temp, int_comb_engine);
	// по какой причине остановка двигателя
	if (int_comb_engine.engine_temp >= int_comb_engine.temp_overheat)
	{
		cout << "\n Двигатель проработал " << fixed << setprecision(1)
			<< time << " сек и перегрелся\n";
	}
	else {
		cout << "\n Двигатель проработал " << fixed << setprecision(1)
			<< time << " сек и достиг максимальной\n скорости вращения вала\n";
	}

	// критичиские данные
	cout << " Температура двигателя в момент остановки " << fixed
		<< setprecision(1) << int_comb_engine.engine_temp << " градусов\n";

	cout << " Скорость вращения вала в момент остановки " << fixed
		<< setprecision(1) << int_comb_engine.rotat_speed << " м/сек\n";

	cout << "\n Работа программы завершена. Нажмите Enter для выхода...";
	cin.get();
	cin.get();
}
