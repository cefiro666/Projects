#include "pch.h"
#include "CreatFile.h"

CreatFile::CreatFile(LPCSTR url)
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

	nameFile = sUrl.substr(sUrl.find("_") + 3, (sUrl.size() - sUrl.find("_") + 3)) + "-File.txt";
}

void CreatFile::write(string buffer)
{
	ofstream file(nameFile, ios::out);
	cout << " -Write file... ";

	if (file.is_open()) 
	{
		file << buffer;
		cout << "                  Done" << endl;
		file.close();
	} else {
		cout << "\n\n Error writing file!\n";
		exit(0);
	}
	cout << "\n All completed successfully. File created.\n";
}