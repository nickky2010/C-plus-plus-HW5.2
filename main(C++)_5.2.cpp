//                             Курс. Объектно - ориентированное программирование на C++.
//                                          Модуль 5. Шаблоны классов.
//                                              Домашнее задание №2.
//                                                   Задание 1.
// Создать класс для работы с матрицами. Предусмотреть следующие функции для работы с матрицами:
//    -сложения матриц;
//    -умножения матриц;
//    -транспонирования матриц;
//    -присваивания матриц друг другу;
//    -установка и получение произвольного элемента матрицы.
// Необходимо перегрузить соответствующие операторы.

//                                                   Задание 2.
// Создайте шаблонный класс матрица.Необходимо реализовать :
//    -динамическое выделение памяти;
//    -очистку памяти;
//    -заполнение матрицы с клавиатуры;
//    -заполнение случайными значениями;
//    -отображение матрицы;
//    -арифметические операции с помощью перегруженных операторов(+, –, *, / ),
//    -поиск максимального и минимального элемента.

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
	cout << "Класс для работы с матрицами\n\n";
	do {
		cout << "Необходимо ввести исходные данные\n";
		cout << "Выберите способ:\n";
		cout << "1 - ручной;\n";
		cout << "2 - автоматический (по 2 матрицы целочисленного и вещественного типа размерностью " << ROW_AUTO << "х" << COL_AUTO << ")\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		check_inter(vyb, 1, 2);
	} while (vyb < 1 || vyb>2);
	switch (vyb)
	{
		// ручной ввод
	case 1:
		system("cls");
		do {
			choice(vyb, "далее");
			if (vyb == 1) {
				create_int_array_matrix(matrix_int, kol_int);
				cout << "Данные в матрицы целочисленного типа int внесены успешно!\n\n";
				system("pause");
			}
			if (vyb == 2) {
				create_double_array_matrix(matrix_double, kol_double);
				cout << "Данные в матрицы вещественного типа double внесены успешно!\n\n";
				system("pause");
			}
			system("cls");
		} while (vyb != 0);
		break;
		// автоматический ввод
	case 2:
		system("cls");
		kol_int = 2;
		matrix_int = new Matrix <int>*[kol_int];
		for (int i = 0; i < kol_int; i++) {
			matrix_int[i] = new Matrix <int>(ROW_AUTO, COL_AUTO, 50, 1, 1);
		}
		cout << "Создано " << kol_int<< " матрицы целочисленного типа int размерностью "<< ROW_AUTO<<"х"<< COL_AUTO <<"!\n";
		kol_double = 2;
		matrix_double = new Matrix <double>*[kol_double];
		for (int i = 0; i < kol_double; i++) {
			matrix_double[i] = new Matrix <double>(ROW_AUTO, COL_AUTO, 50, 1, 0.99);
		}
		cout << "Создано "<< kol_double <<" матрицы вещественного типа double размерностью " << ROW_AUTO << "х" << COL_AUTO << "!\n\n";
		system("pause");
		break;
	default:
		while (cin.get() != '\n');
		cout << "Неверно! Повторите ввод!\n";
	}
	while (true) {
		int menu = -1;
		system("cls");
		cout << "1 - просмотр содержимого матриц\n";
		cout << "2 - сложение матриц\n";
		cout << "3 - вычитание матриц\n";
		cout << "4 - умножение матриц\n";
		cout << "5 - деление матриц\n";
		cout << "6 - транспонирование матриц\n";
		cout << "7 - присваивание матриц друг другу\n";
		cout << "8 - установка произвольного элемента матрицы\n";
		cout << "9 - получение произвольного элемента матрицы\n";
		cout << "10 - получение максимального и минимального элемента матрицы\n";
		cout << "0 - выход\n";
		cout << "Ваш выбор: ";
		cin >> menu;
		switch (menu)
		{
		case 1: // 1 - просмотр содержимого матриц
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						do {
							choice_show(tmp_vyb1, "назад");
							if (tmp_vyb1 == 1) {
								choice(tmp_vyb1, kol_int);
								cout << "\nМатрица " << tmp_vyb1 << endl;
								matrix_int[tmp_vyb1-1]->Show();
								system("pause");
							}
							if (tmp_vyb1 == 2) {
								for (int i = 0; i < kol_int; i++) {
									cout << "\nМатрица " << i + 1 << endl;
									matrix_int[i]->Show();
								}
								system("pause");
							}
						} while (tmp_vyb1 != 0);
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						do {
							choice_show(tmp_vyb1, "назад");
							if (tmp_vyb1 == 1) {
								choice(tmp_vyb1, kol_double);
								cout << "\nМатрица " << tmp_vyb1 << endl;
								matrix_double[tmp_vyb1]->Show();
								system("pause");
							}
							if (tmp_vyb1 == 2) {
								for (int i = 0; i < kol_double; i++) {
									cout << "\nМатрица " << i + 1 << endl;
									matrix_double[i]->Show();
								}
								system("pause");
							}
						} while (tmp_vyb1 != 0);
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 2: // 2 - сложение матриц
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->Сompare_sum(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb1 - 1]->Get_Rows(), matrix_int[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 1);
						}
						else cout << "\nОшибка!\nДля сложения матриц, необходимо, чтобы они были одинаковыми по размеру!\n";
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";								
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->Сompare_sum(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb1 - 1]->Get_Rows(), matrix_double[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 1);
						}
						else cout << "\nОшибка!\nДля сложения матриц, необходимо, чтобы они были одинаковыми по размеру!\n";;
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 3: // 3 - вычитание матриц
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->Сompare_sum(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb1 - 1]->Get_Rows(), matrix_int[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 2);
						}
						else cout << "\nОшибка!\nДля вычитания матриц, необходимо, чтобы они были одинаковыми по размеру!\n";
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->Сompare_sum(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb1 - 1]->Get_Rows(), matrix_double[tmp_vyb1 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 2);
						}
						else cout << "\nОшибка!\nДля вычитания матриц, необходимо, чтобы они были одинаковыми по размеру!\n";;
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 4:     // 4 - умножение матриц
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->Сompare_mult(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb2 - 1]->Get_Rows(), matrix_int[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 3);
						}
						else {
							cout << "\nОшибка!\nДля умножения матриц, необходимо, чтобы число столбцов матрицы ";
							cout << tmp_vyb1 << " равнялось числу строк матрицы " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->Сompare_mult(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb2 - 1]->Get_Rows(), matrix_double[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 3);
						}
						else {
							cout << "\nОшибка!\nДля умножения матриц, необходимо, чтобы число столбцов матрицы ";
							cout << tmp_vyb1 << " равнялось числу строк матрицы " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 5:     // 5 - деление матриц
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int, 1);
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->Сompare_mult(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							matrix = new Matrix <int>(matrix_int[tmp_vyb2 - 1]->Get_Rows(), matrix_int[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrix, matrix_int, vyb, tmp_vyb1, tmp_vyb2, 4);
						}
						else {
							cout << "\nОшибка!\nДля деления матриц, необходимо, чтобы число столбцов матрицы ";
							cout << tmp_vyb1 << " равнялось числу строк матрицы " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_double, 1);
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->Сompare_mult(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							matrixd = new Matrix <double>(matrix_double[tmp_vyb2 - 1]->Get_Rows(), matrix_double[tmp_vyb2 - 1]->Get_Cols());
							show_action_matrix(matrixd, matrix_double, vyb, tmp_vyb1, tmp_vyb2, 4);
						}
						else {
							cout << "\nОшибка!\nДля деления матриц, необходимо, чтобы число столбцов матрицы ";
							cout << tmp_vyb1 << " равнялось числу строк матрицы " << tmp_vyb2 << " !\n";
						}
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 6: // 6 - транспонирование матриц
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						choice(tmp_vyb1, kol_int);
						matrix = new Matrix <int>(matrix_int[tmp_vyb1 - 1]->Get_Rows(), matrix_int[tmp_vyb1 - 1]->Get_Cols());
						cout << "\nМатрица " << tmp_vyb1 << endl;
						matrix_int[tmp_vyb1 - 1]->Show();
						cout << "\nТранспонированная матрица " << tmp_vyb1 << endl;
						*matrix = matrix->transpose(*matrix_int[tmp_vyb1 - 1]);
						matrix->Show();
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						choice(tmp_vyb2, kol_double);
						matrixd = new Matrix <double>(matrix_double[tmp_vyb2 - 1]->Get_Rows(), matrix_double[tmp_vyb2 - 1]->Get_Cols());
						cout << "\nМатрица " << tmp_vyb2 << endl;
						matrix_double[tmp_vyb2 - 1]->Show();
						cout << "\nТранспонированная матрица " << tmp_vyb2 << endl;
						*matrixd = matrixd->transpose(*matrix_double[tmp_vyb2 - 1]);
						matrixd->Show();
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 7:                //присваивание матриц друг другу
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						cout << "Выберите копируемую матрицу (1 матрица)\n";
						choice(tmp_vyb1, kol_int, 1);
						cout << "\nВыберите матрицу куда копировать (2 матрица)\n";
						choice(tmp_vyb2, kol_int, 2);
						if (matrix_int[0]->Сompare_sum(matrix_int[tmp_vyb1 - 1], matrix_int[tmp_vyb2 - 1])) {
							cout << "\nКопируемая матрица " << tmp_vyb1 << endl;
							matrix_int[tmp_vyb1 - 1]->Show();
							cout << "\nИзменяемая матрица " << tmp_vyb2 << " до копирования" << endl;
							matrix_int[tmp_vyb2 - 1]->Show();
							cout << "\nИзменяемая матрица " << tmp_vyb2 << " после копирования" << endl;
							matrix_int[tmp_vyb2 - 1] = matrix_int[tmp_vyb1 - 1];
							matrix_int[tmp_vyb2 - 1]->Show();
						}
						else cout << "\nОшибка!\nДля присваивания матриц, необходимо, чтобы они были одинаковыми по размеру!\n";
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						cout << "\nВыберите копируемую матрицу (1 матрица)\n";
						choice(tmp_vyb1, kol_double, 1);
						cout << "Выберите матрицу куда копировать (2 матрица)\n";
						choice(tmp_vyb2, kol_double, 2);
						if (matrix_double[0]->Сompare_sum(matrix_double[tmp_vyb1 - 1], matrix_double[tmp_vyb2 - 1])) {
							cout << "\nКопируемая матрица " << tmp_vyb1 << endl;
							matrix_double[tmp_vyb1 - 1]->Show();
							cout << "\nИзменяемая матрица " << tmp_vyb2 << " до копирования" << endl;
							matrix_double[tmp_vyb2 - 1]->Show();
							cout << "\nИзменяемая матрица " << tmp_vyb2 << " после копирования" << endl;
							matrix_double[tmp_vyb2 - 1] = matrix_double[tmp_vyb1 - 1];
							matrix_double[tmp_vyb2 - 1]->Show();
						}
						else cout << "\nОшибка!\nДля присваивания матриц, необходимо, чтобы они были одинаковыми по размеру!\n";
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 8: // установка произвольного элемента матрицы
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						int row, col, set_value;
						choice(tmp_vyb1, kol_int);
						check_inter_row_col(matrix_int, row, col, tmp_vyb1, "изменения", " до изменения");
						cout << "Введите новое значение: ";
						cin >> set_value;
						matrix_int[tmp_vyb1 - 1]->Set(row - 1, col - 1, set_value);
						cout << "Новое значение введено в матрицу!\n";
						cout << "\nМатрица " << tmp_vyb1 << " после изменений" << endl;
						matrix_int[tmp_vyb1 - 1]->Show();
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						int row, col;
						double set_value;
						choice(tmp_vyb1, kol_double);
						check_inter_row_col(matrix_double, row, col, tmp_vyb1, "изменения", " до изменения");
						cout << "Введите новое значение: ";
						cin >> set_value;
						matrix_double[tmp_vyb1 - 1]->Set(row - 1, col - 1, set_value);
						cout << "Новое значение введено в матрицу!\n";
						cout << "\nМатрица " << tmp_vyb1 << " после изменений" << endl;
						matrix_double[tmp_vyb1 - 1]->Show();
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 9:     // получение произвольного элемента матрицы
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						system("cls");
						int row, col;
						choice(tmp_vyb1, kol_int);
						check_inter_row_col(matrix_int, row, col, tmp_vyb1, "получения", "");
						cout << "\nВаше значение " << matrix_int[tmp_vyb1 - 1]->Get(row - 1, col - 1) << endl;
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						system("cls");
						int row, col;
						choice(tmp_vyb1, kol_double);
						check_inter_row_col(matrix_double, row, col, tmp_vyb1, "получения", "");
						cout << "\nВаше значение " << matrix_double[tmp_vyb1 - 1]->Get(row - 1, col - 1) << endl;
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
					system("pause");
				}
				system("cls");
			} while (vyb != 0);
			break;
		case 10:     // получение максимального и минимального элемента матрицы
			system("cls");
			do {
				choice(vyb, "назад");
				if (vyb == 1) {
					if (matrix_int != NULL) {
						int Min=0, Max=0, tMin = 0, tMax = 0;
						system("cls");
						choice(tmp_vyb1, kol_int);
						cout << "\nМатрица " << tmp_vyb1 << endl;
						matrix_int[tmp_vyb1 - 1]->Show();
						Min = tMin = matrix_int[tmp_vyb1 - 1]->Get(0, 0);
						Max = tMax = matrix_int[tmp_vyb1 - 1]->Get(0, 0);
						for (int i = 1; i < matrix_int[tmp_vyb1 - 1]->Get_Rows(); i++) {
							matrix_int[tmp_vyb1 - 1]->MinMax(i, tMin, tMax);
							if (Min > tMin) Min = tMin;
							if (Max < tMax) Max = tMax;
						}
						cout << "\nМинимальное значение: " << Min << endl;
						cout << "Максимальное значение: " << Max << endl;
					}
					else cout << "\nМатриц целочисленного типа (int) не существует\n";
					system("pause");
				}
				if (vyb == 2) {
					if (matrix_double != NULL) {
						double Min = 0, Max = 0, tMin = 0, tMax = 0;
						system("cls");
						choice(tmp_vyb2, kol_double);
						cout << "\nМатрица " << tmp_vyb2 << endl;
						matrix_double[tmp_vyb2 - 1]->Show();
						Min = tMin = matrix_double[tmp_vyb2 - 1]->Get(0, 0);
						Max = tMax = matrix_double[tmp_vyb2 - 1]->Get(0, 0);
						for (int i = 1; i < matrix_double[tmp_vyb2 - 1]->Get_Rows(); i++) {
							matrix_double[tmp_vyb2 - 1]->MinMax(i, tMin, tMax);
							if (Min > tMin+1e-9) Min = tMin;
							if (Max < tMax - 1e-9) Max = tMax;
						}
						cout << "\nМинимальное значение: " << Min << endl;
						cout << "Максимальное значение: " << Max << endl;
					}
					else cout << "\nМатриц вещественного типа (double) не существует\n";
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
			cout << "Неверно! Повторите ввод!\n";
		}
	}
	system("pause");
	return 0;
}
