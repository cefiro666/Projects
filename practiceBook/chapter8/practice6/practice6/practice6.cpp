#include "pch.h"
#include <iostream>

using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	Time() :hours(0), minutes(0), seconds(0) {}

	Time(int h, int m, int s)
	{
		hours = h;
		minutes = m;
		seconds = s;
	}

	void print_time() const
	{
		cout << hours << ":" << minutes << ":" << seconds << endl;
	}

	Time operator+ (Time time2) const
	{
		Time temp(hours, minutes, seconds);
		temp.seconds = temp.hours * 3600 + temp.minutes * 60 +
			temp.seconds + time2.hours * 3600 + time2.minutes *
			60 + time2.seconds;
		temp.hours = temp.seconds / 3600;
		temp.minutes = (temp.seconds - (temp.hours * 3600)) / 60;
		temp.seconds = (temp.seconds - (temp.hours * 3600)) - (temp.minutes * 60);
		return temp;
	}

	Time operator- (Time time2) const
	{
		Time temp(hours, minutes, seconds);
		temp.seconds = (temp.hours * 3600 + temp.minutes * 60 +
			temp.seconds) - (time2.hours * 3600 + time2.minutes *
			60 + time2.seconds);
		temp.hours = temp.seconds / 3600;
		temp.minutes = (temp.seconds - (temp.hours * 3600)) / 60;
		temp.seconds = (temp.seconds - (temp.hours * 3600)) - (temp.minutes * 60);
		return temp;
	}

	Time operator* (float var)
	{
		Time temp(hours, minutes, seconds);
		temp.seconds = (temp.hours * 3600 + temp.minutes * 60 -
			temp.seconds) * var;
		temp.hours = temp.seconds / 3600;
		temp.minutes = (temp.seconds - (temp.hours * 3600)) / 60;
		temp.seconds = (temp.seconds - (temp.hours * 3600)) - (temp.minutes * 60);
		return temp;
	}

	Time operator++ ()
	{
		return Time(++hours, minutes, seconds);
	}

	Time operator-- ()
	{
		return Time(--hours, minutes, seconds);
	}

	Time operator++ (int)
	{
		return Time(hours++, minutes, seconds);
	}

	Time operator-- (int)
	{
		return Time(hours--, minutes, seconds);
	}


};

int main()
{
	Time time1(7, 34, 45);
	Time time2(3, 45, 34);
	Time time3, time4;
	time3 = time1 - time2;
	time3.print_time();
	time3 = time1 * 2;
	time3.print_time();
}