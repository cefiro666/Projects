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
<<<<<<< HEAD
	}

	void getName()
	{
		cout << "Номер - " << number << endl;
		cout << "Фамилия - " << surname << endl;
		cout << "Имя - " << name << endl;
		cout << "Отчество - " << patronymic << endl;
	}

	static int count;

	static void writeFile(Name* arr[])
	{
		fstream file;
		file.open("data.dat", ios::out | ios::app | ios::binary);

		for (int i = 0; i < count; i++)
		{
			file.write((char*)arr[i], sizeof(Name));
		}

		file.close();
	}

	static void ReadFile(Name* arr[])
	{
		fstream file;
		file.open("data.dat", ios::in | ios::binary);

		while(!file.eof())
		{
			arr[count] = new Name;
			file.read((char*)arr[count++], sizeof(Name));
		}

		file.close();
=======

		ofstream file;
		file.open("data.dat", ios::app | ios::out | ios::binary);

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
>>>>>>> 48d83bc6c0e27c0e8889c130dc34a600bd7d3fbc
	}

private:
	unsigned int number;
	string name;
	string patronymic;
	string surname;
};

<<<<<<< HEAD
int Name::count = 0;

=======
>>>>>>> 48d83bc6c0e27c0e8889c130dc34a600bd7d3fbc
int main()
{
	system("chcp 1251");

<<<<<<< HEAD
	Name* arr[100];
	char ch;

	cout << "Считать данные из файла или ввести новые? (1/2)... ";
	cin >> ch;
	if (ch == '1')
	{
		Name::ReadFile(arr);
		for (int i = 0; i < Name::count - 1; i++)
		{
			arr[i]->getName();
		}
	}
	else if (ch == '2')
	{
		do {
			arr[Name::count] = new Name;
			arr[Name::count++]->setName();
			cout << "\nПовторить? (y/n)... ";
			cin.ignore(10, '\n');
			cin >> ch;

		} while (ch != 'n');

		for (int i = 0; i < Name::count; i++)
		{
			arr[i]->getName();
		}
		
		Name::writeFile(arr);
	}
=======
	unsigned int number;
	char ch;
	Name name;

	do {
		name.setName();
		cout << "\nПовторить? (y/n)... ";
		cin.ignore(10, '\n');
		cin >> ch;

	} while (ch != 'n');

	cout << "\nКакой номер вывести?... ";
	cin >> number;
	name.getName(number);
>>>>>>> 48d83bc6c0e27c0e8889c130dc34a600bd7d3fbc
}