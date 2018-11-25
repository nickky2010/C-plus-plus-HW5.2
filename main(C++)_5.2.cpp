//                             ����. �������� - ��������������� ���������������� �� C++.
//                                          ������ 5. ������� �������.
//                                              �������� ������� �2.
//                                                   ������� 1.
// ������� ����� ��� ������ � ���������. ������������� ��������� ������� ��� ������ � ���������:
//    -�������� ������;
//    -��������� ������;
//    -���������������� ������;
//    -������������ ������ ���� �����;
//    -��������� � ��������� ������������� �������� �������.
// ���������� ����������� ��������������� ���������.

//                                                   ������� 2.
// �������� ��������� ����� �������.���������� ����������� :
//    -������������ ��������� ������;
//    -������� ������;
//    -���������� ������� � ����������;
//    -���������� ���������� ����������;
//    -����������� �������;
//    -�������������� �������� � ������� ������������� ����������(+, �, *, / ),
//    -����� ������������� � ������������ ��������.

#include <iostream>
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include "Matrix.h"
#include "main_function.h"
#define ROW_AUTO 5
#define COL_AUTO 5
using namespace std;

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand((size_t)time(0));
	int tmp_vyb1 = 0, tmp_vyb2 = 0, vyb = 0;
	int kol_int=0, kol_double=0;
	Matrix <int> *matrix = NULL;
	Matrix <double> *matrixd = NULL;
	Matrix <int> **matrix_int = NULL;
	Matrix <double> **matrix_double = NULL;
	cout << "����� ��� ������ � ���������\n\n";
	do {
		cout << "���������� ������ �������� ������\n";
		cout << "�������� ������:\n";
		cout << "1 - ������;\n";
		cout << "2 - �������������� (�� 2 ������� �������������� � ������������� ���� ������������ " << ROW_AUTO << "�" << COL_AUTO << ")\n";
		cout << "��� �����: ";
		cin >> vyb;
		check_inter(vyb, 1, 2);
	} while (vyb < 1 || vyb>2);
	switch (vyb)
	{
		// ������ ����
	case 1:
		system("cls");
		do {
			choice(vyb, "�����");
			if (vyb == 1) {
				create_int_array_matrix(matrix_int, kol_int);
				cout << "������ � ������� �������������� ���� int ������� �������!\n\n";
				system("pause");
			}
			if (vyb == 2) {
				create_double_array_matrix(matrix_double, kol_double);
				cout << "������ � ������� ������������� ���� double ������� �������!\n\n";
				system("pause");
			}
			system("cls");
		} while (vyb != 0);
		break;
		// �������������� ����
	case 2:
		system("cls");
		kol_int = 2;
		matrix_int = new Matrix <int>*[kol_int];
		for (int i = 0; i < kol_int; i++) {
			matrix_int[i] = new Matrix <int>(ROW_AUTO, COL_AUTO, 50, 1, 1);
		}
		cout << "������� " << kol_int<< " ������� �������������� ���� int ������������ "<< ROW_AUTO<<"�"<< COL_AUTO <<"!\n";
		kol_double = 2;
		matrix_double = new Matrix <double>*[kol_double];
		for (int i = 0; i < kol_double; i++) {
			matrix_double[i] = new Matrix <double>(ROW_AUTO, COL_AUTO, 50, 1, 0.99);
		}
		cout << "������� "<< kol_double <<" ������� ������������� ���� double ������������ " << ROW_AUTO << "�" << COL_AUTO << "!\n\n";
		system("pause");
		break;
	default:
		while (cin.get() != '\n');
		cout << "�������! ��������� ����!\n";
	}
	while (true) {
		int menu = -1;
		system("cls");
		cout << "1 - �������� ����������� ������\n";
		cout << "2 - �������� ������\n";
		cout << "3 - ��������� ������\n";
		cout << "4 - ��������� ������\n";
		cout << "5 - ������� ������\n";
		cout << "6 - ���������������� ������\n";
		cout << "7 - ������������ ������ ���� �����\n";
		cout << "8 - ��������� ������������� �������� �������\n";
		cout << "9 - ��������� ������������� �������� �������\n";
		cout << "10 - ��������� ������������� � ������������ �������� �������\n";
		cout << "0 - �����\n";
		cout << "��� �����: ";
		cin >> menu;
		switch (menu)
		{
		case 1: // 1 - �������� ����������� ������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						do {
							choice_show(tmp_vyb1, "�����");
							if (tmp_vyb1 == 1) {
								choice(tmp_vyb1, kol_int);
								cout << "\n������� " << tmp_vyb1 << endl;
								matrix_int[tmp_vyb1-1]->Show();
								system("pause");
							}
							if (tmp_vyb1 == 2) {
								for (int i = 0; i < kol_int; i++) {
									cout << "\n������� " << i + 1 << endl;
									matrix_int[i]->Show();
								}
								system("pause");
							}
						} while (tmp_vyb1 != 0);
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						do {
							choice_show(tmp_vyb1, "�����");
							if (tmp_vyb1 == 1) {
								choice(tmp_vyb1, kol_double);
								cout << "\n������� " << tmp_vyb1 << endl;
								matrix_double[tmp_vyb1]->Show();
								system("pause");
							}
							if (tmp_vyb1 == 2) {
								for (int i = 0; i < kol_double; i++) {
									cout << "\n������� " << i + 1 << endl;
									matrix_double[i]->Show();
								}
								system("pause");
							}
						} while (tmp_vyb1 != 0);
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 2: // 2 - �������� ������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->�ompare_sum(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb1 - 1]->Get_Rows(), matrix_int[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 1);
						}
						else cout << "\n������!\n��� �������� ������, ����������, ����� ��� ���� ����������� �� �������!\n";
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";								
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->�ompare_sum(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb1 - 1]->Get_Rows(), matrix_double[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 1);
						}
						else cout << "\n������!\n��� �������� ������, ����������, ����� ��� ���� ����������� �� �������!\n";;
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 3: // 3 - ��������� ������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->�ompare_sum(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb1 - 1]->Get_Rows(), matrix_int[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 2);
						}
						else cout << "\n������!\n��� ��������� ������, ����������, ����� ��� ���� ����������� �� �������!\n";
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->�ompare_sum(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb1 - 1]->Get_Rows(), matrix_double[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 2);
						}
						else cout << "\n������!\n��� ��������� ������, ����������, ����� ��� ���� ����������� �� �������!\n";;
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 4:     // 4 - ��������� ������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->�ompare_mult(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb2 - 1]->Get_Rows(), matrix_int[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 3);
						}
						else {
							cout << "\n������!\n��� ��������� ������, ����������, ����� ����� �������� ������� ";
							cout << tmp_vyb1 << " ��������� ����� ����� ������� " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->�ompare_mult(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb2 - 1]->Get_Rows(), matrix_double[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 3);
						}
						else {
							cout << "\n������!\n��� ��������� ������, ����������, ����� ����� �������� ������� ";
							cout << tmp_vyb1 << " ��������� ����� ����� ������� " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 5:     // 5 - ������� ������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->�ompare_mult(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb2 - 1]->Get_Rows(), matrix_int[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 4);
						}
						else {
							cout << "\n������!\n��� ������� ������, ����������, ����� ����� �������� ������� ";
							cout << tmp_vyb1 << " ��������� ����� ����� ������� " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->�ompare_mult(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb2 - 1]->Get_Rows(), matrix_double[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 4);
						}
						else {
							cout << "\n������!\n��� ������� ������, ����������, ����� ����� �������� ������� ";
							cout << tmp_vyb1 << " ��������� ����� ����� ������� " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 6: // 6 - ���������������� ������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int);
						matrix = new Matrix <int>(matrix_int[tmp_vyb1 - 1]->Get_Rows(), matrix_int[tmp_vyb1 - 1]->Get_Cols());
						cout << "\n������� " << tmp_vyb1 << endl;
						matrix_int[tmp_vyb1 - 1]->Show();
						cout << "\n����������������� ������� " << tmp_vyb1 << endl;
						*matrix = matrix->transpose(*matrix_int[tmp_vyb1 - 1]);
						matrix->Show();
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb2, kol_double);
						matrixd = new Matrix <double>(matrix_double[tmp_vyb2 - 1]->Get_Rows(), matrix_double[tmp_vyb2 - 1]->Get_Cols());
						cout << "\n������� " << tmp_vyb2 << endl;
						matrix_double[tmp_vyb2 - 1]->Show();
						cout << "\n����������������� ������� " << tmp_vyb2 << endl;
						*matrixd = matrixd->transpose(*matrix_double[tmp_vyb2 - 1]);
						matrixd->Show();
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 7:                //������������ ������ ���� �����
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						cout << "�������� ���������� ������� (1 �������)\n";
						choice(tmp_vyb1, kol_int, 1);
						cout << "\n�������� ������� ���� ���������� (2 �������)\n";
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->�ompare_sum(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							cout << "\n���������� ������� " << tmp_vyb1 << endl;
							matrix_int[tmp_vyb1 - 1]->Show();
							cout << "\n���������� ������� " << tmp_vyb2 << " �� �����������" << endl;
							matrix_int[tmp_vyb2 - 1]->Show();
							cout << "\n���������� ������� " << tmp_vyb2 << " ����� �����������" << endl;
							matrix_int[tmp_vyb2 - 1] = matrix_int[tmp_vyb1 - 1];
							matrix_int[tmp_vyb2 - 1]->Show();
						}
						else cout << "\n������!\n��� ������������ ������, ����������, ����� ��� ���� ����������� �� �������!\n";
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						cout << "\n�������� ���������� ������� (1 �������)\n";
						choice(tmp_vyb1, kol_double, 1);
						cout << "�������� ������� ���� ���������� (2 �������)\n";
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->�ompare_sum(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							cout << "\n���������� ������� " << tmp_vyb1 << endl;
							matrix_double[tmp_vyb1 - 1]->Show();
							cout << "\n���������� ������� " << tmp_vyb2 << " �� �����������" << endl;
							matrix_double[tmp_vyb2 - 1]->Show();
							cout << "\n���������� ������� " << tmp_vyb2 << " ����� �����������" << endl;
							matrix_double[tmp_vyb2 - 1] = matrix_double[tmp_vyb1 - 1];
							matrix_double[tmp_vyb2 - 1]->Show();
						}
						else cout << "\n������!\n��� ������������ ������, ����������, ����� ��� ���� ����������� �� �������!\n";
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 8: // ��������� ������������� �������� �������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						int row, col, set_value;
						choice(tmp_vyb1, kol_int);
						check_inter_row_col(matrix_int, row, col, tmp_vyb1, "���������", " �� ���������");
						cout << "������� ����� ��������: ";
						cin >> set_value;
						matrix_int[tmp_vyb1 - 1]->Set(row - 1, col - 1, set_value);
						cout << "����� �������� ������� � �������!\n";
						cout << "\n������� " << tmp_vyb1 << " ����� ���������" << endl;
						matrix_int[tmp_vyb1 - 1]->Show();
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						int row, col;
						double set_value;
						choice(tmp_vyb1, kol_double);
						check_inter_row_col(matrix_double, row, col, tmp_vyb1, "���������", " �� ���������");
						cout << "������� ����� ��������: ";
						cin >> set_value;
						matrix_double[tmp_vyb1 - 1]->Set(row - 1, col - 1, set_value);
						cout << "����� �������� ������� � �������!\n";
						cout << "\n������� " << tmp_vyb1 << " ����� ���������" << endl;
						matrix_double[tmp_vyb1 - 1]->Show();
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 9:     // ��������� ������������� �������� �������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						int row, col;
						choice(tmp_vyb1, kol_int);
						check_inter_row_col(matrix_int, row, col, tmp_vyb1, "���������", "");
						cout << "\n���� �������� " << matrix_int[tmp_vyb1 - 1]->Get(row - 1, col - 1) << endl;
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						int row, col;
						choice(tmp_vyb1, kol_double);
						check_inter_row_col(matrix_double, row, col, tmp_vyb1, "���������", "");
						cout << "\n���� �������� " << matrix_double[tmp_vyb1 - 1]->Get(row - 1, col - 1) << endl;
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 10:     // ��������� ������������� � ������������ �������� �������
			system("cls");
			do {
				choice(vyb, "�����");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						int Min=0, Max=0, tMin = 0, tMax = 0;
						system("cls");
						choice(tmp_vyb1, kol_int);
						cout << "\n������� " << tmp_vyb1 << endl;
						matrix_int[tmp_vyb1 - 1]->Show();
						Min = tMin = matrix_int[tmp_vyb1 - 1]->Get(0, 0);
						Max = tMax = matrix_int[tmp_vyb1 - 1]->Get(0, 0);
						for (int i = 1; i < matrix_int[tmp_vyb1 - 1]->Get_Rows(); i++) {
							matrix_int[tmp_vyb1 - 1]->MinMax(i, tMin, tMax);
							if (Min > tMin) Min = tMin;
							if (Max < tMax) Max = tMax;
						}
						cout << "\n����������� ��������: " << Min << endl;
						cout << "������������ ��������: " << Max << endl;
					}
					else cout << "\n������ �������������� ���� (int) �� ����������\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						double Min = 0, Max = 0, tMin = 0, tMax = 0;
						system("cls");
						choice(tmp_vyb2, kol_double);
						cout << "\n������� " << tmp_vyb2 << endl;
						matrix_double[tmp_vyb2 - 1]->Show();
						Min = tMin = matrix_double[tmp_vyb2 - 1]->Get(0, 0);
						Max = tMax = matrix_double[tmp_vyb2 - 1]->Get(0, 0);
						for (int i = 1; i < matrix_double[tmp_vyb2 - 1]->Get_Rows(); i++) {
							matrix_double[tmp_vyb2 - 1]->MinMax(i, tMin, tMax);
							if (Min > tMin+1e-9) Min = tMin;
							if (Max < tMax - 1e-9) Max = tMax;
						}
						cout << "\n����������� ��������: " << Min << endl;
						cout << "������������ ��������: " << Max << endl;
					}
					else cout << "\n������ ������������� ���� (double) �� ����������\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
			break;
		case 0:
			/*if (matrix != NULL) delete[] matrix;
			if (matrixd != NULL) delete[] matrixd;
			if (matrix_int != NULL) {
				for (int i = 0; i < kol_int; i++) {
					delete[] matrix_int[i];
				}
				delete matrix_int;
			}
			if (matrix_double != NULL) {
				for (int i = 0; i < kol_double; i++) {
					delete[] matrix_double[i];
				}
				delete matrix_double;
			}*/
			quit();
			break;
		default:
			while (cin.get() != '\n');
			cout << "�������! ��������� ����!\n";
		}
	}
	system("pause");
	return 0;
}
