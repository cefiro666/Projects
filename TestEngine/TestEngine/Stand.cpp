#include "Stand.h"

Stand::Stand(Engine* engine) : engine(engine) {}

void Stand::startTest(Test* test)
{
	test->startEngine(engine);
}
