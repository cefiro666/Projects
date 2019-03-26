#include <iostream>

using namespace std;

class Employee
{
private:
    int number;
    float salary;

public:
    void get_employee() const
    {
        cout << "Номер сотрудника " << number;
        cout << ", оклад сотрудника " << salary << endl;
    }

    void set_employee()
    {
        cout << "Введите номер сотрудника ";
        cin >> number;
        cout << "Введите оклад сотрудника ";
        cin >> salary;
    }
};

int main()
{
    Employee Jon, Stive, Don;
    Jon.set_employee();
    Stive.set_employee();
    Don.set_employee();
    Jon.get_employee();
    Stive.get_employee();
    Don.get_employee();
}