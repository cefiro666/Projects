#include "pch.h"
#include <windows.h>
#include <wininet.h>

#pragma comment(lib,"wininet")

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	LPCSTR URL = "https://docs.microsoft.com/en-us/windows/desktop/api/wininet/nf-wininet-internetreadfile";

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
				BOOL hReadFIle;
				DWORD bytesRead;

				do {
					// читаем данные
					hReadFIle = InternetReadFile(hOpenUrlA, buffer, sizeof(buffer) - 1, &bytesRead);

					// сохраняем результат
					buffer[bytesRead] = 0;
					file << buffer;

				} while (!(hReadFIle == FALSE || bytesRead == 0));

			} else {
				cout << "Ошибка записи файла!" << endl;
			}
		}
		InternetCloseHandle(hOpenUrlA);
	}
	InternetCloseHandle(hInternet);
}