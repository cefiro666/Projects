#include <iostream>
#include <fstream>


using namespace std;

int main()
{
	system("chcp 1251");

	char ch;
	string name,patronymic, surname;
	unsigned int number;

	ofstream file;
	file.open("data.dat", ios::out | ios::app);

	if (!file) 
	{
		cout << "\nОшибка открытия файла для записи данных!";

	} else {

		do {
			cout << "Введите имя: ";
			cin >> name;
			cout << "Введите отчество: ";
			cin >> patronymic;
			cout << "Введите фамилию: ";
			cin >> surname;
			cout << "Введите номер: ";
			cin >> number;

			file << name << endl
				<< patronymic << endl
				<< surname << endl
				<< number << endl;

			cout << "\nПовторить? (y/n)... ";
			cin.ignore(10, '\n');
			cin >> ch;

		} while (ch != 'n');

		file.close();

		ifstream file;
		file.open("data.dat", ios::in);
		while (file)
		{
			file.get(ch);
			cout << ch;
		}
	}
	
}