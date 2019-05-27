#pragma once
#include "Engine.h"

class InterŅombEngine : public Engine
{
public:
	InterŅombEngine(double cMoment, double cRotatSpeed,
		double cTemp, double Inert, double tempOverheat,
		std::map<double, double> addiction);

	void step() override;
};

