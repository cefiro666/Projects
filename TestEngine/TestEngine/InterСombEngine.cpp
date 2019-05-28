#include "Inter—ombEngine.h"
#include <iostream>

InterCombEngine::InterCombEngine(double cMoment, double cRotatSpeed, double cTemp,
	double Inert, double overheatTemp, std::map<double, double> addiction)
{
	this->cMoment = cMoment;
	this->cRotatSpeed = cRotatSpeed;
	this->cTemp = cTemp;
	this->Inert = Inert;
	this->overheatTemp = overheatTemp;
	this->addiction = addiction;
	rotatSpeed = 0.0;
	engineTime = 0.0;
	addictionValue = this->addiction.begin();
	nextAddictionValue = ++this->addiction.begin();
}

void InterCombEngine::resetEngine()
{
	rotatSpeed = 0.0;
	engineTime = 0.0;
	addictionValue = this->addiction.begin();
	nextAddictionValue = ++this->addiction.begin();
}

void InterCombEngine::stepSimulation()
{
	nextSpeed = nextAddictionValue->first;
	speed = addictionValue->first;
	nextMoment = nextAddictionValue->second;
	moment = addictionValue->second;

	M = rotatSpeed * (nextMoment - moment) / (nextSpeed - speed) + nextMoment -
		(nextMoment - moment) / (nextSpeed - speed) * nextSpeed;

	a = M / Inert;
	heatRate = M * cMoment + (rotatSpeed * rotatSpeed) * cRotatSpeed;
	coolRate = cTemp * (mediumTemp - engineTemp);
	engineTemp += heatRate + coolRate;

	rotatSpeed += a / 100;
	engineTime += 0.01;

	if (rotatSpeed >= nextSpeed)
	{
		++addictionValue;
		++nextAddictionValue;
	}
}