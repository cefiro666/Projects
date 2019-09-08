// класс конфигурации

#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ReadConf
{
private:
	// ширина строки
	int lineWidth;
	// исключаемые слова
	vector<string> extraItems;

public:
	// при создании объекта происходит 
	// установка значений по умолчанию
	ReadConf();

	// чтение файла конфигурации
	void readConf();

	// вернуть ширину строки
	int getLineWidth();

	// вернуть список исключаемых слов
	vector<string> getExtraItems();
};

