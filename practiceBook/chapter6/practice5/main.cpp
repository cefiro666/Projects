#include <iostream>
#include <string>

using namespace std;

class Date
{
private:
    int day;
    int month;
    int year;

public:
    void setDate()
    {
        string sDay;
        string sMonth;
        string sYear;
        cout << "Введите дату в формате dd/mm/yyyy: ";
        getline(cin,sDay,'/');
        getline(cin,sMonth,'/');
        getline(cin,sYear);
        day = stoi(sDay);
        month = stoi(sMonth);
        year = stoi(sYear);
    }
    void showDate()
    {
        cout << day << "/" << month << "/" << year << endl;
    }
};

int main()
{
    Date date;
    date.setDate();
    date.showDate();
}