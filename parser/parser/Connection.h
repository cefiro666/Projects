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
	// ������� wininet
	HINTERNET hInternet;
	HINTERNET hOpenUrlA;
	BOOL hReadFile;
	// ���������� ��� ������ ������ � �����
	char buffer[1024];
	DWORD bytesRead;
	string data;

public:
	// ����������� (��� �������� ������� ������������ � ����������
	// ������� �������� � ��������� ������ � ������ 
	Connection(LPCSTR URL);
	
	// ����������� ��������� ������ �� utf-8 � ansi
	void UTF8ToANSI();

	// �������� ������ � ������� ������
	string getData();
};