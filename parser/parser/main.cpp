#include "pch.h"
#include <windows.h>
#include <wininet.h>

#pragma comment(lib,"wininet")

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LPCSTR URL = "https://edaplus.info/produce/carrot.html";

	// инициализация WinInet
	HINTERNET hInternet = InternetOpenA("WinInet", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

	// подключение ресурса по указанному URL
	if (hInternet != NULL)
	{
		HINTERNET hOpenUrlA = InternetOpenUrlA(hInternet, URL, 0, 0, 0, 0);

		// считывание файла
		if (hOpenUrlA != NULL)
		{
			// создаём выходной файл
			ofstream file("news.txt", ios::out | ios::binary);
			if (file.is_open())
			{
				char buffer[1024];
				BOOL hReadFile;
				DWORD bytesRead;

				do {
					// читаем данные
					hReadFile = InternetReadFile(hOpenUrlA, buffer, sizeof(buffer) - 1, &bytesRead);

					// сохраняем результат
					buffer[bytesRead] = 0;
					file << buffer;

				} while (!(hReadFile == FALSE || bytesRead == 0));
				file.close();
				ofstream  file111("news111.txt", ios::out | ios::binary);
				string date;
				ifstream file("news.txt", ios::in);
				while (!(date == "</html>"))
				{
					getline(file, date, '<');
					//file.seekg(-1, ios_base::cur);
					getline(file, date, '>');
					date = "<" + date + ">";
					if (date == "<p>")
					{
						getline(file, date, '<');
						file111 << date << "\n\n";
						file.seekg(3, ios_base::cur);
					}
					else if (date == "<h1>" || date == "<h2>" || date == "<h3>" || date == "<h4>" || date == "<h5>" || date == "<h6>")
					{
						getline(file, date, '<');
						file111 << date << "\n\n";
						file.seekg(4, ios_base::cur);
					}
					else if (date == "<title>")
					{
						getline(file, date, '<');
						file111 << date << "\n\n";
						file.seekg(7, ios_base::cur);
					}

				}
				file111.close();
				file.close();
			} else {
				cout << "Ошибка записи файла!" << endl;
			}
		}
		InternetCloseHandle(hOpenUrlA);
	}
	InternetCloseHandle(hInternet);
}