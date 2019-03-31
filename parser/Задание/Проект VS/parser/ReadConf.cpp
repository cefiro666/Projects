﻿#include "pch.h"
#include "ReadConf.h"

ReadConf::ReadConf()
{
	// параметры по умолчанию
	lineWidth = 80;
	extraItems = { "<span>", "<br>", "<i>", "<sup>", "<em>", "<strong>", "</span>",
	"</i>", "</sup>", "</em>", "</strong>", "&quot;", "&nbsp;" };
}

void ReadConf::readConf()
{
	string sLineWidth;
	ifstream conf("conf.txt", ios::in);
	
	cout << "\n -Reading configuration file... ";
	if (conf.is_open())
	{
		// считать ширину строки из файла
		conf.seekg(10, ios::beg);
		getline(conf, sLineWidth, '\n');
		lineWidth = stoi(sLineWidth);
		// считать исключения из файла
		conf.seekg(18, ios::cur);
		string item;
		while (!conf.eof())
		{
			getline(conf, item, '\n');
			if (item != "") extraItems.push_back(item);
		}
		cout << "  Done" << endl;
		conf.close();
	} else {
		cout << "\n\n Error reading configuration file. The default settings are set!\n" << endl;
	}
}

int ReadConf::getLineWidth()
{
	return lineWidth;
}

vector<string> ReadConf::getextraItems()
{
	return extraItems;
}
