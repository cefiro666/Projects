#include <iostream>
#include <string>

using namespace std;

struct Fraction
{
    int numerator;
    int denominator;
};

Fraction fadd(Fraction, Fraction);
Fraction fsub(Fraction, Fraction);
Fraction fmul(Fraction, Fraction);
Fraction fdiv(Fraction, Fraction);


int main()
{
    string numerator;
    string denominator;

    Fraction fraction1;
    Fraction fraction2;

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
    cout << "Сумма дробей равна " << fadd(fraction1, fraction2).numerator << "/" 
        << fadd(fraction1, fraction2).denominator << endl;
    cout << "Разность дробей равна " << fsub(fraction1, fraction2).numerator << "/" 
        << fsub(fraction1, fraction2).denominator << endl;
    cout << "Произведение дробей равно " << fmul(fraction1, fraction2).numerator << "/" 
        << fmul(fraction1, fraction2).denominator << endl;
    cout << "Частное дробей равно " << fdiv(fraction1, fraction2).numerator << "/" 
        << fdiv(fraction1, fraction2).denominator << endl;
        
    
}

Fraction fadd(Fraction fraction1, Fraction fraction2)
{
    Fraction rezult;
    rezult.numerator = (fraction1.numerator*fraction2.denominator)
        +(fraction1.denominator*fraction2.numerator);
    rezult.denominator = fraction1.denominator*fraction2.denominator;
    return rezult;
}

Fraction fsub(Fraction fraction1, Fraction fraction2)
{
    Fraction rezult;
    rezult.numerator = (fraction1.numerator*fraction2.denominator)
        -(fraction1.denominator*fraction2.numerator);
    rezult.denominator = fraction1.denominator*fraction2.denominator;
    return rezult;
}

Fraction fmul(Fraction fraction1, Fraction fraction2)
{
    Fraction rezult;
    rezult.numerator = fraction1.numerator*fraction2.numerator;
    rezult.denominator = fraction1.denominator*fraction2.denominator;
    return rezult;
}

Fraction fdiv(Fraction fraction1, Fraction fraction2)
{
    Fraction rezult;
    rezult.numerator = fraction1.numerator*fraction2.denominator;
    rezult.denominator = fraction1.denominator*fraction2.numerator;
    return rezult;
}
