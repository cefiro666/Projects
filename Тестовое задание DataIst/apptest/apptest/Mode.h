#pragma once
#include <iostream>
#include <fstream>

class Mode
{
public:
	Mode(std::string path);

	// при необходимости можно добавить 
	// новые методы для работы с файлом
	//====================================

	// счеткик вхождений слова
	int count(std::string word);

	// контрольная сумма
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