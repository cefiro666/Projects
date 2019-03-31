#include "pch.h"
#include "File.h"


File::File(LPCSTR url)
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
	nameFile = sUrl.substr(sUrl.find("_") + 3, (sUrl.size() - sUrl.find("_") + 3)) + "_Text.txt";
}

void File::write(string buffer)
{
	ofstream file(nameFile, ios::out);
	if (file.is_open()) {
		file << buffer;
		cout << "Файл сохранен!" << endl;
		file.close();
	}
	else {
		cout << "Ошибка открытия файла для записи!\n";
	}
}