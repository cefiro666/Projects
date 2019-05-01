#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std;

int isFeet(string);     //объявление
///////////////////////////////////////////////////////////
class Distance          // Класс английских расстояний
{
private:
	int feet;
	float inches;
public:
	Distance()                 // конструктор (без аргументов)
	{
		feet = 0; inches = 0.0;
	}

	Distance(int ft, float in) // конструктор (2 арг.)
	{
		feet = ft; inches = in;
	}

	void showdist()            // вывод расстояния
	{
		cout << feet << "\'-" << inches << '\"';
	}

	void getdist();     
							
	class exception
	{
	public:
		exception(string s) : str(s) {}

		string str;
	};
};
//---------------------------------------------------------
void Distance::getdist()    // получение длины от пользователя
{
	string instr;             // для входной строки
	cout << "\n\nВведите футы: ";

	cin.unsetf(ios::skipws);				
	cin >> instr;   

	if (!isFeet(instr))     
	{  					
		cin.clear();
		cin.ignore(10, '\n');
		throw exception("Футы должны быть целыми < 1000");
	}       

	feet = atoi(instr.c_str());
	cin.clear();
	cin.ignore(10, '\n');

	cout << "Введите дюймы: ";

	cin.unsetf(ios::skipws);
	cin >> inches;        

	if (inches >= 12.0 || inches < 0.0)
	{
		cin.clear();
		cin.ignore(10, '\n');
		throw exception("Дюймы должны быть между 0.0 и 11.99");
	}

	if (!cin.good())        // все ли хорошо с cin
	{
		cin.clear();
		cin.ignore(10, '\n');
		throw exception("Неверно введены дюймы");
	}

	cin.clear();
	cin.ignore(10, '\n');
}
//---------------------------------------------------------
int isFeet(string str)      // true если введена строка
{                         // с правильным значением футов
	int slen = str.size();    // получить длину

	if (slen == 0 || slen > 5)
	{
		return 0;
	}

	for (int j = 0; j < slen; j++)
	{
		if ((str[j] < '0' || str[j] > '9') && str[j] != '-')
		{
			return 0;
		}	
	}

	double n = atof(str.c_str()); // перевод в double

	if (n < -999.0 || n > 999.0)
	{
		return 0;
	}

	return 1;                  // правильные футы
}
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");
	Distance d;
	char ans = 'y';
	do {
		try
		{
			d.getdist();          // получить его значение
			cout << "\nРасстояние = ";
			d.showdist();         // вывести его
			cout << "\nЕще раз (y/n)? ";
			cin >> ans;
			cin.ignore(10, '\n'); // съесть символы и
		}

		catch (Distance::exception ex)
		{
			cout << ex.str << endl;
		}

	} while (ans != 'n');  // цикл до 'n'

	return 0;
}


