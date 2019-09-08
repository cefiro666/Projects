#include <iostream>

using namespace std;

int main()
{
    struct Employee
    {
        int number;
        float allowance;
    };
    Employee employee1;
    Employee employee2;
    Employee employee3;
    cout << "Введите номер и пособие первого сотрудника: ";
    cin >> employee1.number >> employee1.allowance;
    cout << "Введите номер и пособие второго сотрудника: ";
    cin >> employee2.number >> employee2.allowance;
    cout << "Введите номер и пособие третьего сотрудника: ";
    cin >> employee3.number >> employee3.allowance;
    cout << "Номер и пособие первого сотрудника: " << employee1.number
    << ", " << employee1.allowance << endl;
    cout << "Номер и пособие второго сотрудника: " << employee2.number
    << ", " << employee2.allowance << endl;
    cout << "Номер и пособие третьего сотрудника: " << employee3.number
    << ", " << employee3.allowance << endl;
}