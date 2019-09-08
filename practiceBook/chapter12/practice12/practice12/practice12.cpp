﻿// empl_io.cpp
// Файловый ввод/вывод объектов employee
// Поддержка объектов неодинаковых размеров
#include <fstream>      // для потоковых файловых функций
#include <iostream>
#include <typeinfo>     // для typeid()
using namespace std;
#include <process.h>    // для exit()

const int LEN = 32;     // Максимальная длина фамилий
const int MAXEM = 100;  // максимальное число работников

enum employee_type { tmanager, tscientist, tlaborer };
///////////////////////////////////////////////////////////
class employee                // класс employee 
{
private:
	char name[LEN];           // фамилия работника
	unsigned long number;     // номер работника
	static int n;             // текущее число работников
	static employee* arrap[]; //массив указателей на
							  // класс работников
public:
	virtual void getdata()
	{
		cin.ignore(10, '\n');
		cout << "  Введите фамилию: "; cin >> name;
		cout << "  Введите номер: ";    cin >> number;
	}
	virtual void putdata()
	{
		cout << "\n  Фамилия: " << name;
		cout << "\n  Номер: " << number;
	}
	virtual employee_type get_type(); // получить тип
	static void add();                // добавить работника
	static void display();            // вывести данные обо всех
	static void read();               // чтение из файла
	static void write();              // запись в файл
	static void find(unsigned long);              // запись в файл
};
//---------------------------------------------------------
//статические переменные
int employee::n;                  // текущее число работников
employee* employee::arrap[MAXEM]; // массив указателей на
								  // класс работников
///////////////////////////////////////////////////////////
//класс manager (менеджеры)
class manager : public employee
{
private:
	char title[LEN];  // титул ("вице-президент" и т. п.)
	double dues;      // Налоги гольф-клуба
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите титул: "; cin >> title;
		cout << "  Введите налоги: "; cin >> dues;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  Титул: " << title;
		cout << "\n  Налоги гольф-клуба: " << dues;
	}
};
///////////////////////////////////////////////////////////
//класс scientist (ученые)
class scientist : public employee
{
private:
	int pubs;              // число публикаций
public:
	void getdata()
	{
		employee::getdata();
		cout << "  Введите число публикаций: "; cin >> pubs;
	}
	void putdata()
	{
		employee::putdata();
		cout << "\n  Число публикаций: " << pubs;
	}
};
///////////////////////////////////////////////////////////
//класс laborer (рабочие)
class laborer : public employee
{
};
///////////////////////////////////////////////////////////
//добавить работника в список (хранится в ОП)
void employee::add()
{
	char ch;
	cout << "'m' для добавления менеджера"
		"\n's' для добавления ученого"
		"\n'l' для добавления рабочего"
		"\nВаш выбор: ";
	cin >> ch;
	switch (ch)
	{          //создать объект указанного типа
	case 'm': arrap[n] = new manager;  break;
	case 's': arrap[n] = new scientist; break;
	case 'l': arrap[n] = new laborer;  break;
	default: cout << "\nНеизвестный тип работника\n"; return;
	}
	arrap[n++]->getdata();  //Получить данные от пользователя
}
//---------------------------------------------------------

void employee::find(unsigned long num)
{
	employee* emp;
	bool isFind = false;
	int size;               // размер объекта employee 
	employee_type etype;    // тип работника
	ifstream inf;           // открыть ifstream в двоичном виде
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\nНевозможно открыть файл\n"; return;
	}
	n = 0;                
	while (!isFind && !inf.eof())
	{                    
		inf.read((char*)& etype, sizeof(etype));
		if (inf.eof())   
			break;
		if (!inf)       
		{
			cout << "\nНевозможно чтение типа\n"; return;
		}
		switch (etype)
		{               
		case tmanager: 
			emp = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			emp = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			emp = new laborer;
			size = sizeof(laborer);
			break;
		default: cout << "\nНеизвестный тип в файле\n"; return;
		}     

		inf.read((char*)emp, size);

		if (!inf) 
		{
			cout << "\nЧтение данных из файла невозможно\n"; return;
		}

		if (emp->number == num)
		{
			cout << "Найденный работник:\n";
			emp->putdata();
			cout << endl;
			isFind = true;
		}
	}
	if (!isFind) cout << "Не найдено!\n";
}


