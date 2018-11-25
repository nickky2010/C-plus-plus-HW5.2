#include <iostream>
#include "Matrix.h"
#include "main_function.h"
using namespace std;
void quit() {                          // ������� ������
	cout << "���������� ������!\n";
	system("pause");
	exit(0);
}

void check_inter(int vyb, int min, int max)
{
	if (vyb < min || vyb>max) {
		if (vyb < min) cout << "�������! ���������� ������ ���� �� ����� " << min << " !\n";
		else if (vyb > max) cout << "�������! ���������� ������ ���� �� ����� " << max << " !\n";
		cout << "��������� ����!\n";
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	}
}

void check_inter_row_col(Matrix <int>**matrix, int &row, int &col, int tmp_vyb1, const char* s, const char* str) {
	do {
		system("cls");
		cout << "\n������� " << tmp_vyb1 << str << endl;
		cout << "��� " << s << " �������� ��������� ������� � ����� �� ���� � �������\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "������� ��� �������: ";
		cin >> row;
		check_inter(row, 1, matrix[tmp_vyb1 - 1]->Get_Rows());
	} while (row < 1 || row > matrix[tmp_vyb1 - 1]->Get_Rows());
	do {
		system("cls");
		cout << "\n������� " << tmp_vyb1 << str << endl;
		cout << "��� " << s << " �������� ��������� ������� � ����� �� ���� � �������\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "������� ������� �������: ";
		cin >> col;
		check_inter(col, 1, matrix[tmp_vyb1 - 1]->Get_Cols());
	} while (col < 1 || col > matrix[tmp_vyb1 - 1]->Get_Cols());
}

void check_inter_row_col(Matrix <double>**matrix, int &row, int &col, int tmp_vyb1, const char* s, const char* str) {
	do {
		system("cls");
		cout << "\n������� " << tmp_vyb1 << str << endl;
		cout << "��� " << s << " �������� ��������� ������� � ����� �� ���� � �������\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "������� ��� �������: ";
		cin >> row;
		check_inter(row, 1, matrix[tmp_vyb1 - 1]->Get_Rows());
	} while (row < 1 || row > matrix[tmp_vyb1 - 1]->Get_Rows());
	do {
		system("cls");
		cout << "\n������� " << tmp_vyb1 << str << endl;
		cout << "��� " << s << " �������� ��������� ������� � ����� �� ���� � �������\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "������� ������� �������: ";
		cin >> col;
		check_inter(col, 1, matrix[tmp_vyb1 - 1]->Get_Cols());
	} while (col < 1 || col > matrix[tmp_vyb1 - 1]->Get_Cols());
}

void check_inter(int vyb, int min)
{
	if (vyb < min) {
		if (vyb < min) cout << "�������! ���������� ������ ���� �� ����� " << min << " !\n";
		cout << "��������� ����!\n";
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	}
}

void choice(int& vyb, const char* s) {
	do {
		cout << "�������� ��� �������:\n";
		cout << "1 - ������������� (int);\n";
		cout << "2 - ������������ (double);\n";
		cout << "0 - " << s << ";\n";
		cout << "��� �����: ";
		cin >> vyb;
		check_inter(vyb, 0, 2);
	} while (vyb < 0 || vyb>2);
}

void choice(int& vyb, const char* s, const char* ) {
	do {
		cout << "�������� ��� �������:\n";
		cout << "1 - ������������� (int);\n";
		cout << "2 - ������������ (double);\n";
		cout << "0 - " << s << ";\n";
		cout << "��� �����: ";
		cin >> vyb;
		check_inter(vyb, 0, 2);
	} while (vyb < 0 || vyb>2);
}

void choice_show(int& vyb, const char* s) {
	do {
		system("cls");
		cout << "�������� ������ ������ ������:\n";
		cout << "1 - ���������� ������������ �������;\n";
		cout << "2 - ���������� ��� ������� ������� ����;\n";
		cout << "0 - " << s << ";\n";
		cout << "��� �����: ";
		cin >> vyb;
		check_inter(vyb, 0, 2);
	} while (vyb < 0 && vyb>2);
}

