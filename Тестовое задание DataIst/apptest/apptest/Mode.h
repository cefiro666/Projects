#pragma once
#include <iostream>
#include <fstream>

class Mode
{
public:
	Mode(std::string path);

	// ��� ������������� ����� �������� 
	// ����� ������ ��� ������ � ������
	//====================================

	// ������� ��������� �����
	int count(std::string word);

	// ����������� �����
	int checksum();

	//====================================

	class Excep 
	{
	public:
		Excep(std::string error) : error(error) {}
		std::string error;
	};

	~Mode();
private:
	std::fstream file;
};