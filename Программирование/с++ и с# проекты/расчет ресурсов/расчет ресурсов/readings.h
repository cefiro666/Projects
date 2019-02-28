//объ€вление класса Readings, определение переменных и прототипов методов
#pragma once
#include "calculations.h"
#include <string>
#include <iostream>	
#include <fstream>
#include <iomanip>

using namespace std;

//класс дл€ хранени€ показаний счетчиков и дат, и тарифов
class Readings {

private:
	//хранит дату отчетного дн€
	string date; 
	// массив дл€ хранени€ показаний счетчика: 
	//[0]-гор€ча€ ванна,											
	//[1]-холодна€ ванна, 																
	//[2]-гор€ча€ кухн€, 																
	//[3]-холодна€ кухн€, 																
	//[4]-энерги€
	float Arr_readings[5];
	//тариф водоотведени€
	float drainage_tariff;
	//тариф на холодную воду
	float cold_water_tariff;
	//тариф на гор€чую воду
	float hot_water_tariff;
	//тариф электроэнергию
	float electricity_tariff;

public:	
	//возврат, установка и печать даты
	string get_date();
	void set_date(string date);	
	void print_date();
	//возврат и установка значений тарифов
	float get_drainage_tariff();
	void set_drainage_tariff(float value);
	float get_cold_water_tariff();
	void set_cold_water_tariff(float value);
	float get_hot_water_tariff();
	void set_hot_water_tariff(float value);
	float get_electricity_tariff();
	void set_electricity_tariff(float value);
	//возврат, установка и печать показани€
	float get_readings(int i); 
	void set_readings(int i, float value);
	void print_readings(int i);
	//запись новых данных и чтение старых (дата, показани€) из файла
	void write(string path);
	void read(string path);
	//дружественные функции и методы
	friend void fill_present_readings(Readings &present_readings);
	friend void Calculations::calculation(Readings &present_readings, Readings &post_readings);
	friend void set_tariff(Readings &present_readings, Readings &post_readings, Calculations &calc);
};