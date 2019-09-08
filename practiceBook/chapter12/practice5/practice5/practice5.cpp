#include <iostream>
#include <fstream>

using namespace std;

class Time
{
public:
	void getTime()
	{
		while (true)
		{
			cout << "\nВведите часы: ";
			cin >> m_hours;

			if (cin.good())
			{
				if (m_hours <= 23 && m_hours >= 0)
				{
					cin.ignore(10, '\n');
					break;
				}
				else {
					cout << "\nЧасы должны быть от 0 до 23!";
				}
			}
			else {
				cin.clear();
				cout << "\nНеправильный ввод!";
				cin.ignore(10, '\n');
			}
		}

		while (true)
		{
			cout << "\nВведите минуты: ";
			cin >> m_minutes;

			if (cin.good())
			{
				if (m_minutes <= 59 && m_minutes >= 0)
				{
					cin.ignore(10, '\n');
					break;
				}
				else {
					cout << "\nМинуты должны быть от 0 до 59!";
				}
			}
			else {
				cin.clear();
				cout << "\nНеправильный ввод!";
				cin.ignore(10, '\n');
			}
		}

		while (true)
		{
			cout << "\nВведите секунды: ";
			cin >> m_seconds;

			if (cin.good())
			{
				if (m_seconds <= 59 && m_seconds >= 0)
				{
					cin.ignore(10, '\n');
					break;
				}
				else {
					cout << "\nСекунды должны быть от 0 до 59!";
				}
			}
			else {
				cin.clear();
				cout << "\nНеправильный ввод!";
				cin.ignore(10, '\n');
			}
		}
	}

	void putTime()
	{
		cout << "\nВремя - " << m_hours << ":" << m_minutes << ":" << m_seconds;
	}

private:
	int m_hours;
	int m_minutes;
	int m_seconds;
};

int main()
{
	system("chcp 1251");

	Time time;
	char ch;

	do {
		time.getTime();
		time.putTime();

		cout << "\nПовторить? (y/n)... ";
		cin >> ch;

	} while (ch != 'n');
}