#pragma once

#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class File
{
	// адрес ресурса
	LPCSTR url;
	// имя файла
	string nameFile;

public:
	// конструктор (формирует имя будущего фала)
	File(LPCSTR url);

	// запись файла данных
	void write(string buffer);
};