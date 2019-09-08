#include <iostream>
#include <string>

using namespace std;

int main()
{
    enum Etype { laborer,secretary,manager,accountant,executive };
    Etype type;
    char var;
    string value;
    cout << "Введите первую букву названия должности\n(laborer,secretary,manager,accountant,executive)... ";
    cin >> var;
    switch (var)
    {
        case 'l':
            type = laborer;
            value = "laborer";
            break;
        case 's':
            type = secretary;
            value = "secretary";
            break;
        case 'm':
            type = manager;
            value = "manager";
            break;
        case 'a':
            type = accountant;
            value = "accountant";
            break;
        case 'e':
            type = executive;
            value = "executive";
            break;
        default:
            cout << "Неверный ввод!" << endl;
            break;
    }
    cout << "Выбранная должность - " << value << endl;
}