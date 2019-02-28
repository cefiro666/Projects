//���������� ������ Calculations, ����������� ���������� � ���������� �������
//���������� � ���������� ������� � ���������� ������
#pragma once
#include <string>
#include <iostream>	

using namespace std;

//���������� ������ Readings ��� ���������� ������ �������
class Readings;
//����� ���������� �������� � ������ �������� ��������, 
//������� � ��������� �� ������� �� ���������
class Calculations {

private:
	// ����������� ������ � ���������� (������/�����/���������)
	//[0,0] - ������ �� ������� ���� � ������
	//[0,1] - ������ �� �������� ���� � ������
	//[0,2] - ������ �� ������� ���� � �����
	//[0,3] - ������ �� �������� ���� � �����
	//[0,4] - ������ �� �������������
	//[1,0],[1,2] - ����� �� ������� ����
	//[1,1],[1,3] - ����� �� �������� ����
	//[1,4] - ����� �� �������������
	//[2,0] - ��������� ������� ���� � ������
	//[2,1] - ��������� �������� ���� � ������
	//[2,2] - ��������� ������� ���� � �����
	//[2,3] - ��������� �������� ���� � �����
	//[2,4] - ��������� ��������������
	float Arr_calculations[3][5]; 
	//�������� ��������� �� ������
	float sum_cost; 
	//�������� ������ ����
	float sum_expenditure; 

public:
	//������� � ��������� �������� ���������
	float get_sum_cost();
	void set_sum_cost(float value);
	//������� � ��������� ��������� �������
	float get_sum_expenditure();
	void set_sum_expenditure(float value);
	//������� � ��������� �������� �������
	float get_expenditure(int i);
	void set_expenditure(int i, float value);
	//������� � ��������� ��������� �������� �� ������ ����������
	float get_cost(int i);
	void set_cost(int i, float value);
	//������� ������� � ��������� ��������
	void calculation(Readings &present_readings, Readings &post_readings);
	//������������� �������
	friend void set_tariff(Readings &present_readings, Readings &post_readings, Calculations &calc);
};