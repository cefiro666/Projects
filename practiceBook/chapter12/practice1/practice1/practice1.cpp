
#include <fstream>
#include <iostream>

using namespace std;

class Distance 
{
private:
	int feet;
	float inches;
public:
	void setdist(int ft, float in)
	{
		feet = ft; inches = in;
	}
	void getdist() 
	{
		cout << "\nВведите число футов: "; cin >> feet;
		cout << "Введите число дюймов: "; cin >> inches;
	}
	void showdist() 
	{
		cout << feet << "\'-" << inches << '\"';
	}
};

int main()
{
	system("chcp 1251");

	char ch;
	Distance dist;
	fstream file;
						  
	file.open("GROUP.DAT", ios::app | ios::out | ios::in | ios::binary);

	do {
		cout << "\nВведите истанцию:";
		dist.getdist(); 
		file.write(reinterpret_cast<char*>(&dist), sizeof(dist));
		cout << "Продолжить ввод (y/n)? ";
		cin >> ch;
	} while (ch == 'y'); 

	file.seekg(0); 
	file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
	while (!file.eof())
	{
		cout << "\nДистанция:";
		dist.showdist(); 
		file.read(reinterpret_cast<char*>(&dist), sizeof(dist));
	}
	cout << endl;
}


