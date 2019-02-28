//��������������� �������
#pragma once
#include "calculations.h"
#include "readings.h"
#include <string>
#include <iostream>	
#include <time.h>
#include <lmcons.h>
#include <Windows.h>

using namespace std;

//���������� ��� �������� ������������ � �������
string get_username() {
	char buffer[UNLEN + 1];
	DWORD size;
	size = sizeof(buffer);
	GetUserNameA(buffer, &size);
	string username = buffer;
	return username;
}
//���������� ������������� ���� ����� ������
string get_path() {
	string path = "C:/Users/" + get_username() + "/Documents/datacalc.txt";
	return path;
}
//�������� ����������� ����� ������ � �������� ������ ����� 
void check_file() {
	//�������� ��������� ������ �� ������
	ifstream in(get_path(), ios_base::in);
	//���� �� �������� ����
	if (!in.is_open()) {
		cout << "\n ������, ��� ��� ������ ������ ��������� (���� �� ������ ���� ������).\n ���������� ������� ����� ���� ������.\n\n";
		//���������� ��� ������ ���� ������ � ����� ����
		string date;
		float cold_tariff, hot_tariff, drainage_tariff, electricity_tariff, readings_cold_bathroom, readings_hot_bathroom, readings_cold_kitchen, readings_hot_kitchen, readings_electricity;
		bool true_in = false;
		int value;
		//���� ��� ���������� ����� ���������� � ������ ������
		while (!true_in) {
			bool true_in_value = false;
			cout << " ������� ���� �������� ��������� ������� (xx.yy.zzzz xx - �����, yy - �����, zzzz - ���): ";
			cin >> date;
			cout << " ������� ���� �� �������� ������� ����: ";
			cin >> hot_tariff;
			cout << " ������� ���� �� �������� �������� ����: ";
			cin >> cold_tariff;
			cout << " ������� ���� �� �������� ���������� ����: ";
			cin >> drainage_tariff;
			cout << " ������� ���� �� ��������/��� ��������������: ";
			cin >> electricity_tariff;
			cout << " ������� ��������� �������� ������� ���� � ������: ";
			cin >> readings_hot_bathroom;
			cout << " ������� ��������� �������� �������� ���� ������: ";
			cin >> readings_cold_bathroom;
			cout << " ������� ��������� ������� ���� �� �����: ";
			cin >> readings_hot_kitchen;
			cout << " ������� ��������� �������� ���� �� �����: ";
			cin >> readings_cold_kitchen;
			cout << " ������� ��������� ���������������: ";
			cin >> readings_electricity;
			cout << "\n ��������� ������ �����?\n �� (1)/ ��� (2)\n ��� �����... ";
			//���� ��� �������� ������������ ������
			while (!true_in_value) {
				cin >> value;
				if (char(value) == 1) {
					//�������� ��������� ������ �� ������ ������ �����
					ofstream new_file(get_path());
					//���� ���� ��������
					if (new_file.is_open()) {
						//������ �������, ���� � ��������� � ����� ����
						new_file << hot_tariff << " " << cold_tariff << " " << electricity_tariff << " " << drainage_tariff << "\n" << date << "\n" << readings_hot_bathroom << "\n" << readings_cold_bathroom << "\n" << readings_hot_kitchen << "\n" << readings_cold_kitchen << "\n" << readings_electricity;
						new_file.close();
						cout << "\n ���� ������ ������� ������!\n";
						//����� �� ������
						true_in = true;
						true_in_value = true;
					} else {
						cout << "\n ������ �������� �����. �������� ���� ������� �� ������.\n ���������� ��������� ������ �� ��������-������� � ���������� windows.\n";
					}
				} else if (char(value) == 2) {
					cout << "\n ����� ��������� ���� ������...\n";
					//����� �� ����� �������� �����
					true_in_value = true;
				} else {
					cout << " �������� ����. ���������... ";
				}
			}
		}
	}
}
//���������� ������� ���� � ������� dd.mm.yyyy
const string get_present_date() {
#pragma warning(disable: 4996)
	time_t now = time(0);
	struct tm tstruct;
	char buf[11];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%d.%m.%Y", &tstruct);
	return buf;
}
//���� � ������ � ������ �������� ��������� ��������� � ����
void fill_present_readings(Readings &present_readings) {
	cout << " ������� ������ ��������� �� ����������� ����:\n";
	float value;
	string question[5] = { " -������� ���� � ������: ",
							" -�������� ���� � ������: ",
							" -������� ���� � �����: ",
							" -�������� ���� � �����: ",
							" -���������������: " };
	for (int i = 0; i < 5; i++) {
		cout << question[i];
		cin >> value;
		present_readings.set_readings(i, value);
	}
	//������ �������� ���� � ������
	present_readings.set_date(get_present_date()); 
}
//������� ��������� �������
void set_tariff(Readings &present_readings, Readings &post_readings, Calculations &calc) {
	cout << " ���� �� ������������� �������� ������?\n ��, �������� (1) / ���������� ��� ��������� (2)\n ��� �����... ";
	int value;
	bool true_in = false;
	//���� ��� ����������� �����
	while (!true_in) {
		cin >> value;
		switch (char(value)) {
		case 1:
			float value;
			cout << "\n ������. ������� ��������� ����� ������:\n";
			cout << " -�� 1 �������� ������� ���� (���.): ";
			cin >> value;
			present_readings.set_hot_water_tariff(value);
			cout << " -�� 1 �������� �������� ���� (���.): ";
			cin >> value;
			present_readings.set_cold_water_tariff(value);
			cout << "  �� 1 ��������/��� �������������� (���.): ";
			cin >> value;
			present_readings.set_electricity_tariff(value);
			cout << " -�� 1 �������� ���������� ���� (���.): ";
			cin >> value;
			present_readings.set_drainage_tariff(value);
			//��������� ������� �������� ���������� ��� ���������
			calc.set_sum_cost(0);
			calc.set_sum_expenditure(0);
			//����� �� �����
			true_in = true;
			break;
		case 2:
			//���������� ����������, ���������� ������ ������� �������(�� �����)
			present_readings.set_hot_water_tariff(post_readings.get_hot_water_tariff());
			present_readings.set_cold_water_tariff(post_readings.get_cold_water_tariff());
			present_readings.set_drainage_tariff(post_readings.get_drainage_tariff());
			present_readings.set_electricity_tariff(post_readings.get_electricity_tariff());
			//��������� ������� �������� ���������� ��� ���������
			calc.set_sum_cost(0);
			calc.set_sum_expenditure(0);
			//����� �� �����
			true_in = true;
			break;
		default:
			cout << " �������� ����. ���������... ";
			break;
		}
	}
}