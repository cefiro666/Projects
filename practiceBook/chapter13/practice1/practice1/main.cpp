// vl_app.cpp
// ��������� ���������� ������� �����
#include "verylong.h"    //������������ ���� verylong

int main()
{
	system("chcp 1251");
	unsigned long numb, j;
	verylong fact = 1;       //���������������� verylong

	cout << "\n\n������� �����: ";
	cin >> numb;           //���� ����� ���� long int

	for (j = numb; j > 0; j--)  //��������� � ��� numb *
		fact = fact * j;     //  numb-1 * numb-2 *
	cout << "���������= "; //  numb-3 � �. �.
	fact.putvl();          //������� �������� ����������
	cout << endl;
	return 0;
}

