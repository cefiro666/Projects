#include "pch.h"
#include <string>
#include <iostream>	
#include <Windows.h>

using namespace std;

class Triangle {
public:
	int size;
	string symbol;
	void PrintTriangle() {
		for (int i = 1; i <= size; i++) {
			for (int z = 1; z <= i; z++) {
				cout << " " << symbol;
			}
			cout << endl;
		}
	}
	Triangle(int size, string symbol) {
		this->size = size;
		this->symbol = symbol;
	}
};

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size;
	string symbol;
	cout << "Введите размер основания треугольника: ";
	cin >> size;
	cout << "Введите символ рисования: ";
	cin >> symbol;

	Triangle one(size, symbol);
	one.PrintTriangle();

	cout << "Нажмите любую клавишу...";
	cin.get();
	cin.get();
}