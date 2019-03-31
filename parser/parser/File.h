#pragma once

#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class File
{
	// ����� �������
	LPCSTR url;
	// ��� �����
	string nameFile;

public:
	// ����������� (��������� ��� �������� ����)
	File(LPCSTR url);

	// ������ ����� ������
	void write(string buffer);
};