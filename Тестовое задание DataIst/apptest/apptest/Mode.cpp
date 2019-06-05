#include "Mode.h"
#include <cctype>

Mode::Mode(std::string name)
{
	file.open(name, std::ios::in);
	if (!file.is_open()) throw Excep("\n Error opening file!");
}

Mode::~Mode()
{
	file.close();
}

int Mode::count(std::string word)
{
	std::string checkWord;
	int count = 0;

	while (!file.eof())
	{
		file >> checkWord;
		if (checkWord == word)
		{
			count++;
			continue;
		}

		for (size_t i = 0; i < checkWord.size(); i++)
		{
			if (ispunct(checkWord.at(i)))
			{
				std::string newWord = checkWord.substr(0, i);
				if (newWord == word) count++;
			}
		}
	}

	return count;
}

int Mode::checksum()
{
	int checksum = 0;
	std::string nWord;

	while (!file.eof())
	{
		file >> checkWord;
		for (size_t i = 0; i < checkWord.size(); i++)
		{
			checksum += (int)checkWord.at(i);
		}
	}

	return checksum;
}