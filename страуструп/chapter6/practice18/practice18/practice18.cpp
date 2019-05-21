#include <iostream>
#include <map>

std::map<std::string, double> table;

enum TokenValue
{
	NAME,			NUMBER,			END,
	PLUS = '+',		MINUS = '-',	MUL = '*',	DIV = '/',
	PRINT = ';',	ASSIGN = '=',	LP = '(',	RP = ')'
};

TokenValue currTok = PRINT;

double numberValue;
std::string stringValue;

TokenValue getToken()
{
	char ch = 0;
	std::cin >> ch;
	switch (ch)
	{
	case 0:
		return currTok = END;
	}
}

double expr(bool get);

double prim(bool get)
{
	if (get) getToken();

	switch (currTok)
	{
	case NUMBER:
		double v = numberValue;
		getToken();
		return v;
	case NAME:
		double& v = table[stringValue];
		if (getToken() == ASSIGN) v = expr(true);
		return v;
	case MINUS:
		return -prim(true);
	case LP:
		double e = expr(true);
		if (currTok != RP) return error("')' expected");
		getToken();
		return e;
	default:
		return error("primary ecpected");
	}
}

double term(bool get)
{
	double left = prim(get);
	
	while (true)
	{
		switch (currTok)
		{
		case MUL:
			left *= prim(true);
			break;
		case DIV:
			if (double d = prim(true))
			{
				left /= d;
				break;
			}
			return error("divide by 0");
		default:
			return left;
		}
	}
}

double expr(bool get)
{
	double left = term(get);

	while(true)
	{
		switch (currTok)
		{
		case PLUS:
			left += term(true);
			break;
		case MINUS:
			left -= term(true);
			break;
		default:
			return left;
		}
	}
}
int main()
{
    std::cout << "Hello World!\n"; 
}