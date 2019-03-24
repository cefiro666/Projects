#include <iostream>

using namespace std;

double power(double number, int power);
double power(char number, int power);
double power(int number, int power);
double power(long number, int power);
double power(float number, int power);

int main()
{
    double d_number;
    char c_number;
    int i_number;
    long l_number;
    float f_number;
    int pow;
    cout << "Введите число и степень через пробел: ";
    cin >> d_number >> pow;
     c_number = i_number = l_number = f_number = d_number;
    cout << "Результат для d: " << power(d_number, pow) << endl;
    cout << "Результат для c: " << power(c_number, pow) << endl;
    cout << "Результат для i: " << power(i_number, pow) << endl;
    cout << "Результат для l: " << power(l_number, pow) << endl;
    cout << "Результат для f: " << power(f_number, pow) << endl;
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

double power(char number, int power=2)
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

double power(int number, int power=2)
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

double power(long number, int power=2)
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

double power(float number, int power=2)
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