#include <iostream>

using namespace std;

int main()
{
    struct Time
    {
        int hours;
        int minutes;
        int seconds;
    };
    Time time;
    cout << "Введите время (часы, минуты, секунды): ";
    cin >> time.hours >> time. minutes >> time.seconds;
    long total_secs = time.hours*3600+time.minutes*60+time.seconds;
    cout << "Время в секундах - " << total_secs << endl;
}