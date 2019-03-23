#include <iostream>

using namespace std;

void swap(int&, int&);

int main()
{
    int value1, value2;
    cout << "Введите два числа через пробел: ";
    cin >> value1 >> value2;
    swap(value1, value2);
    cout << "Первое число: " << value1 << ", второе число: " << value2 << endl;
}

void swap(int& value1,int& value2)
{
    int temp = value1;
    value1 = value2;
    value2 = temp;
}
