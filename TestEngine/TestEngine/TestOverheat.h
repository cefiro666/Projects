#pragma once
#include "Test.h"
#include <iostream>

class TestOverheat : public Test
{
public:
	TestOverheat(double mediumTemp);
	void startEngine(Engine*) override;

private:
	double mediumTemp;
};

