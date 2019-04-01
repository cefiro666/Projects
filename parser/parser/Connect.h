// класс установки соединения, загрузки информации
// с ресурса и конвертации кодировки буфера данных

#pragma once
#include <windows.h>
#include <wininet.h>
#pragma comment(lib,"wininet")
#include <iostream>
#include <string>

using namespace std;

class Connect
{
private:
	// объекты wininet
	HINTERNET hInternet;
	HINTERNET hOpenUrlA;
	BOOL hReadFile;

	// переменные для заполнения буфера
	char buffer[1024];
	DWORD bytesRead;
	string data;

public:
	// конструктор (при создании объекта подключается 
	// к указанному ресурсу и скачивает данные в буфер 
	Connect(LPCSTR URL);

	// проверка кодировки
	bool is_valid_utf8();

	// конвертация скачанных данных из utf-8 в ansi
	void utf8toAnsi();

	// получить строку с данными буфера
	string getData();
};