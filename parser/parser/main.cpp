#include "pch.h"
#include <windows.h>
#include <wininet.h>

#pragma comment(lib,"wininet")

#include <fstream>
#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

// форматирование ссылок и удаление лишних тегов из абзацев
void formatLink(string& buff)
{
	string openTeg, closeTeg, link;
	unsigned int pos = 0;
	unsigned int begin = 0;
	unsigned int end;

	while (true) 
	{
		openTeg = "<a href=\"";
		closeTeg = "\"";
		begin = buff.find(openTeg, pos);
		if (begin == string::npos) break;
		end = buff.find(closeTeg, begin + openTeg.size());
		link = " [" + buff.substr(begin + openTeg.size(), end - (begin + openTeg.size())) + "]";

		closeTeg = ">";
		end = buff.find(closeTeg, begin + openTeg.size());
		if (end == string::npos) break;
		buff.erase(begin, end - begin + closeTeg.size());

		openTeg = "</a>";
		begin = buff.find(openTeg, pos);
		buff.erase(begin, openTeg.size());
		buff.insert(begin, link);

		pos = begin + link.size();
	}
}

// удаление лишних тегов из текста (можно добавлять)
void deleteTeg(string& buff)
{
	string openTeg, closeTeg;
	unsigned int pos = 0;
	unsigned int begin = 0;
	unsigned int end;
	vector<string> arrTeg = { "span", "i", "sup", "em" };
	vector<string> arrTegPar = { "<", "</" };

	for (unsigned int n = 0; n < arrTeg.size(); n++)
	{
		for (unsigned int i = 0; i < arrTegPar.size(); i++)
		{
			while (true)
			{
				openTeg = arrTegPar[i] + arrTeg[n];
				closeTeg = ">";
				begin = buff.find(openTeg);
				if (begin == string::npos) break;
				end = buff.find(closeTeg, begin + openTeg.size());
				buff.erase(begin, end - begin + closeTeg.size());
			}
		}
	}
}

// рекурсивный парсер оглавления и параграфов
void parser(string data, int pos, string& buff, list<int> arrBegin, vector<string> arrTeg)
{
	arrBegin.clear();
	for (unsigned int i = 0; i < arrTeg.size(); i++)
	{
		if (data.find(arrTeg[i], pos) != string::npos)
		{
			arrBegin.push_back(data.find(arrTeg[i], pos));
		}
	}

	if (!arrBegin.empty())
	{
		arrBegin.sort();
		int begin = data.find(">", arrBegin.front());
		string teg = data.substr(arrBegin.front() + 1, begin - arrBegin.front() - 1);
		int end = data.find("</" + teg, begin + 1);
		buff.append(data.substr(begin + 1, end - begin - 1) + "\n\n");
		parser(data, end, buff, arrBegin, arrTeg);
	}
}

// возвращает сформированное имя файла
string nameFile(LPCSTR url)
{
	
	string sUrl = url;
	vector<string> signs = { "\\", "/", "?", ":", "*","\"", ">", "<", "|" };

	// замена неразрешенных символов в имени файла на "_"
	for (unsigned int i = 0; i < signs.size(); i++)
	{
		while (sUrl.find(signs[i]) != string::npos)
		{
			sUrl.replace(sUrl.find(signs[i]), 1, "_");
		}
	}

	return sUrl.substr(sUrl.find("_") + 3, (sUrl.size()- sUrl.find("_") + 3)) + "_Text.txt";
}


int main(int argc, char* argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//     \ / ? : *" > < |
	//LPCSTR URL = argv[1];
	LPCSTR URL = "https://edaplus.info/produce/carrot.html";


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

		ofstream  text(nameFile(URL), ios::out | ios::binary);

		string buff;
		unsigned int pos = 0;

		list<int> arrBegin(0);
		vector<string> arrTeg = { "<title>","<p>" };

		parser(data, pos, buff, arrBegin, arrTeg);

		formatLink(buff);
		deleteTeg(buff);

		text << buff;
		cout << "Фаил сохранен!" << endl;
		text.close();
	} 
	InternetCloseHandle(hInternet);
}

