#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[])
{
	system ("chcp 1251");

	char ch;

	if (argc != 3)
	{
		cout << "\nНеверное количество аргументов!";

	} else {

		ifstream fileOriginal;
		fileOriginal.open(argv[1], ios::in | ios::binary);

		if (!fileOriginal)
		{
			cout << "\nОшибка открытия файла " << argv[1];

		} else {

			ofstream fileCopy;
			fileCopy.open(argv[2], ios::out | ios::binary);

			if (!fileCopy)
			{
				cout << "\nОшибка открытия файла " << argv[2];

			}
			else {

				while (fileOriginal)
				{
					fileOriginal.get(ch);
					fileCopy.put(ch);
				}
				cout << "\nФайл скопирован.";
			}
		}
	}
}