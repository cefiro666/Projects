#include <iostream>
#include <fstream>

using namespace std;

class Name
{
public:
	void setName()
	{
		cout << "Введите имя: ";
		cin >> name;
		cout << "Введите отчество: ";
		cin >> patronymic;
		cout << "Введите фамилию: ";
		cin >> surname;
		cout << "Введите номер: ";
		cin >> number;

		ofstream file;
		file.open("data.dat", ios::app | ios:: out | ios::binary);

		if (!file)
		{
			cout << "\nНевозможно открыть фаил для записи!";
		}
		else {
			file << number << endl
				<< surname << endl
				<< name << endl
				<< patronymic << endl;
			file.close();
		}
	}

	void getName(unsigned int numb)
	{
		ifstream file;
		file.open("data.dat", ios::in | ios::binary);

		if (!file)
		{
			cout << "\nНевозможно открыть фаил для чтения!";
		}
		else {
			while (file && number != numb)
			{
				file >> number >> surname >> name >> patronymic;
			}

			if (number == numb)
			{
				cout << "Номер - " << number << endl;
				cout << "Фамилия - " << surname << endl;
				cout << "Имя - " << name << endl;
				cout << "Отчество - " << patronymic << endl;
			}
			else {
				cout << "\nНе найдено!" << endl;
			}
		}
	}

private:
	unsigned int number;
	string name;
	string patronymic;
	string surname;
};

int main()
{
	system("chcp 1251");

	unsigned int number;
	char ch;
	Name name;

	do {
		name.setName();
		cout << "\nПовторить? (y/n)... ";
		cin.ignore(10, '\n');
		cin >> ch;

	} while (ch != 'n');

	cout << "\nКакой номер вывести?";
	cin >> number;
	name.getName(number);
}