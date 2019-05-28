#pragma once
#include <map>

class Engine
{
public:
	virtual void stepSimulation() = 0;

	virtual void resetEngine() = 0;

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
	double overheatTemp;

	// �������� ������� ���. ��������
	double heatRate;

	// �������� ���������� ���. ��������
	double coolRate;

	// ����������� ��������� ������� �� ��������
	// �������� ����
	std::map<double, double> addiction;

	// �������� ������
	double M;

	// ��������� �������� ����
	double a;

	// ����������� ���������
	double engineTemp;

	// ����� ������ ���������
	double engineTime;
};