// упражнение 1

#include "pch.h"
#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	struct Number
	{
		unsigned int city_code;
		unsigned int station_number;
		unsigned int subscriber_number;
	};

	Number my_number = { 212,767,8900 };
	Number your_number;

    cout << "Введите код города, номер станции и номер абонента:\n";

	cin >> your_number.city_code >> your_number.station_number 
		>>your_number.subscriber_number;

	cout << "Мой номер (" << my_number.city_code << ") " 
		<< my_number.station_number << "-" 
		<< my_number.subscriber_number << endl;

	cout << "Ваш номер (" << your_number.city_code << ") " 
		<< your_number.station_number << "-" 
		<< your_number.subscriber_number << endl;
}
