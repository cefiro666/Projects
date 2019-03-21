#include <iostream>

using namespace std;

double power(double number, int power);
int main()
{
    double number;
    int power;
    cout << "Введите число и степень через пробел: ";
    cin >> number >> power;
    cout << "Результат: " << power(number, power) << endl;
}
double power(double number, int power=2)
{
    double rezult = number;
    if (power == 0) 
    {
       rezult = 1;
    } 
    else if (power == 1) 
    {
        rezult = power;
    } 
    else 
    {
        while (power != 1)
        {
            rezult *= number;
            power--;
        }
    }
    return rezult;
}
