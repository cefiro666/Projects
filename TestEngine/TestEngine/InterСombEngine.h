#pragma once
#include "Engine.h"

class Inter—ombEngine : public Engine
{
public:
	Inter—ombEngine(double cMoment, double cRotatSpeed,
		double cTemp, double Inert, double tempOverheat,
		std::map<double, double> addiction);

	void step() override;
};

