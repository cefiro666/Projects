#pragma once
#include "Test.h"

class TestOverheat : public Test
{
public:
	TestOverheat(double mediumTemp);
	void startTest(Engine*) override;

private:
	double mediumTemp;
};