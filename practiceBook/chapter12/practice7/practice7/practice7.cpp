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
	}

private:
	unsigned int number;
	string name;
	string patronymic;
	string surname;
};

int Name::count = 0;

int main()
{
	system("chcp 1251");

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
}