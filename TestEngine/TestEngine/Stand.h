#pragma once
#include "Test.h"
#include "Engine.h"

class Stand
{
public:
	Stand(Engine*);
	void startTest(Test*);

private:
	Engine* engine;
};

