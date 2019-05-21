#include <iostream>
#include <map>
#include <algorithm>
#include <iterator>

namespace Task
{
	class Map
	{
	public:
		Map() {}
		void input()
		{
			std::string word;
			double value;
			char ch;

			while (true)
			{
				std::cout << "Input word: ";
				std::cin >> word;
				std::cout << "Input value for \"" << word << "\": ";
				std::cin >> value;

				i = map.find(word);

				if (i == map.end())
				{
					map[word] = { value, 1 };

				} else {

					map[word] = { map[word].value + value, ++map[word].count };
				}

				std::cout << "Repeat? (y/n)... ";
				std::cin >> ch;
				if (ch == 'n') break;
			}
		}

		void sumWord()
		{
			std::cout << "\nThe sum of the values by words:\n\n";
			
			double sumWord;
			double averageWord;
			double sum = 0;
			int count = 0;

			for (i = map.begin(); i != map.end(); i++)
			{
				sumWord = i->second.value;
				averageWord = sumWord / i->second.count;

				std::cout << "Word - \"" << i->first << "\", quantity - " <<
					i->second.count << ", sum - " << sumWord << ", average - " <<
					averageWord << '\n';

				sum += sumWord;
				count += i->second.count;
			}

			std::cout << "Sum all words - " << sum << ", average all words - " <<
				sum / count << '\n';
		}

	private:
		struct Data
		{
			double value;
			int count;
		};

		std::map<std::string, Data> map;
		std::map<std::string, Data>::iterator i;
	};
}


int main()
{
	Task::Map map;
	
	map.input();
	map.sumWord();
}