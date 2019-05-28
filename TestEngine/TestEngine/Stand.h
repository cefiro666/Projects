#pragma once
#include "Test.h"
#include "Engine.h"

class Stand
{
public:
	Stand(Engine*);
	void startStand(Test*);

private:
	Engine* engine;
};