#include <iostream>

using namespace std;

void count();

int main()
{
    for(int i; i < 10; i++) count();
}

void count()
{
    static int counter;
    counter++;
    cout << "Функция вызвана " << counter << " раз" << endl;
}