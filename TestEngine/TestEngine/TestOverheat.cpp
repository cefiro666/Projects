#include "TestOverheat.h"


TestOverheat::TestOverheat(double mediumTemp)
	: mediumTemp(mediumTemp) {}

void TestOverheat::startEngine(Engine* engine)
{
	engine->mediumTemp = mediumTemp;
	engine->engineTemp = engine->mediumTemp;
	engine->i = engine->addiction.begin();
	engine->j = ++engine->addiction.begin();

	while (engine->engineTemp < engine->tempOverheat)
	{
		engine->step();
		if (engine->rotatSpeed >= ((engine->addiction.rbegin())->first - 1)) break;
	}
	
	std::cout << engine->engineTime << '\n';
}
