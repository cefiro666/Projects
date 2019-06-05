#pragma once
#include <iostream>
#include <fstream>
#include "Excep.h"

class Mode
{
public:
	Mode(std::string);

	// if necessary, you can add new 
	// methods to work with the file
	//====================================

	// word occurrence counter
	int count(std::string);

	// check sum
	int checksum();

	//====================================

	~Mode();
private:
	std::fstream file;
};