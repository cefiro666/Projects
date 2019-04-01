// класс обработки буфера данных

#pragma once
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Handler
{
private:
	// буфер данных
	string buff;

	// переменные для метода parsing
	list<int> arrBegin;
	vector<string> arrTegOpen;
	vector<string> arrTegClose;
	int pos;

public:
	Handler();
	// парсер оглавления и параграфов
	void parsing(string data);

	// форматирование ссылок
	void formatLink();

	// удаление лишних элементов ( extraItems) 
	// из буфера данных
	void delExtraItems(vector<string> extraItems);

	// выравнивание ширины строки с переносом слов
	void lineWidth(int lineWidth);

	// вернуть буффер данных
	string getBuff();
};