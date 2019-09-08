#include <iostream>

using namespace std;

long hms_to_secs(int hours, int minutes, int seconds);

int main() 
{
    while (true)
    {
        int hours, minutes, seconds;
        cout << "Введите значение времни (hh mm ss): ";
        cin >> hours >> minutes >> seconds;
        cout << "Время в секндах: " << hms_to_secs(hours, minutes, seconds) << endl;
    }
    
}

long hms_to_secs(int hours, int minutes, int seconds)
{
    return (hours * 3600 + minutes * 60 + seconds);
}
