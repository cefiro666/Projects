// класс создания итогового файла

#pragma once
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class CreatFile
{
private:
	// адрес ресурса
	LPCSTR url;
	// имя файла
	string nameFile;

public:
	// при создании обекта формируетя имя файла
	CreatFile(LPCSTR url);

	// запись обработанного буфера в файл
	void write(string buffer);
};