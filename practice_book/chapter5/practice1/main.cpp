#include <iostream>

using namespace std;

float circarea(float);
int main()
{
    float rad;
    
    cout << "Введите радиус: ";
    cin >> rad;
    cout << "Площадь круга равна: " << circarea(rad) << endl;
}
float circarea(float rad)
{   
    const float pi = 3.14;
    return pi*rad*rad;
}
