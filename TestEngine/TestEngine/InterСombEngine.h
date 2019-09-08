#pragma once
#include "Engine.h"

class InterCombEngine : public Engine
{
public:
	InterCombEngine(double cMoment, double cRotatSpeed,
		double cTemp, double Inert, double tempOverheat,
		std::map<double, double> addiction);

	void stepSimulation() override;
	void resetEngine() override;

private:
	std::map<double, double> ::iterator addictionValue, nextAddictionValue;
	double nextSpeed;
	double speed;
	double nextMoment;
	double moment;
};