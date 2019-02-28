//определения методов класса Readings
//информация о назначении методов в объявлении класса
#include "pch.h"
#include "readings.h"

float Readings::get_drainage_tariff() { return drainage_tariff; }
float Readings::get_cold_water_tariff() { return cold_water_tariff; }
float Readings::get_hot_water_tariff() { return hot_water_tariff; }
float Readings::get_electricity_tariff() { return electricity_tariff; }
float Readings::get_readings(int i) {return Arr_readings[i];}
string Readings::get_date() {return date;}
void Readings::set_readings(int i, float value) {Arr_readings[i] = value;}
void Readings::set_date(string date) {this->date = date;}
void Readings::set_drainage_tariff(float value) { drainage_tariff = value; }
void Readings::set_cold_water_tariff(float value) { cold_water_tariff = value;}
void Readings::set_hot_water_tariff(float value) { hot_water_tariff = value; }
void Readings::set_electricity_tariff(float value) { electricity_tariff = value; }
void Readings::print_date() {cout << " " << date << endl;}
void Readings::print_readings(int i) {
	int n;
	//проверка для форматирования при выводе последнего значения в массиве (один знак после запятой, для остальных три знака) 
	//сокращенная форма if/else 
	n = (i == 4) ? 1 : 3; 
	cout << " " << fixed << setprecision(n) << Arr_readings[i] << endl;
}
//запись показаний счетчиков и даты в фаил данных (нынешний период)
void Readings::write(string path) { 
	//создается строчный массив для чтения всего файла
	string buffer_in[256];
	//открытие файлового потока на чтение по пути path
	ifstream in(path, ios_base::in);
	//если файла открылся
	if (in.is_open()) {
		//установка указателя в начало
		in.seekg(0, ios_base::beg);
		for (int i = 0; i < 256; i++) {
			//считывание 256 строк из файла в массив
			getline(in, buffer_in[i], '\n');
		}
	} else {
		cout << "Ошибка открытия файла для записи!\n";
	}
	//закрыли поток
	in.close();
	//открытие файлового потока на запись (с затиранием содержимого при открытии)
	ofstream out(path, ios_base::trunc | ios_base::out);
	if (out.is_open()) {
		out.seekp(0, ios_base::beg);
		//запись в первую строку актуальных тарифов
		out << hot_water_tariff << " " << cold_water_tariff << " " << electricity_tariff << " " << drainage_tariff << "\n";
		//запись строк прошлого файла из буфера кроме первой строки (там хранятся ненужные прошлые тарифы)
		for (int i = 1; i < 256; i++) {
			//пропуск пустых строк
			if (!(buffer_in[i] == "")) {
				out << buffer_in[i] << "\n";
			}
		}
		//установка указателя в конец
		out.seekp(0, ios_base::end);
		//запись актуальной даты в одну строку
		out << date;
		//запись актуальных показателей счетчиков в отдельные строки
		for (int i = 0; i < 5; i++) {
			int n;
			//проверка для форматирования вывода последнего значения в массиве 
			//(один знак после запятой для показний электросчетчика, три знака для водяных)
			n = (i == 4) ?  1 : 3; 
			out << "\n" << fixed << setprecision(n) << Arr_readings[i];
		}
	} else {
		cout << "Ошибка открытия файла для записи!\n";
	}
	out.close();
}
//чтение тарифов, показаний и даты из файла данных (прошлый период)
void Readings::read(string path) {
	//смещение указателя чтения
	int offset = 0;
	//сщетчик строк
	int string_count = 0;
	//открытие файлового потока на чтение (путь файла path)
	ifstream in(path, ios_base::in);
	if (in.is_open()) {
		//установка указателя в начало
		in.seekg(0, ios_base::beg);
		//чтение значений тарифов в переменные
		in >> hot_water_tariff;
		in >> cold_water_tariff;
		in >> electricity_tariff;
		in >> drainage_tariff;
		//установка указателя в конец
		in.seekg(0, ios_base::end);
		//вычисление количества символов в последних 6 строках файла (датат и поаказния счетчиков)
		while (string_count < 6) {
			//смещение на один символ назад от текущей позиции
			in.seekg(-1, ios_base::cur);
			//если следующий символ чтения от указателя '\n' увеличить счетчик строк
			if (in.peek() == '\n') {
				string_count++;
			}
			//увеличить счетчик символов
			offset++;
		}
		//установка указателя перед датой прошлого периода
		in.seekg(-(offset + 4), ios_base::end); //4 - занимает символ конца файла
		//считать дату
		getline(in, date, '\n');
		//считать показания в массив
		for (int i = 0; i < 5; i++) {
			in >> Arr_readings[i];
		}
	}
	else {
		cout << "Ошибка открытия файла для чтения!\n";
	}
	in.close();
}