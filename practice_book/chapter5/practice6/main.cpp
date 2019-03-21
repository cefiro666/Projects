#include <iostream>
#include <string>

using namespace std;
   
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

long time_to_secs(Time time);
Time secs_to_time(long secs);

int main()
{
    string hours,minutes,seconds;
    Time time1,time2,time3;

    cout << "Введите первое время (hh:mm:ss): ";
    getline(cin,hours,':');
    getline(cin,minutes,':');
    getline(cin,seconds);
    time1.hours = stoi(hours);
    time1.minutes = stoi(minutes);
    time1.seconds = stoi(seconds);

    cout << "Введите второе время (hh:mm:ss): ";
    getline(cin,hours,':');
    getline(cin,minutes,':');
    getline(cin,seconds);
    time2.hours = stoi(hours);
    time2.minutes = stoi(minutes);
    time2.seconds = stoi(seconds);

    time3 = secs_to_time(time_to_secs(time1) + time_to_secs(time2));
    
    cout << "Итоговое время " << time3.hours << ":" << time3.minutes
        << ":" << time3.seconds << endl;
}

Time secs_to_time(long secs)
{
    Time time;
    time.hours = secs / 3600;
    time.minutes = (secs - (time.hours * 3600)) / 60;
    time.seconds = (secs - (time.hours * 3600)) - (time.minutes * 60);
    return time;
}

long time_to_secs(Time time)
{
    return (time.hours * 3600 + time.minutes * 60 + time.seconds);
}