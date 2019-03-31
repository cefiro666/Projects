#pragma once

#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

class Parser
{
private:
	// ����� ������
	string buff;
	// ���������� ��� ������� parser
	list<int> arrBegin;
	vector<string> arrTegOpen;
	vector<string> arrTegClose;
	int pos;

public:
	Parser();

	// ������������ �� lineWidth �������� � ������ � ��������� ����
	void lineWidth(int lineWidth);

	// ������ ���������� � ����������
	void parser(string data);

	// �������� ������ ��������� (vector<string> extraItems) �� ������ ������
	void delExtraItems(vector<string> extraItems);

	// �������������� ������
	void formatLink();

	// ������� ������ ������
	string getBuff();
};