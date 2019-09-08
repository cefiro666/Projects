#include "pch.h"
#include <iostream>

using namespace std;

#include <string> 

class String
{
protected:
	enum { SZ = 80 };
	char str[SZ];

public:
	String()
	{
		str[0] = '\x0';
	}

	String(const char s[])
	{
		strcpy_s(str, s);
	} 

	void display() const
	{
		cout << str;
	}

	operator char* ()
	{
		return str;
	}
};

class Pstring : public String
{
public:
	Pstring() {}

	Pstring(const char s[])
	{
		if (strlen(s) >= SZ)
		{
			strncpy_s(str, s, SZ - 1);
		} else {
			strcpy_s(str, s);
		}
	}
};

int main()
{
	system("chcp 1251");
	Pstring s1;                

	char xstr[] = "Ура, товарищи! ";

	s1 = xstr;                 

	s1.display();          

	Pstring s2 = "Мы победим!ghjgjhgjhghjgjgjghgjhgjhgjhgjhgjhgjhgjhgjgjhgjhgjgjhgjghjghjgjhgjhgjghjgqwqwqwqwqwqwqw";

	cout << static_cast<char*>(s2); 
	cout << endl;

	return 0;
}


