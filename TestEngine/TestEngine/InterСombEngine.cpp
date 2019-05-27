#include "Inter—ombEngine.h"

Inter—ombEngine::Inter—ombEngine(double cMoment, double cRotatSpeed, double cTemp,
	double Inert, double tempOverheat, std::map<double, double> addiction)
{
	this->cMoment = cMoment;
	this->cRotatSpeed = cRotatSpeed;
	this->cTemp = cTemp;
	this->Inert = Inert;
	this->tempOverheat = tempOverheat;
	this->addiction = addiction;
	this->rotatSpeed = 0.0;
}

void Inter—ombEngine::step()
{
	M = rotatSpeed * (j->second - i->second) / (j->first - i->first) + j->second - 
		(j->second - i->second) / (j->first - i->first) * j->first;

	a = M / Inert;
	heatRate = M * cMoment + (rotatSpeed * rotatSpeed) * cRotatSpeed;
	coolRate = cTemp * (mediumTemp - engineTemp);
	engineTemp += heatRate + coolRate;

	rotatSpeed += a / 10;
	engineTime += 0.1;

	if (rotatSpeed >= j->first)
	{
		++i;
		++j;
	}
}