//Вывести данные обо всех работниках
void employee::display()
{
	for (int j = 0; j < n; j++)
	{
		cout << (j + 1);                // вывести номер
		switch ((*arrap[j]).get_type()) //вывести тип 
		{
		case tmanager:  cout << ". Тип: Менеджер";  break;
		case tscientist: cout << ". Тип: Ученый"; break;
		case tlaborer:   cout << ". Тип: Рабочий";  break;
		default: cout << ". Неизвестный тип";
		}
		arrap[j]->putdata();           // Вывод данных
		cout << endl;
	}
}
//---------------------------------------------------------
//Возврат типа объекта
employee_type employee::get_type()
{
	if (typeid(*this) == typeid(manager))
		return tmanager;
	else if (typeid(*this) == typeid(scientist))
		return tscientist;
	else if (typeid(*this) == typeid(laborer))
		return tlaborer;
	else
	{
		cerr << "\nНеправильный тип работника"; exit(1);
	}
	return tmanager;
}
//---------------------------------------------------------
//Записать все объекты, хранящиеся в памяти, в файл
void employee::write()
{
	int size = 0;
	cout << "Идет запись " << n << " работников.\n";
	ofstream ouf;           // открыть ofstream в двоичном виде
	employee_type etype;   // тип каждого объекта employee

	ouf.open("EMPLOY.DAT", ios::trunc | ios::binary);
	if (!ouf)
	{
		cout << "\nНевозможно открыть файл\n"; return;
	}
	for (int j = 0; j < n; j++)  // Для каждого объекта
	{                     // получить его тип
		etype = arrap[j]->get_type();
		// записать данные в файл
		ouf.write((char*)& etype, sizeof(etype));
		switch (etype)         // find its size
		{
		case tmanager:  
			size = sizeof(manager); 
			break;
		case tscientist: 
			size = sizeof(scientist);
			break;
		case tlaborer:  
			size = sizeof(laborer); 
			break;
		}   
		ouf.write((char*)arrap[j], size);
		if (!ouf)
		{
			cout << "\nЗапись в файл невозможна\n"; return;
		}
	}
}
//---------------------------------------------------------
//чтение всех данных из файла в память
void employee::read()
{
	int size;               // размер объекта employee 
	employee_type etype;    // тип работника
	ifstream inf;           // открыть ifstream в двоичном виде
	inf.open("EMPLOY.DAT", ios::binary);
	if (!inf)
	{
		cout << "\nНевозможно открыть файл\n"; return;
	}
	n = 0;                  // В памяти работников нет
	while (true)
	{                     // чтение типа следующего работника
		inf.read((char*)& etype, sizeof(etype));
		if (inf.eof())       // выход из цикла по EOF
			break;
		if (!inf)              // ошибка чтения типа
		{
			cout << "\nНевозможно чтение типа\n"; return;
		}
		switch (etype)
		{                   // создать нового работника
		case tmanager:      // корректного типа
			arrap[n] = new manager;
			size = sizeof(manager);
			break;
		case tscientist:
			arrap[n] = new scientist;
			size = sizeof(scientist);
			break;
		case tlaborer:
			arrap[n] = new laborer;
			size = sizeof(laborer);
			break;
		default: cout << "\nНеизвестный тип в файле\n"; return;
		}                   // чтение данных из файла
		inf.read((char*)arrap[n], size);
		if (!inf)              // ошибка, но не EOF
		{
			cout << "\nЧтение данных из файла невозможно\n"; return;
		}
		n++;
	} 
	cout << "Идет чтение " << n << " работников\n";
}
///////////////////////////////////////////////////////////
int main()
{
	system("chcp 1251");

	char ch;
	while (true)
	{
		cout << "'a' – добавление сведений о работнике"
			"\n'd' - вывести сведения обо всех работниках"
			"\n'w' – записать все данные в файл"
			"\n'r' – прочитать все данные из файла"
			"\n'f' – найти работника в файле по номеру"
			"\n'x' - выход"
			"\nВаш выбор: ";
		cin >> ch;
		switch (ch)
		{
		case 'a':           // добавить работника
			employee::add(); break;
		case 'd':           // вывести все сведения
			employee::display(); break;
		case 'w':           // запись в файл
			employee::write(); break;
		case 'r':           // чтение всех данных из файла
			employee::read(); break;
		case 'f':           // чтение всех данных из файла
			int number;
			cout << "Введите номер сотрудника для поиска инфы о нем... ";
			cin >> number;
			employee::find(number); break;
		case 'x': exit(0);  // выход
		default: cout << "\nНеизвестная команда";
		}  //end switch
	}  //end while
	return 0;
}  //end main()