void choice(int& vyb, int kol_matrix) {
	do {
		cout << "������� ����� ����������� �������:\n";
		cout << "��� �����: ";
		cin >> vyb;
		check_inter(vyb, 1, kol_matrix);
	} while (vyb < 1 || vyb>kol_matrix);
}

void choice(int& vyb, int kol_matrix, int number) {
	do {
		cout << "\n������� ����� "<<number<<" �������:\n";
		cout << "��� �����: ";
		cin >> vyb;
		check_inter(vyb, 1, kol_matrix);
	} while (vyb < 1 || vyb>kol_matrix);
}

void create_int_array_matrix(Matrix <int> **&matrix_int, int &kol_int) {
	int Row=0; 
	int Col=0;
	int tmp_data;
	do {
		cout << "������� ���������� ������: ";
		cin >> kol_int;
		check_inter(kol_int, 1);
	} while (kol_int < 1);
	matrix_int = new Matrix <int>*[kol_int];
	for (int k = 0; k < kol_int; k++) {	
		do {
			system("cls");
			cout << "������� ���������� ����� " << k + 1 << " �������: ";
			cin >> Row;
			check_inter(Row, 1);
		} while (Row < 1);
		do {
			cout << "������� ���������� ������� " << k + 1 << " �������: ";
			cin >> Col;
			check_inter(Col, 1);
		} while (Col < 1);
		matrix_int[k] = new Matrix <int>(Row, Col);
		cout << "������� ������ � " << k + 1 << " �������:\n";
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				cout << "matrix [" << i << "][" << j << "] = ";
				cin >> tmp_data;
				matrix_int[k]->Set(i, j, tmp_data);
			}
		}
	}
}

void create_double_array_matrix(Matrix <double> **&matrix_double, int &kol_double) {
	int Row = 0;
	int Col = 0;
	double tmp_data;
	do {
		cout << "������� ���������� ������: ";
		cin >> kol_double;
		check_inter(kol_double, 1);
	} while (kol_double < 1);
	matrix_double = new Matrix <double>*[kol_double];
	for (int k = 0; k < kol_double; k++) {
		do {
			system("cls");
			cout << "������� ���������� ����� " << k + 1 << " �������: ";
			cin >> Row;
			check_inter(Row, 1);
		} while (Row < 1);
		do {
			cout << "������� ���������� ������� " << k + 1 << " �������: ";
			cin >> Col;
			check_inter(Col, 1);
		} while (Col < 1);
		matrix_double[k] = new Matrix <double>(Row, Col);
		cout << "������� ������ � " << k + 1 << " �������:\n";
		for (int i = 0; i < Row; i++) {
			for (int j = 0; j < Col; j++) {
				cout << "matrix [" << i << "][" << j << "] = ";
				cin >> tmp_data;
				matrix_double[k]->Set(i, j, tmp_data);
			}
		}
	}
}

