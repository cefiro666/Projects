#include <iostream>
#include <algorithm>
#include <iterator>
#include <fstream>
#include <map>
#include <string>

using namespace std;

class Map
{
public:
	void displayMap()
	{
		map<string, int, less<string> >::iterator iter;
		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			cout << (*iter).first << " == " << (*iter).second << endl;
		}
	}

	void readFile(string path)
	{
		file.open(path);
		istream_iterator<string> in(file), eof;

		while (in != eof)
		{
			mp.insert(make_pair(*in++, 0));
		}
	}

	void calcWord()
	{
		file.clear();

		map<string, int, less<string> >::iterator iter;
		string word;
		int count;
		for (iter = mp.begin(); iter != mp.end(); iter++)
		{
			count = 0;
			file.seekg(0);

			while (!file.eof())
			{
				file >> word;
				if (word == (*iter).first)
				{
					count++;
				}
			}

			(*iter).second = count;
		}
	}

private:
	map<string, int, less<string> > mp;
	ifstream file;
};

int main()
{
	system("chcp 1251");
	
	Map m;
	m.readFile("data.txt");
	m.calcWord();
	m.displayMap();
}