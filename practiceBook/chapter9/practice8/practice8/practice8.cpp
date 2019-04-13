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
		}
		else {
			strcpy_s(str, s);
		}
	}
};

class Pstring2 : public Pstring
{
public:
	Pstring2() : Pstring() {}

	Pstring2(const char s[]) : Pstring(s) {}

	Pstring2& left(Pstring2 str, int n)
	{
		for (int i = 0; i < n; i++)
		{
			this->str[i] = str[i];
		}
		this->str[n] = '\0';
		return *this;
	}

	Pstring2& mid(Pstring2 str, int s, int n)
	{
		int l = 0;
		for (int i = s; i < s + n; i++, l++)
		{
			this->str[l] = str[i];
		}
		this->str[l] = '\0';
		return *this;
	}

	Pstring2& right(Pstring2 str, int n)
	{
		int l = 0;
		
		for (unsigned int i = strlen(str) - n; i < strlen(str); i++, l++)
		{
			this->str[l] = str[i];
		}
		this->str[l] = '\0';
		return *this;
	}
};

int main()
{
	system("chcp 1251");
	Pstring2 s1;

	Pstring2 s2 = "Мы победим я так думаю";

	cout << static_cast<char*>(s2);
	cout << endl;

	s1.left(s2, 5);
	s1.display();
	cout << endl;
	s1.mid(s2, 5, 5);
	s1.display();
	cout << endl;
	s1.right(s2, 5);
	s1.display();
	return 0;
}


