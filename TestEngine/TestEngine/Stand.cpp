#include "Stand.h"
#include <iostream>
#include <typeinfo>

Stand::Stand(Engine* engine) : engine(engine) {}

void Stand::startStand(Test* test)
{
	std::cout << " \n ������� ��������� " << typeid(*engine).name() << '\n';

	test->startTest(engine);

	engine->resetEngine();
}