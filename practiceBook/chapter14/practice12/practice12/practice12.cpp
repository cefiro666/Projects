#include <iostream>
#include <fstream>

using namespace std;

class Dofile
{
public:
	Dofile(string path)
	{
		file.open(path, ios::trunc | ios::out | ios::in | ios::binary);

		if (!file.is_open())
		{
			throw exception("Ошибка открытия файла!");
		}
	}

	template <class T>
	void write(T* buff, int size)
	{
		file.seekg(0, ios::beg);
		file.write(reinterpret_cast<char*>(buff), size * sizeof(T));

		if (!file)
		{
			throw exception("Ошибка записи!");
		}

		cout << "\nЗапись выполнена";
	}

	template <class T>
	void read(T* buff, int size)
	{
		file.seekg(0, ios::beg);
		file.read(reinterpret_cast<char*>(buff), size * sizeof(T));

		if (!file)
		{
			throw exception("Ошибка чтения!");
		}

		cout << "\nЧтение выполнено";
	}

	~Dofile()
	{
		file.close();
	}

	class exception
	{
	public:
		exception(string s) : str(s) {}

		string str;
	};

private:
	fstream file;
};

int main()
{
	system("chcp 1251");

	try {
		const int MAX = 50;
		float buff[MAX];
		float buff2[MAX];

		Dofile file("data.dat");

		for (int i = 0; i < MAX; i++)
		{
			buff[i] = static_cast<float>(i);
		}

		file.write<float>(buff, MAX);

		file.read<float>(buff2, MAX);

		for (int i = 0; i < MAX; i++)
		{
			if (buff[i] != buff2[i])
			{
				cout << "\nДанные не совпали!";
				return 0;
			}
		}

		cout << "\nДанные совпали!";
	}

	catch (Dofile::exception& ex)
	{
		cout << ex.str << endl;
	}
}