void show_action_matrix(Matrix <int> *matrix, Matrix <int> **matrix_int, int &vyb, int &tmp_vyb1, int &tmp_vyb2, int operators) {
	cout << "\n������� " << tmp_vyb1 <<"\n";
	matrix_int[tmp_vyb1 - 1]->Show();
	cout << "\n������� " << tmp_vyb2 << "\n";
	matrix_int[tmp_vyb2 - 1]->Show();
	switch (operators) {
	case 1: 
		cout << "\n����� ������ " << tmp_vyb1 << " � " << tmp_vyb2 << "\n";
		*matrix = *matrix_int[tmp_vyb1 - 1] + *matrix_int[tmp_vyb2 - 1];          // ��������
		break;
	case 2:
		cout << "\n�������� ������ " << tmp_vyb1 << " � " << tmp_vyb2 << "\n";
		*matrix = *matrix_int[tmp_vyb1 - 1] - *matrix_int[tmp_vyb2 - 1];          // ��������
		break;
	case 3:
		cout << "\n������������ ������ " << tmp_vyb1 << " � " << tmp_vyb2 << "\n";
		*matrix = *matrix_int[tmp_vyb1 - 1] * (*matrix_int[tmp_vyb2 - 1]);      // ���������
		break;
	case 4:
		cout << "\n������� ������� " << tmp_vyb1 << " �� ������� " << tmp_vyb2 << "\n";
		int determinant = 0;
		if (matrix_int[tmp_vyb2 - 1]->Get_Rows() == matrix_int[tmp_vyb2 - 1]->Get_Cols() &&
			matrix_int[tmp_vyb2 - 1]->Get_Rows()<=3 && 
			matrix_int[tmp_vyb2 - 1]->Revers_determinant(matrix_int[tmp_vyb2 - 1], determinant)) 
		{
			*matrix = *matrix_int[tmp_vyb1 - 1] / *matrix_int[tmp_vyb2 - 1];          // �������
			matrix->Show();
		}
		else if (matrix_int[tmp_vyb2 - 1]->Get_Rows() != matrix_int[tmp_vyb2 - 1]->Get_Cols()) 
			cout << "�� ����� ������������ �������. ������� " << tmp_vyb2 << " �� �������� ����������.\n";
		else if (matrix_int[tmp_vyb2 - 1]->Get_Rows() > 3) 
			cout << "����������. ��������� �� ��������� �� ������� ������� ������������ ������ ��� 3�3.\n";
		else if (determinant==0) 
			cout << "�� ����� ������������ �������. ������������ ������� " << tmp_vyb2 << " ����� 0.\n";
		break;
	}
	if (operators!=4) matrix->Show();
	vyb = tmp_vyb1 = tmp_vyb2 = 0;
	delete matrix;
}

void show_action_matrix(Matrix <double> *matrix, Matrix <double> **matrix_double, int &vyb, int &tmp_vyb1, int &tmp_vyb2, int operators) {
	cout << "\n������� " << tmp_vyb1 << "\n";
	matrix_double[tmp_vyb1 - 1]->Show();
	cout << "\n������� " << tmp_vyb2 << "\n";
	matrix_double[tmp_vyb2 - 1]->Show();
	switch (operators) {
	case 1:
		cout << "\n����� ������ " << tmp_vyb1 << " � " << tmp_vyb2 << "\n";
		*matrix = *matrix_double[tmp_vyb1 - 1] + *matrix_double[tmp_vyb2 - 1];          // ��������
		break;
	case 2:
		cout << "\n�������� ������ " << tmp_vyb1 << " � " << tmp_vyb2 << "\n";
		*matrix = *matrix_double[tmp_vyb1 - 1] - *matrix_double[tmp_vyb2 - 1];          // ��������
		break;
	case 3:
		cout << "\n������������ ������ " << tmp_vyb1 << " � " << tmp_vyb2 << "\n";
		*matrix = *matrix_double[tmp_vyb1 - 1] * (*matrix_double[tmp_vyb2 - 1]);      // ���������
		break;
	case 4:
		cout << "\n������� ������� " << tmp_vyb1 << " �� ������� " << tmp_vyb2 << "\n";
		double determinant = 0;
		if (matrix_double[tmp_vyb2 - 1]->Get_Rows() == matrix_double[tmp_vyb2 - 1]->Get_Cols() &&
			matrix_double[tmp_vyb2 - 1]->Get_Rows() <= 3 &&
			matrix_double[tmp_vyb2 - 1]->Revers_determinant(matrix_double[tmp_vyb2 - 1], determinant))
		{
			*matrix = *matrix_double[tmp_vyb1 - 1] / *matrix_double[tmp_vyb2 - 1];          // �������
			matrix->Show();
		}
		else if (matrix_double[tmp_vyb2 - 1]->Get_Rows() != matrix_double[tmp_vyb2 - 1]->Get_Cols())
			cout << "�� ����� ������������ �������. ������� " << tmp_vyb2 << " �� �������� ����������.\n";
		else if (matrix_double[tmp_vyb2 - 1]->Get_Rows() > 3)
			cout << "����������. ��������� �� ��������� �� ������� ������� ������������ ������ ��� 3�3.\n";
		else if (determinant == 0)
			cout << "�� ����� ������������ �������. ������������ ������� " << tmp_vyb2 << " ����� 0.\n";
		break;
	}
	if (operators != 4) matrix->Show();
	vyb = tmp_vyb1 = tmp_vyb2 = 0;
	delete matrix;
}

