#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Token
{
public:
	virtual float getNumber() = 0;
	virtual char getOperator() = 0;
};

class Operator : public Token
{
public:
	Operator(char ch) : _oper(ch) {}

	float getNumber()
	{
		return 0;
	}

	char getOperator() override
	{
		return _oper;
	}

private:
	char _oper;
};

class Number : public Token
{
public:
	Number(float num) : _fNum(num) {}

	float getNumber() override
	{
		return _fNum;
	}

	char getOperator()
	{
		return 0;
	}

private:
	float _fNum;
};

class Stack
{
public:
	Stack()
	{
		top = 0;
	}

	void push(float number)
	{
		atoken[++top] = new Number(number);
	}

	void push(char oper)
	{
		atoken[++top] = new Operator(oper);
	}

	Token* pop()
	{
		return atoken[top--];
	}

	int gettop()
	{
		return top;
	}

private:
	Token* atoken[100];
	int top;
};

class Parse
{
public:
	Parse(string s) : str(s) {}

	void parse()
	{
		string oper;
		stringstream ss;
		ss << str;
		getline(ss, oper, '+');
	}

	void calculate()
	{

	}

private:
	Stack stack;
	string str;
};

int main()
{
	system("chcp 1251");

	string str;
	cout << "Введите выражение:\n";
	getline(cin, str);

	Parse pares(str);

}


