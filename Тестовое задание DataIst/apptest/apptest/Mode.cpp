#include "Mode.h"

Mode::Mode(std::string path)
{
	file.open(path, std::ios::in);
	if (!file.is_open()) throw Excep("Error open file!");
}

Mode::~Mode()
{
	file.close();
}

int Mode::count(std::string word)
{
	std::string nWord;
	int count = 0;
	while (!file.eof())
	{
		file >> nWord;
		if (nWord == word) count++;
	}
	return count;
}

int Mode::checksum()
{
	int checksum = 0;
	std::string nWord;
	while (!file.eof())
	{
		file >> nWord;
		for (int i = 0; i < nWord.size(); i++)
		{
			nWord.at(i);
		}
	}

	return checksum;
}
