#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Time
    {
        int hours;
        int minutes;
        int seconds;
        long total;
    };

    string hours,minutes,seconds;
    Time time1,time2,time3;

    cout << "Введите первое время (hh:mm:ss): ";
    getline(cin,hours,':');
    getline(cin,minutes,':');
    getline(cin,seconds);
    time1.hours = stoi(hours);
    time1.minutes = stoi(minutes);
    time1.seconds = stoi(seconds);
    time1.total = time1.hours*3600+time1.minutes*60+time1.seconds;

    cout << "Введите второе время (hh:mm:ss): ";
    getline(cin,hours,':');
    getline(cin,minutes,':');
    getline(cin,seconds);
    time2.hours = stoi(hours);
    time2.minutes = stoi(minutes);
    time2.seconds = stoi(seconds);
    time2.total = time2.hours*3600+time2.minutes*60+time2.seconds;

    time3.total = time1.total+time2.total;
    time3.hours = time3.total / 3600;
    time3.minutes = (time3.total - (time3.hours * 3600)) / 60;
    time3.seconds = (time3.total - (time3.hours * 3600)) - (time3.minutes * 60);
    
    cout << "Итоговое время " << time3.hours << ":" << time3.minutes
        << ":" << time3.seconds << endl;
}