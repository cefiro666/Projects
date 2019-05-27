#pragma once
#include <map>

class Engine
{
public:
	virtual void step() = 0;

	// ����������� ����������� �������� ������� �� 
	// ��������� �������
	double cMoment;

	// ����������� ����������� �������� ������� �� 
	// �������� �������� ���������
	double cRotatSpeed;

	// ����������� ����������� �������� ���������� 
	// �� ����������� ��������� � ���������� �����
	double cTemp;

	// ����������� ���������� �����
	double mediumTemp;

	// �������� �������� ����
	double rotatSpeed;

	// ������ ������� ���������
	double Inert;

	// ����������� ��������� ���������
	double tempOverheat;

	// �������� ������� ���. ��������
	double heatRate;

	// �������� ���������� ���. ��������
	double coolRate;

	// ����������� ��������� ������� �� ��������
	// �������� ����
	std::map<double, double> addiction;
	std::map<double, double> ::iterator i, j;

	// �������� ������
	double M;

	// ��������� �������� ����
	double a;

	// ����������� ���������
	double engineTemp;

	// ����� ������ ���������
	double engineTime;
};

