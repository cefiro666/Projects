#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Parser
{
private:
	// буфер данных
	string buff;
	// переменные для функции parser
	list<int> arrBegin;
	vector<string> arrTegOpen;
	vector<string> arrTegClose;
	int pos;

public:
	Parser();

	// выравнивание по lineWidth символов в строке с переносом слов
	void lineWidth(int lineWidth);

	// парсер оглавления и параграфов
	void parser(string data);

	// удаление лишних элементов (vector<string> extraItems) из буфера данных
	void delExtraItems(vector<string> extraItems);

	// форматирование ссылок
	void formatLink();

	// вернуть буффер данных
	string getBuff();
};