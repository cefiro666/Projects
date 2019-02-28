//���������� ������ Readings, ����������� ���������� � ���������� �������
#pragma once
#include "calculations.h"
#include <string>
#include <iostream>	
#include <fstream>
#include <iomanip>

using namespace std;

//����� ��� �������� ��������� ��������� � ���, � �������
class Readings {

private:
	//������ ���� ��������� ���
	string date; 
	// ������ ��� �������� ��������� ��������: 
	//[0]-������� �����,											
	//[1]-�������� �����, 																
	//[2]-������� �����, 																
	//[3]-�������� �����, 																
	//[4]-�������
	float Arr_readings[5];
	//����� �������������
	float drainage_tariff;
	//����� �� �������� ����
	float cold_water_tariff;
	//����� �� ������� ����
	float hot_water_tariff;
	//����� ��������������
	float electricity_tariff;

public:	
	//�������, ��������� � ������ ����
	string get_date();
	void set_date(string date);	
	void print_date();
	//������� � ��������� �������� �������
	float get_drainage_tariff();
	void set_drainage_tariff(float value);
	float get_cold_water_tariff();
	void set_cold_water_tariff(float value);
	float get_hot_water_tariff();
	void set_hot_water_tariff(float value);
	float get_electricity_tariff();
	void set_electricity_tariff(float value);
	//�������, ��������� � ������ ���������
	float get_readings(int i); 
	void set_readings(int i, float value);
	void print_readings(int i);
	//������ ����� ������ � ������ ������ (����, ���������) �� �����
	void write(string path);
	void read(string path);
	//������������� ������� � ������
	friend void fill_present_readings(Readings &present_readings);
	friend void Calculations::calculation(Readings &present_readings, Readings &post_readings);
	friend void set_tariff(Readings &present_readings, Readings &post_readings, Calculations &calc);
};