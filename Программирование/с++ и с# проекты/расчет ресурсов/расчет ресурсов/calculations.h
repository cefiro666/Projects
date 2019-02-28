//объявление класса Calculations, определение переменных и прототипов методов
//информация о назначении методов в объявлении класса
#pragma once
#include <string>
#include <iostream>	

using namespace std;

//объявление класса Readings для корректной работы методов
class Readings;
//класс производит рассчеты и хранит значения расходов, 
//тарифов и стоимости по каждому из счетчиков
class Calculations {

private:
	// многомерный массив с значениями (расход/тариф/стоимость)
	//[0,0] - расход по горячей воде в ванной
	//[0,1] - расход по холодной воде в ванной
	//[0,2] - расход по горячей воде в кухне
	//[0,3] - расход по холодной воде в кухне
	//[0,4] - расход по электричеству
	//[1,0],[1,2] - тариф на горячую воду
	//[1,1],[1,3] - тариф на холодную воду
	//[1,4] - тариф на электричество
	//[2,0] - стоимость горячей воды в ванной
	//[2,1] - стоимость холодной воды в ванной
	//[2,2] - стоимость горячей воды в кухне
	//[2,3] - стоимость холодной воды в кухне
	//[2,4] - стоимость электроэнергии
	float Arr_calculations[3][5]; 
	//итоговая стоимость за услуги
	float sum_cost; 
	//итоговый расход воды
	float sum_expenditure; 

public:
	//возврат и установка итоговой стоимости
	float get_sum_cost();
	void set_sum_cost(float value);
	//возврат и установка итогового расхода
	float get_sum_expenditure();
	void set_sum_expenditure(float value);
	//возврат и установка значения расхода
	float get_expenditure(int i);
	void set_expenditure(int i, float value);
	//возврат и установка стоимости ресурсов по одному показателю
	float get_cost(int i);
	void set_cost(int i, float value);
	//рассчет расхода и стоимости ресурсов
	void calculation(Readings &present_readings, Readings &post_readings);
	//дружественная функция
	friend void set_tariff(Readings &present_readings, Readings &post_readings, Calculations &calc);
};