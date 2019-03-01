//вспомогательные функции
#pragma once
#include "calculations.h"
#include "readings.h"
#include <string>
#include <iostream>	
#include <time.h>
#include <lmcons.h>
#include <Windows.h>

using namespace std;

//возвращает имя текущего пользователя в системе
string get_username() {
	char buffer[UNLEN + 1];
	DWORD size;
	size = sizeof(buffer);
	GetUserNameA(buffer, &size);
	string username = buffer;
	return username;
}
//возвращает установленный путь файла данных
string get_path() {
	string path = "C:/Users/" + get_username() + "/Documents/datacalc.txt";
	return path;
}
//проверка присутствия файла данных и создание нового файла 
void check_file() {
	//создание файлового потока на чтение
	ifstream in(get_path(), ios_base::in);
	//если не открылся файл
	if (!in.is_open()) {
		cout << "\n Похоже, что это первый запуск программы (либо не найден файл данных).\n Необходимо создать новый файл данных.\n\n";
		//переменные для записи всех данных в новый файл
		string date;
		float cold_tariff, hot_tariff, drainage_tariff, electricity_tariff, readings_cold_bathroom, readings_hot_bathroom, readings_cold_kitchen, readings_hot_kitchen, readings_electricity;
		bool true_in = false;
		int value;
		//цикл для повторного ввода переменных в случае ошибки
		while (!true_in) {
			bool true_in_value = false;
			cout << " Введите дату прошлого отчетного периода (xx.yy.zzzz xx - число, yy - месяц, zzzz - год): ";
			cin >> date;
			cout << " Введите цену за кубометр горячей воды: ";
			cin >> hot_tariff;
			cout << " Введите цену за кубометр холодной воды: ";
			cin >> cold_tariff;
			cout << " Введите цену за кубометр отведенной воды: ";
			cin >> drainage_tariff;
			cout << " Введите цену за киловатт/час электроэнергии: ";
			cin >> electricity_tariff;
			cout << " Введите показания счетчика горячей воды в ванной: ";
			cin >> readings_hot_bathroom;
			cout << " Введите показания счетчика холодной воды ванной: ";
			cin >> readings_cold_bathroom;
			cout << " Введите показания горячей воды на кухне: ";
			cin >> readings_hot_kitchen;
			cout << " Введите показания холодной воды на кухне: ";
			cin >> readings_cold_kitchen;
			cout << " Введите показания электросчетчика: ";
			cin >> readings_electricity;
			cout << "\n Введенные данные верны?\n Да (1)/ Нет (2)\n Ваш выбор... ";
			//цикл для проверки корректности выбора
			while (!true_in_value) {
				cin >> value;
				if (char(value) == 1) {
					//создание файлового потока на запись нового файла
					ofstream new_file(get_path());
					//если файл создался
					if (new_file.is_open()) {
						//запись тарифов, даты и показаний в новый фаил
						new_file << hot_tariff << " " << cold_tariff << " " << electricity_tariff << " " << drainage_tariff << "\n" << date << "\n" << readings_hot_bathroom << "\n" << readings_cold_bathroom << "\n" << readings_hot_kitchen << "\n" << readings_cold_kitchen << "\n" << readings_electricity;
						new_file.close();
						cout << "\n Файл данных успешно создан!\n";
						//выход из циклов
						true_in = true;
						true_in_value = true;
					} else {
						cout << "\n Ошибка создания файла. Возможно диск защищен от записи.\n Попробуйте отключить защиту от программ-шпионов в настройках windows.\n";
					}
				} else if (char(value) == 2) {
					cout << "\n Тогда повторите ввод данных...\n";
					//выход из цикла проверки ввода
					true_in_value = true;
				} else {
					cout << " Неверный ввод. Повторите... ";
				}
			}
		}
	}
}
//возвращает текущую дату в формате dd.mm.yyyy
const string get_present_date() {
#pragma warning(disable: 4996)
	time_t now = time(0);
	struct tm tstruct;
	char buf[11];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d.%m.%Y", &tstruct);
	return buf;
}
//воод и запись в массив нынешних показаний счетчиков и даты
void fill_present_readings(Readings &present_readings) {
	cout << " Введите данные счетчиков на сегодняшний день:\n";
	float value;
	string question[5] = { " -горячей воды в ванной: ",
							" -холодной воды в ванной: ",
							" -горячей воды в кухне: ",
							" -холодной воды в кухне: ",
							" -электросчетчика: " };
	for (int i = 0; i < 5; i++) {
		cout << question[i];
		cin >> value;
		present_readings.set_readings(i, value);
	}
	//запись нынешней даты в массив
	present_readings.set_date(get_present_date()); 
}
//функция изменения тарифов
void set_tariff(Readings &present_readings, Readings &post_readings, Calculations &calc) {
	cout << " Есть ли необходимость изменить тарифы?\n Да, изменить (1) / Продолжить без изменения (2)\n Ваш выбор... ";
	int value;
	bool true_in = false;
	//цикл для корректного ввода
	while (!true_in) {
		cin >> value;
		switch (char(value)) {
		case 1:
			float value;
			cout << "\n Хорошо. Давайте установим новые тарифы:\n";
			cout << " -за 1 кубометр горячей воды (руб.): ";
			cin >> value;
			present_readings.set_hot_water_tariff(value);
			cout << " -за 1 кубометр холодной воды (руб.): ";
			cin >> value;
			present_readings.set_cold_water_tariff(value);
			cout << " -за 1 киловатт/час электроэнергии (руб.): ";
			cin >> value;
			present_readings.set_electricity_tariff(value);
			cout << " -за 1 кубометр отведенной воды (руб.): ";
			cin >> value;
			present_readings.set_drainage_tariff(value);
			//установка нулевых значений переменных для рассчетов
			calc.set_sum_cost(0);
			calc.set_sum_expenditure(0);
			//выход из цикла
			true_in = true;
			break;
		case 2:
			//перезапись переменных, содержащих тарифы старыми данными(из файла)
			present_readings.set_hot_water_tariff(post_readings.get_hot_water_tariff());
			present_readings.set_cold_water_tariff(post_readings.get_cold_water_tariff());
			present_readings.set_drainage_tariff(post_readings.get_drainage_tariff());
			present_readings.set_electricity_tariff(post_readings.get_electricity_tariff());
			//установка нулевых значений переменных для рассчетов
			calc.set_sum_cost(0);
			calc.set_sum_expenditure(0);
			//выход из цикла
			true_in = true;
			break;
		default:
			cout << " Неверный ввод. Повторите... ";
			break;
		}
	}
}