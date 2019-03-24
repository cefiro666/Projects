#include <iostream>
#include <string>

using namespace std;

int main()
{
    struct Fraction
    {
        int numerator;
        int denominator;
    };

    string numerator;
    string denominator;

    Fraction fraction1;
    Fraction fraction2;
    Fraction fraction3;

    cout << "Подсчет суммы дробей\n";
    cout << "Введите первую дробь в виде x/y ";
    getline(cin,numerator,'/');
    getline(cin,denominator);
    fraction1.numerator = stoi(numerator);
    fraction1.denominator = stoi(denominator);
    cout << "Введите вторую дробь в виде x/y ";
    getline(cin,numerator,'/');
    getline(cin,denominator);
    fraction2.numerator = stoi(numerator);
    fraction2.denominator = stoi(denominator);
    fraction3.numerator = (fraction1.numerator*fraction2.denominator)
        +(fraction1.denominator*fraction2.numerator);
    fraction3.denominator = fraction1.denominator*fraction2.denominator;
    if (fraction3.numerator == fraction3.denominator)
    {
        cout << "\nСумма дробей равна 1" << endl;
    } else {
        cout << "\nСумма дробей равна " << fraction3.numerator << "/" 
            << fraction3.denominator << endl;
    }
}
