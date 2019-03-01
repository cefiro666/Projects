#include "pch.h"
#include "calculations.h"
#include "readings.h"
#include "function.h"
#include <string>
#include <iostream>	
#include <Windows.h>

using namespace std;

int main() {
	//установка параметров локали (только для windows)
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	cout << " ______________________________________________________________\n\n";
	cout << "      ПРОГРАММА РАССЧЕТА СТОИМОСТИ РАСХОДОВАННЫХ РЕСУРСОВ\n";
	cout << " ______________________________________________________________\n";
	cout << "\n      Обратите внимание! Программа расчитана на квартиры\n" << 
			"      с раздельными счетчиками горячей и холодной воды\n" << 
			"      для кухни и ванной. Если у вас всего два счетчика\n" << 
			"      воды - во всех полях, предназначенных для ввода\n" << 
			"      показаний в кухне вводите 0.\n";
	cout << " ______________________________________________________________\n\n";
	cout << " Сегодня " << get_present_date() << endl;
	//проверка присутствия файла данных. Если файл не найден - создание нового, с вводом всех данных прошлого периода
	check_file();
	//создание объекта класса для хранения данных прошлого периода (подробнее в объявлении класса)
	Readings post_readings;
	//создание объекта класса для хранения данных нынешнего периода (подробнее в объявлении класса)
	Calculations calc;
	//создание объекта класса для вычисления и хранения итоговых показателей (подробнее в объявлении класса)
	Readings present_readings;
	//чтение данных прошлого периода из файла (тарифы, дата, показания)
	post_readings.read(get_path());
	cout << "\n Установленные тарифы:\n";
	cout << setw(30) << left << " -горячая вода " << setw(10)   << right << post_readings.get_hot_water_tariff() << " руб. за кубометр\n";
	cout << setw(30) << left << " -холодная вода " << setw(10)  << right << post_readings.get_cold_water_tariff() << " руб. за кубометр\n";
	cout << setw(30) << left << " -электроэнергия " << setw(10) << right << post_readings.get_electricity_tariff() << " руб. за киловатт/час\n";
	cout << setw(30) << left << " -водоотведение " << setw(10)  << right << post_readings.get_drainage_tariff() << " руб. за кубометр\n\n";
	//установка новых тарифов, либо перезапись старых
	set_tariff(present_readings, post_readings, calc);
	cout << " ______________________________________________________________\n\n";
	cout << " Информация о прошлом отчетном периоде\n\n";
	cout << " Дата снятия показаний: " << post_readings.get_date() << endl << endl;
	cout << " Показания счетчиков: " << endl;
	cout << setw(30) << left << " -горячей воды в ванной: "   << setw(10) << right << post_readings.get_readings(0) << " кубометр\n";
	cout << setw(30) << left << " -холодной воды в ванной: "  << setw(10) << right << post_readings.get_readings(1) << " кубометр\n";
	cout << setw(30) << left << " -горячей воды в кухне: "    << setw(10) << right << post_readings.get_readings(2) << " кубометр\n";
	cout << setw(30) << left << " -холодной воды в кухне: "   << setw(10) << right << post_readings.get_readings(3) << " кубометр\n";
	cout << setw(30) << left << " -электроэнергии: "          << setw(10) << right << post_readings.get_readings(4) << " киловатт/час\n";
	cout << " ______________________________________________________________\n\n";
	//ввод нынешних данных
	fill_present_readings(present_readings);
	//рассчет итоговых показателей стоимости, расхода и др.
	calc.calculation(present_readings, post_readings);
	cout << " ______________________________________________________________\n\n";
	cout << " Итоговые данные за отчетный период с " << post_readings.get_date() << " по " << present_readings.get_date() << endl;
	cout << " ______________________________________________________________\n\n";
	cout << " Расход ресурсов:\n";
	cout << setw(30) << left << " -горячей воды в ванной "  << setw(10) << right << fixed << setprecision(3) << calc.get_expenditure(0) << " кубометр\n";
	cout << setw(30) << left << " -холодной воды в ванной " << setw(10) << right << fixed << setprecision(3) << calc.get_expenditure(1) << " кубометр\n";
	cout << setw(30) << left << " -горячей воды в кухне "   << setw(10) << right << fixed << setprecision(3) << calc.get_expenditure(2) << " кубометр\n";
	cout << setw(30) << left << " -холодной воды в кухне "  << setw(10) << right << fixed << setprecision(3) << calc.get_expenditure(3) << " кубометр\n";
	cout << setw(30) << left << " -электроэнергии "         << setw(10) << right << fixed << setprecision(1) << calc.get_expenditure(4) << " киловатт/час\n\n";
	cout << " Стоимость ресурсов:\n";
	cout << setw(30) << left << " -горячей воды в ванной "      << setw(10) << right << fixed << setprecision(2) << calc.get_cost(0) << " руб.\n";
	cout << setw(30) << left << " -холодной воды в ванной "     << setw(10) << right << fixed << setprecision(2) << calc.get_cost(1) << " руб.\n";
	cout << setw(30) << left << " -горячей воды в кухне "       << setw(10) << right << fixed << setprecision(2) << calc.get_cost(2) << " руб.\n";
	cout << setw(30) << left << " -холодной воды в кухне "      << setw(10) << right << fixed << setprecision(2) << calc.get_cost(3) << " руб.\n";
	cout << setw(30) << left << " -электроэнергии "             << setw(10) << right << fixed << setprecision(2) << calc.get_cost(4) << " руб.\n";
	cout << setw(30) << left << " + плата за водоотведение "    << setw(10) << right << fixed << setprecision(2) << present_readings.get_drainage_tariff() * calc.get_sum_expenditure() << " руб.\n\n";
	cout << " Итого плата за коммунальные услуги составляет - " << fixed << setprecision(2) << calc.get_sum_cost() << " руб.\n";
	cout << " ______________________________________________________________\n\n";
	//запись нынешних данных в фаил
	present_readings.write(get_path());
	cout << " Спасибо за использование этой программы! Всего хорошего!\n\n";
	cout << " Нажмите ENTER для закрытия...";
	cin.get();
	cin.get();
}