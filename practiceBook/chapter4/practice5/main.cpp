#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Date
    {
        int day;
        int month;
        int year;
    };
    Date date1;
    string day;
    string month;
    string year;
    cout << "Введите дату в формате dd/mm/yyyy: ";
    getline(cin,day,'/');
    getline(cin,month,'/');
    getline(cin,year);
    date1.day = stoi(day);
    date1.month = stoi(month);
    date1.year = stoi(year);
    cout << "Введенная дата " << date1.day << "/" 
    << date1.month << "/" << date1.year << endl;
}