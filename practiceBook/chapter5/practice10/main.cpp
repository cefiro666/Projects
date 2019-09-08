#include <iostream>

using namespace std;

int counter;
void count();

int main()
{
    for(int i; i < 10; i++) count();
}

void count()
{
    counter++;
    cout << "Функция вызвана " << counter << " раз" << endl;
}