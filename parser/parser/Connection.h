#pragma once

#include <windows.h>
#include <wininet.h>
#pragma comment(lib,"wininet")
#include <iostream>
#include <string>

using namespace std;

class Connection
{
private:
	// объекты wininet
	HINTERNET hInternet;
	HINTERNET hOpenUrlA;
	BOOL hReadFile;
	// переменные для записи данных в буфер
	char buffer[1024];
	DWORD bytesRead;
	string data;

public:
	// конструктор (при создании объекта подключается к указанному
	// ресурсу интернет и скачивает данные в строку 
	Connection(LPCSTR URL);
	
	// конвертация скачанных данных из utf-8 в ansi
	void UTF8ToANSI();

	// получить строку с данными буфера
	string getData();
};