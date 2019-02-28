//����������� ������� ������ Readings
//���������� � ���������� ������� � ���������� ������
#include "pch.h"
#include "readings.h"

float Readings::get_drainage_tariff() { return drainage_tariff; }
float Readings::get_cold_water_tariff() { return cold_water_tariff; }
float Readings::get_hot_water_tariff() { return hot_water_tariff; }
float Readings::get_electricity_tariff() { return electricity_tariff; }
float Readings::get_readings(int i) {return Arr_readings[i];}
string Readings::get_date() {return date;}
void Readings::set_readings(int i, float value) {Arr_readings[i] = value;}
void Readings::set_date(string date) {this->date = date;}
void Readings::set_drainage_tariff(float value) { drainage_tariff = value; }
void Readings::set_cold_water_tariff(float value) { cold_water_tariff = value;}
void Readings::set_hot_water_tariff(float value) { hot_water_tariff = value; }
void Readings::set_electricity_tariff(float value) { electricity_tariff = value; }
void Readings::print_date() {cout << " " << date << endl;}
void Readings::print_readings(int i) {
	int n;
	//�������� ��� �������������� ��� ������ ���������� �������� � ������� (���� ���� ����� �������, ��� ��������� ��� �����) 
	//����������� ����� if/else 
	n = (i == 4) ? 1 : 3; 
	cout << " " << fixed << setprecision(n) << Arr_readings[i] << endl;
}
//������ ��������� ��������� � ���� � ���� ������ (�������� ������)
void Readings::write(string path) { 
	//��������� �������� ������ ��� ������ ����� �����
	string buffer_in[256];
	//�������� ��������� ������ �� ������ �� ���� path
	ifstream in(path, ios_base::in);
	//���� ����� ��������
	if (in.is_open()) {
		//��������� ��������� � ������
		in.seekg(0, ios_base::beg);
		for (int i = 0; i < 256; i++) {
			//���������� 256 ����� �� ����� � ������
			getline(in, buffer_in[i], '\n');
		}
	} else {
		cout << "������ �������� ����� ��� ������!\n";
	}
	//������� �����
	in.close();
	//�������� ��������� ������ �� ������ (� ���������� ����������� ��� ��������)
	ofstream out(path, ios_base::trunc | ios_base::out);
	if (out.is_open()) {
		out.seekp(0, ios_base::beg);
		//������ � ������ ������ ���������� �������
		out << hot_water_tariff << " " << cold_water_tariff << " " << electricity_tariff << " " << drainage_tariff << "\n";
		//������ ����� �������� ����� �� ������ ����� ������ ������ (��� �������� �������� ������� ������)
		for (int i = 1; i < 256; i++) {
			//������� ������ �����
			if (!(buffer_in[i] == "")) {
				out << buffer_in[i] << "\n";
			}
		}
		//��������� ��������� � �����
		out.seekp(0, ios_base::end);
		//������ ���������� ���� � ���� ������
		out << date;
		//������ ���������� ����������� ��������� � ��������� ������
		for (int i = 0; i < 5; i++) {
			int n;
			//�������� ��� �������������� ������ ���������� �������� � ������� 
			//(���� ���� ����� ������� ��� �������� ���������������, ��� ����� ��� �������)
			n = (i == 4) ?  1 : 3; 
			out << "\n" << fixed << setprecision(n) << Arr_readings[i];
		}
	} else {
		cout << "������ �������� ����� ��� ������!\n";
	}
	out.close();
}
//������ �������, ��������� � ���� �� ����� ������ (������� ������)
void Readings::read(string path) {
	//�������� ��������� ������
	int offset = 0;
	//������� �����
	int string_count = 0;
	//�������� ��������� ������ �� ������ (���� ����� path)
	ifstream in(path, ios_base::in);
	if (in.is_open()) {
		//��������� ��������� � ������
		in.seekg(0, ios_base::beg);
		//������ �������� ������� � ����������
		in >> hot_water_tariff;
		in >> cold_water_tariff;
		in >> electricity_tariff;
		in >> drainage_tariff;
		//��������� ��������� � �����
		in.seekg(0, ios_base::end);
		//���������� ���������� �������� � ��������� 6 ������� ����� (����� � ��������� ���������)
		while (string_count < 6) {
			//�������� �� ���� ������ ����� �� ������� �������
			in.seekg(-1, ios_base::cur);
			//���� ��������� ������ ������ �� ��������� '\n' ��������� ������� �����
			if (in.peek() == '\n') {
				string_count++;
			}
			//��������� ������� ��������
			offset++;
		}
		//��������� ��������� ����� ����� �������� �������
		in.seekg(-(offset + 4), ios_base::end); //4 - �������� ������ ����� �����
		//������� ����
		getline(in, date, '\n');
		//������� ��������� � ������
		for (int i = 0; i < 5; i++) {
			in >> Arr_readings[i];
		}
	}
	else {
		cout << "������ �������� ����� ��� ������!\n";
	}
	in.close();
}