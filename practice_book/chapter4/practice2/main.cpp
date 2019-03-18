#include <iostream>

using namespace std;

int main ()
{
    struct Point
    {
        int x;
        int y;
    };
    Point point1;
    Point point2;
    Point point3;
    cout << "Введите координаты первой точки(x,y): ";
    cin >> point1.x >> point1.y;
    cout << "Введите координаты второй точки(x,y): ";
    cin >> point2.x >> point2.y;
    point3.x = point1.x + point2.x;
    point3.y = point1.y + point2.y;
    cout << "Координаты третьей точки (сумма): ";
    cout << "x = " << point3.x << ", y = " << point3.y << endl;
}