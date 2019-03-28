#include "pch.h"
#include <windows.h>
#include <wininet.h>

#pragma comment(lib,"wininet")

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	LPCSTR URL = argv[1];
	string url = URL;
	while (true)
	{
		if (url.find("/") == string::npos) break;
		url.replace(url.find("/"), 1, "_");
	}
	while (true)
	{
		if (url.find("?") == string::npos) break;
		url.replace(url.find("?"), 1, "_");

	}
	string path = url.substr(8,(url.size()-8)) + "_index.txt";

	// инициализация WinInet
	HINTERNET hInternet = InternetOpenA("WinInet", INTERNET_OPEN_TYPE_PRECONFIG, 0, 0, 0);

	// подключение ресурса по указанному URL
	if (hInternet != NULL)
	{
		HINTERNET hOpenUrlA = InternetOpenUrlA(hInternet, URL, 0, 0, 0, 0);

		string data;

		// считывание страницы в строковую переменную

		if (hOpenUrlA != NULL)
		{
			char buffer[1024];
			BOOL hReadFile;
			DWORD bytesRead;

			do {
				// читаем данные в буфер
				hReadFile = InternetReadFile(hOpenUrlA, buffer, sizeof(buffer) - 1, &bytesRead);
				buffer[bytesRead] = 0;

				// записываем данные из буфера в строку
				for (unsigned int i = 0; i < bytesRead; i++)
				{
					data.push_back(buffer[i]);
				}
			} while (!(hReadFile == FALSE || bytesRead == 0));
		}
		else {
			cout << "Нет соединения с интернетом!" << endl;
		}
		InternetCloseHandle(hOpenUrlA);



		ofstream  text(path, ios::out | ios::binary);

		string openTeg, closeTeg;
		string buff;
		string a;
		int begin = 0;
		int end;		
		unsigned int pos = 0;

		// парсинг заголовка
		openTeg = "<title>";
		closeTeg = "</title>";
		while (true) {
			begin = data.find(openTeg, pos);
			if (begin == string::npos) break;
			end = data.find(closeTeg, begin + openTeg.size());
			// записываем в буффер заголовок с отбивкой строки
			buff.append(data.substr(begin + openTeg.size(), end - 
				(begin + openTeg.size())) + "\n\n");
			pos = end + closeTeg.size();
		}

		// парсинг абзацев
		pos = 0;
		while (true) {
			openTeg = "<p>";
			closeTeg = "</p>";
			begin = data.find(openTeg, pos);
			if (begin == string::npos) break;
			end = data.find(closeTeg, begin + openTeg.size());
			buff.append(data.substr(begin + openTeg.size(), end - 
				(begin + openTeg.size())) + "\n\n");
			pos = end + closeTeg.size();
		}

		// форматирование ссылок
		pos = 0;
		while (true) {
			openTeg = "<a href=\"";
			closeTeg = "\"";
			begin = buff.find(openTeg, pos);
			if (begin == string::npos) break;
			end = buff.find(closeTeg, begin + openTeg.size());
			a = " [" + buff.substr(begin + openTeg.size(), end -
				(begin + openTeg.size())) + "]";

			closeTeg = ">";
			end = buff.find(closeTeg, begin + openTeg.size());
			if (end == string::npos) break;
			buff.erase(begin, end - begin + closeTeg.size());

			openTeg = "</a>";
			begin = buff.find(openTeg, pos);
			buff.erase(begin, openTeg.size());
			buff.insert(begin, a);

			openTeg = "<a href=\"";
			pos = begin + a.size();
		}

		// удаление лишних тегов
		string arr[2] = { "span", "i" };
		for (int i = 0; i < 2; i++)
		{
			pos = 0;
			while (true) {
				openTeg = "<" + arr[i];
				closeTeg = ">";
				begin = buff.find(openTeg, pos);
				if (begin == string::npos) break;
				end = buff.find(closeTeg, begin + openTeg.size());
				buff.erase(begin, end - begin + closeTeg.size());
			}
			pos = 0;
			while (true) {
				openTeg = "</" + arr[i];
				closeTeg = ">";
				begin = buff.find(openTeg, pos);
				if (begin == string::npos) break;
				end = buff.find(closeTeg, begin + openTeg.size());
				buff.erase(begin, end - begin + closeTeg.size());
			}
		}
		text << buff;
		cout << "Фаил сохранен!" << endl;
		text.close();
	} 
	InternetCloseHandle(hInternet);
}