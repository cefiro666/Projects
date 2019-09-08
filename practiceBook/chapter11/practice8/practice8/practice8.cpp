#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

const int LEN = 80;
const int MAX = 40;  

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

private:
	Token* atoken[MAX];
	int top;
};

int main()
{
	system("chcp 1251");
	
	Stack st;
	st.push(34.45F);
	st.push('+');
	Token* ptr1 = st.pop();
	Token* ptr2 = st.pop();
	cout << ptr1->getOperator() << ptr2->getNumber();
}