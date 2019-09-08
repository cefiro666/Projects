#include <iostream>
#include <string>

using namespace std;
   
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

void swap(Time&, Time&);

int main()
{
    string hours,minutes,seconds;
    Time time1,time2;

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

    swap(time1, time2);

    cout << "Первое время: " << time1.hours <<":" << time1.minutes 
        << ":" << time1.seconds << ", второе время: " << time2.hours
        << ":" << time2.minutes << ":" << time2.seconds
        << endl;
}

void swap(Time& time1, Time& time2)
{
    Time temp = time1;
    time1 = time2;
    time2 = temp;
}

