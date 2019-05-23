#include <iostream>
#include <map>
#include <sstream>

std::istream* input;

std::map<std::string, double> table;
std::map <std::string, std::string> func;

struct Symbol
{
	double numberValue;
	std::string stringValue;
};

enum TokenValue
{
	NAME,			NUMBER,			 END,			FUNC,
	PLUS = '+',		MINUS = '-',	 MUL = '*',		DIV = '/',
	PRINT = ';',	 ASSIGN = '=',	 LP = '(',		RP = ')'
};

int noOfErrors;

double error(const std::string& s, int& line)
{
	noOfErrors++;
	std::cerr << "line: " << line << " - error: " << s << '\n';
	line = 0;
	return 1;
}

TokenValue currTok = PRINT;

Symbol symbol;

int line = 0;

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
			while ((*input).get(ch) && isalnum(ch) || ch == '(' || ch == ')')
			{
				symbol.stringValue.push_back(ch);
			}

			(*input).putback(ch);

			if (symbol.stringValue.find("(") != std::string::npos)
			{
				return currTok = FUNC;
			}

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
		std::string& s = func[symbol.stringValue];
		TokenValue token = getToken();
		if (token == ASSIGN)
		{
			std::string str;
			(*input) >> str;
			s.append(str);

			(*input).clear();

			input = new std::istringstream(s);
			double v = expr(true);
			input = &std::cin;
			return v;

		} else {
			
			std::string buffer;
			std::string temp;
			(*input) >> buffer;
			temp.append(char(token) + buffer);
			input = new std::istringstream(s + temp);
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
	func["sqrt()"] = "5 + 6;";

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