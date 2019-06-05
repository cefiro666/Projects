#pragma once
#include <iostream>

class Excep
{
public:
	Excep(std::string error) : error(error) {}
	std::string error;
};