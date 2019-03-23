#pragma once
#include <thread>
#include <iostream>
#include <array>

using namespace std;

// ����� ����� ��������� ����� ��������� ����������
// � ���� ��������� (���������)
// ���������� ����� �������� ����� ��� � ����-������� start (���� switch)
// 
//
// ������ ����� �������������� ����������:
// - ����������� �������� (��� 1)
//
// ��� ������� ��������� ���� ����-������� ���������
class Engine
{
private:
	// ��� ���������
	int type;

	// ��������� ���������
	bool condition;

	// ����������� ����������� �������� ������� �� 
	// ��������� �������
	float coef_M;

	// ����������� ����������� �������� ������� �� 
	// �������� �������� ���������
	float coef_rotat_speed;

	// ����������� ����������� �������� ���������� 
	// �� ����������� ��������� � ���������� �����
	float C;

	// ����������� ���������� �����
	float medium_temp;

	// �������� �������� ����
	float rotat_speed;

	// ������ ������� ���������
	float I;

	// ����������� ��������� ���������
	float temp_overheat;

	// �������� ������� ���. ��������
	float heat_rate;

	// �������� ���������� ���. ��������
	float cool_rate;

	// �������� ������
	float M;

	// ��������� �������� ����
	float a;

	// ����������� ���������
	float engine_temp = medium_temp;

	// ����� ������ ���������
	float engine_time;

	// ����������� ��������� ������� �� 
	// �������� �������� ����    
	array<float, 6> M_arr;
	array<float, 6> rotat_speed_arr;

public:
	// ������ ���������
	void start();

	// ��������� ���������
	void stop();

	// ��������� ��������� ����������� ��������
	void int_comb_simulation();

	friend int main();
	friend float overheating_time(float temp, Engine& engine);
};