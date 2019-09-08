#include <iostream>

using namespace std;

void zero_smaller(int&, int&);
int main()
{
    int number1 = 114;
    int number2 = 240;
    zero_smaller(number1,number2);
    cout << number1 << " " << number2 << endl;
}
void zero_smaller(int& number1, int& number2)
{
    if (number1 < number2)
    {
        number1 = 0;
    } else if (number1 > number2)
    {
        number2 = 0;
    }
}
