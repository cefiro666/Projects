//����������� ������� ������ �alculations
#include "pch.h"
#include "calculations.h"
#include "readings.h"

float Calculations::get_sum_cost() { return sum_cost; }
void Calculations::set_sum_cost(float value) { sum_cost = value; }
float Calculations::get_sum_expenditure() { return sum_expenditure; }
void Calculations::set_sum_expenditure(float value) { sum_expenditure = value; }
float Calculations::get_expenditure(int i) { return Arr_calculations[0][i]; }
float Calculations::get_cost(int i) { return Arr_calculations[2][i]; }
void Calculations::set_expenditure(int i, float value) { Arr_calculations[0][i] = value; }
void Calculations::set_cost(int i, float value) { Arr_calculations[2][i] = value; }
void Calculations::calculation(Readings &present_readings, Readings &post_readings) {
	//��������� �������� ������� �� ����� � �������� �������
	Arr_calculations[1][0] = Arr_calculations[1][2] = present_readings.get_hot_water_tariff();
	Arr_calculations[1][1] = Arr_calculations[1][3] = present_readings.get_cold_water_tariff();
	Arr_calculations[1][4] = present_readings.get_electricity_tariff();
	//������� �������� ������� � ��������� �� ������� ������� � ���������� �������� ���������
	for (int i = 0; i < 5; i++) {
		//������� �������
		Arr_calculations[0][i] = present_readings.get_readings(i) - post_readings.get_readings(i);
		//������ ��������� �� ������ � �������
		Arr_calculations[2][i] = Arr_calculations[1][i] * Arr_calculations[0][i];
		//�������� � �������� ���������
		sum_cost += Arr_calculations[2][i]; 
		//��������  � ��������� ���������� ������� �� ���� (������ ��� ����)
		if (i < 4) {
			sum_expenditure += Arr_calculations[0][i];
		}
	}
	//�������� ��������� �� �������������
	sum_cost += present_readings.get_drainage_tariff() * sum_expenditure;
}