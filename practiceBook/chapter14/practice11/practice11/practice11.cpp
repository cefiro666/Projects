// strplus.cpp
// перегрузка операции + для строк
#include <iostream>

using namespace std;

#include <string>

///////////////////////////////////////////////////////////
class String          // наш класс для строк
{
private:
	enum { SZ = 80 }; // максимальный размер строки
	char str[SZ];  // массив для строки
public:
	// конструктор без параметров
	String()
	{
		strcpy_s(str, "");
	}
	// конструктор с одним параметром
	String(const char* s)
	{

		if (strlen(s) > SZ)
		{
			throw exception("\nОшибка в конструкторе (длинная строка)");
		}

		strcpy_s(str, s);
	}
	// показ строки
	void display() const
	{
		cout << str;
	}
	// оператор сложения
	String operator+ (String ss) const
	{
		String temp;  // временная переменная

		strcpy_s(temp.str, str);    // копируем содержимое первой строки

		if ((strlen(temp.str) + strlen(ss.str)) > SZ)
		{
			throw exception("\nОшибка при сложении (длинная строка)");
		}

		strcat_s(temp.str, ss.str); // добавляем содержимое второй строки

		return temp;  // возвращаем результат
	}

	class exception
	{
	public:
		exception(string s) : str(s) {}

		string str;
	};
};
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");

	try
	{
		String s1 = "\nС Рождеством! werwerwРerwrwrwerwrwrwerwerwerwrwerwer"; // используем конструктор с параметром
		String s2 = "С Новым годомеством! werwerwРerwrwrwerwrwrwerwerwerwr!";   // используем конструктор с параметром
		String s3;                      // используем конструктор без параметров

		// показываем строки
		s1.display();
		cout << endl;
		s2.display();
		s3.display();

		s3 = s1 + s2;       // присваиваем строке s3 результат сложения строк s1 и s2

		s3.display();     // показываем результат
		cout << endl;
	}

	catch (const String::exception& ex)
	{
		cout << ex.str << endl;
	}
}


