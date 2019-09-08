#include <iostream>
#include <string>

using namespace std;

int main()
{
    enum Etype { laborer,secretary,manager,accountant,executive };
    struct Date
    {
        int day;
        int month;
        int year;
    };
    struct Employee
    {
        string name;
        int number;
        float allowance;
        Etype type;
        Date date;
        string value_type;
    };

    char var;
    string value,day,month,year;
    int count;

    cout << "Информацию о скольки сотрудниках вы хотите ввести? ";
    cin >> count;

    Employee arr[count];
    for (int i=0; i<count; i++)
    {
        cout << "Ввод информации о сотруднике " << i << endl;
        cout << "Введите имя сотрудника ";
        cin >> arr[i].name;
        cout << "Введите номер сотрудника ";
        cin >> arr[i].number;
        cout << "Введите зарплату сотрудника: ";
        cin >> arr[i].allowance;
        cout << "Введите первую букву названия должности сотрудника\n(laborer,secretary,manager,accountant,executive)... ";
        cin >> var;
        switch (var)
        {
            case 'l':
                arr[i].type = laborer;
                arr[i].value_type = "laborer";
                break;
            case 's':
                arr[i].type = secretary;
                arr[i].value_type = "secretary";
                break;
            case 'm':
                arr[i].type = manager;
                arr[i].value_type = "manager";
                break;
            case 'a':
                arr[i].type = accountant;
                arr[i].value_type = "accountant";
                break;
            case 'e':
                arr[i].type = executive;
                arr[i].value_type = "executive";
                break;
            default:
                cout << "Неверный ввод!" << endl;
                break;
        }
        cout << "Введите дату в формате dd/mm/yyyy: ";
        getline(cin,day,'/');
        getline(cin,month,'/');
        getline(cin,year);
        arr[i].date.day = stoi(day);
        arr[i].date.month = stoi(month);
        arr[i].date.year = stoi(year);
    }

    for (int i=0; i<count; i++)
    {

        cout << "\nИнофрмация о сотруднике " << arr[i].name << endl;
        cout << "Номер " << arr[i].number << endl;
        cout << "Зарплата " << arr[i].allowance << endl;
        cout << "Должность " << arr[i].value_type << endl;
        cout << "Дата принятия на работу " << arr[i].date.day << "/" << arr[i].date.month
            << "/" << arr[i].date.year << endl;
    }
}