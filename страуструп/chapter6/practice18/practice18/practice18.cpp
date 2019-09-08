#include <iostream>
#include <map>
#include <list>
#include <sstream>

std::istream* input;
std::map<std::string, double> table;
std::map<std::string, std::list<char> > func;


struct Symbol
{
	double arg;
	double numberValue;
	std::string stringValue;
};

Symbol symbol = { 0, 0, "" };

enum TokenValue
{
	NAME,			NUMBER,			 END,			FUNC,
	PLUS = '+',		MINUS = '-',	 MUL = '*',		DIV = '/',
	PRINT = ';',	 ASSIGN = '=',	 LP = '(',		RP = ')'
};

TokenValue currTok = PRINT;

int noOfErrors;
int line = 0;

double error(const std::string& s, int& line)
{
	noOfErrors++;
	std::cerr << "line: " << line << " - error: " << s << '\n';
	line = 0;
	return 1;
}

TokenValue getToken()
{
	char ch;

	do {

		if (!(*input).get(ch)) return currTok = END;

	} while (ch != '\n' && isspace(ch));

	switch (ch)
	{
	case ';':
	case '\n':
		++line;
		return currTok = PRINT;

	case '*':
	case '/':
	case '+':
	case '-':
	case '(':
	case ')':
	case '=':
		return currTok = TokenValue(ch);

	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9':
	case '.':
		(*input).putback(ch);
		(*input) >> symbol.numberValue;
		return currTok = NUMBER;

	default:
		if (isalpha(ch))
		{
			symbol.stringValue = ch;
			while ((*input).get(ch) && isalnum(ch))
			{
				symbol.stringValue.push_back(ch);
			}

			if (ch == '(')
			{
				std::string arg;
				while (true)
				{
					(*input).get(ch);
					if (ch == ')') break;
					arg.push_back(ch);
				}

				if (!arg.empty()) symbol.arg = std::stoi(arg);

				return currTok = FUNC;
			}

			(*input).putback(ch);

			return currTok = NAME;
		}

		error("bad token", line);
		return currTok = PRINT;
	}
}

double expr(bool get);

double prim(bool get)
{
	if (get) getToken();

	switch (currTok)
	{
	case NUMBER:
	{
		double v = symbol.numberValue;
		getToken();
		return v;
	}

	case NAME:
	{
		double& v = table[symbol.stringValue];
		if (getToken() == ASSIGN) v = expr(true);
		return v;
	}

	case FUNC:
	{
		std::list<char>& list = func[symbol.stringValue];
		std::list<char>::iterator i;
		if (getToken() == ASSIGN)
		{
			std::cout << symbol.arg << '\n';
			char ch;
			(*input).get(ch);
			while (true)
			{
				if (ch == '\n') break;
				list.push_back(ch);
				(*input).get(ch);
			}

			std::string str;
			for (i = list.begin(); i != list.end(); i++)
			{
				str.push_back(*i);
			}
			
			input = new std::istringstream(str);
			double v = expr(true);
			input = &std::cin;
			return v;

		} else {

			std::string str;
			for (i = list.begin(); i != list.end(); i++)
			{
				str.push_back(*i);
			}

			input = new std::istringstream(str);
			double v = expr(true);
			input = &std::cin;
			return v;
		}
	}

	case MINUS:
		return -prim(true);

	case LP:
	{
		double e = expr(true);
		if (currTok != RP) return error("')' expected", line);
		getToken();
		return e;
	}

	default:
		return error("primary ecpected", line);
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
			return error("divide by 0", line);

		default:
			return left;
		}
	}
}

double expr(bool get)
{
	double left = term(get);

	while (true)
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

int main(int argc, char* argv[])
{
	switch (argc)
	{
	case 1:
		input = &std::cin;
		break;

	case 2:
		input = new std::istringstream(argv[1]);
		break;

	default:
		error("too many arguments", line);
		return 1;
	}

	table["pi"] = 3.141592;
	table["e"] = 2.718281829;
	func["q"] = { '4','+','5' };

	while (*input)
	{
		getToken();

		if (currTok == END) break;
		if (currTok == PRINT)
		{
			line = 0;
			continue;
		}

		std::cout << expr(false) << '\n';
	}

	if (input != &std::cin) delete input;

	return noOfErrors;
}