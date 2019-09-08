#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	ifstream file;
	file.open(argv[1], ios::in | ios::binary);
	
	if (!file) 
	{
		cout << "\nНевозвожно открыть фаил" << argv[1];

	} else {

		file.seekg(0, ios::end);
		cout << "\nРазмер файла " << file.tellg() << " байт.";
	}
}