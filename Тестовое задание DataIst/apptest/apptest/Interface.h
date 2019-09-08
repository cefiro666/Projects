#pragma once
#include "Mode.h"
#include <map>
#include <iostream>

enum Arg
{
	PROGNAME,
	NAMEFILE,
	MODE,
	WORD,
	HELP
};

class Interface
{
public:
	Interface(int, char* []);
	int argProcessing();
	void help();

private:
	std::map<Arg, std::string> argList;
	Mode* mode;
};