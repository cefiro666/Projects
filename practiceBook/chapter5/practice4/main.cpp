#include <iostream>

using namespace std;

struct Distance
{
    int feet;
    float inches;
};

Distance comparison(Distance, Distance);
int main()
{
    Distance distance1, distance2, max_distance;
    cout << "Введите первую дистанцию (футы дюймы): ";
    cin >> distance1.feet >> distance1.inches;
    cout << "Введите второую дистанцию (футы дюймы): ";
    cin >> distance2.feet >> distance2.inches;
    max_distance = comparison(distance1, distance2);
    cout << "Значение максимальной дистанции " << max_distance.feet << " футов " 
        << max_distance.inches << " дюймов" << endl;
}

Distance comparison(Distance distance1, Distance distance2)
{
    if ((distance1.feet * 12 + distance1.inches) > (distance2.feet * 12 + distance2.inches))
    {
         return distance1;
    } 
    else
    {
         return distance2;
    }
}
