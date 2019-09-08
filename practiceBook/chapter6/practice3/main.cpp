#include <iostream>

using namespace std;

class Time
{
private:
    int hours;
    int minutes;
    int seconds;

public:
    Time():hours(0), minutes(0), seconds(0){}

    Time(int h, int m, int s)
    {
        hours = h;
        minutes = m;
        seconds = s;
    }

    void print_time() const
    {
        cout << hours <<":" << minutes << ":" << seconds << endl;
    }

    void add_time(Time time1, Time time2)
    {
        seconds = time1.hours * 3600 + time1.minutes * 60 + 
            time1.seconds + time2.hours * 3600 + time2.minutes * 
            60 + time2.seconds;
        hours = seconds / 3600;
        minutes = (seconds - (hours * 3600)) / 60;
        seconds = (seconds - (hours * 3600)) - (minutes * 60);
    }
};

int main()
{
    const Time time1(4,34,45);
    const Time time2(3,45,34);
    Time time3;
    time3.add_time(time1,time2);
    time3.print_time();
}