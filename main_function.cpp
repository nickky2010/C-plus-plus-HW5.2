#include <iostream>
#include "Matrix.h"
#include "main_function.h"
using namespace std;
void quit() {                          // функция выхода
	cout << "Завершение работы!\n";
	system("pause");
	exit(0);
}

void check_inter(int vyb, int min, int max)
{
	if (vyb < min || vyb>max) {
		if (vyb < min) cout << "Неверно! Количество должно быть не менее " << min << " !\n";
		else if (vyb > max) cout << "Неверно! Количество должно быть не более " << max << " !\n";
		cout << "Повторите ввод!\n";
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	}
}

void check_inter_row_col(Matrix <int>**matrix, int &row, int &col, int tmp_vyb1, const char* s, const char* str) {
	do {
		system("cls");
		cout << "\nМатрица " << tmp_vyb1 << str << endl;
		cout << "Для " << s << " элемента небходимо указать в каком он ряду и колонке\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "Укажите ряд матрицы: ";
		cin >> row;
		check_inter(row, 1, matrix[tmp_vyb1 - 1]->Get_Rows());
	} while (row < 1 || row > matrix[tmp_vyb1 - 1]->Get_Rows());
	do {
		system("cls");
		cout << "\nМатрица " << tmp_vyb1 << str << endl;
		cout << "Для " << s << " элемента небходимо указать в каком он ряду и колонке\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "Укажите колонку матрицы: ";
		cin >> col;
		check_inter(col, 1, matrix[tmp_vyb1 - 1]->Get_Cols());
	} while (col < 1 || col > matrix[tmp_vyb1 - 1]->Get_Cols());
}

void check_inter_row_col(Matrix <double>**matrix, int &row, int &col, int tmp_vyb1, const char* s, const char* str) {
	do {
		system("cls");
		cout << "\nМатрица " << tmp_vyb1 << str << endl;
		cout << "Для " << s << " элемента небходимо указать в каком он ряду и колонке\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "Укажите ряд матрицы: ";
		cin >> row;
		check_inter(row, 1, matrix[tmp_vyb1 - 1]->Get_Rows());
	} while (row < 1 || row > matrix[tmp_vyb1 - 1]->Get_Rows());
	do {
		system("cls");
		cout << "\nМатрица " << tmp_vyb1 << str << endl;
		cout << "Для " << s << " элемента небходимо указать в каком он ряду и колонке\n";
		matrix[tmp_vyb1 - 1]->Show();
		cout << "Укажите колонку матрицы: ";
		cin >> col;
		check_inter(col, 1, matrix[tmp_vyb1 - 1]->Get_Cols());
	} while (col < 1 || col > matrix[tmp_vyb1 - 1]->Get_Cols());
}

void check_inter(int vyb, int min)
{
	if (vyb < min) {
		if (vyb < min) cout << "Неверно! Количество должно быть не менее " << min << " !\n";
		cout << "Повторите ввод!\n";
		cin.clear();
		while (cin.get() != '\n');
		system("pause");
		system("cls");
	}
}

void choice(int& vyb, const char* s) {
	do {
		cout << "Выберите тип матрицы:\n";
		cout << "1 - целочисленный (int);\n";
		cout << "2 - вещественный (double);\n";
		cout << "0 - " << s << ";\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		check_inter(vyb, 0, 2);
	} while (vyb < 0 || vyb>2);
}

void choice(int& vyb, const char* s, const char* ) {
	do {
		cout << "Выберите тип матрицы:\n";
		cout << "1 - целочисленный (int);\n";
		cout << "2 - вещественный (double);\n";
		cout << "0 - " << s << ";\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		check_inter(vyb, 0, 2);
	} while (vyb < 0 || vyb>2);
}

void choice_show(int& vyb, const char* s) {
	do {
		system("cls");
		cout << "Выберите способ показа матриц:\n";
		cout << "1 - посмотреть определенную матрицу;\n";
		cout << "2 - посмотреть все матрицы данного типа;\n";
		cout << "0 - " << s << ";\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		check_inter(vyb, 0, 2);
	} while (vyb < 0 && vyb>2);
}

void choice(int& vyb, int kol_matrix) {
	do {
		cout << "Введите номер необходимой матрицы:\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		check_inter(vyb, 1, kol_matrix);
	} while (vyb < 1 || vyb>kol_matrix);
}

void choice(int& vyb, int kol_matrix, int number) {
	do {
		cout << "\nВведите номер "<<number<<" матрицы:\n";
		cout << "Ваш выбор: ";
		cin >> vyb;
		check_inter(vyb, 1, kol_matrix);
	} while (vyb < 1 || vyb>kol_matrix);
}

void create_int_array_matrix(Matrix <int> **&matrix_int, int &kol_int) {
	int Row=0; 
	int Col=0;
	int tmp_data;
	do {
		cout << "Введите количество матриц: ";
		cin >> kol_int;
		check_inter(kol_int, 1);
	} while (kol_int < 1);
	matrix_int = new Matrix <int>*[kol_int];
	for (int k = 0; k < kol_int; k++) {	
		do {
			system("cls");
			cout << "Введите количество рядов " << k + 1 << " матрицы: ";
			cin >> Row;
			check_inter(Row, 1);
		} while (Row < 1);
		do {
			cout << "Введите количество колонок " << k + 1 << " матрицы: ";
			cin >> Col;
			check_inter(Col, 1);
		} while (Col < 1);
		matrix_int[k] = new Matrix <int>(Row, Col);
		cout << "Введите данные в " << k + 1 << " матрицу:\n";
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
		cout << "Введите количество матриц: ";
		cin >> kol_double;
		check_inter(kol_double, 1);
	} while (kol_double < 1);
	matrix_double = new Matrix <double>*[kol_double];
	for (int k = 0; k < kol_double; k++) {
		do {
			system("cls");
			cout << "Введите количество рядов " << k + 1 << " матрицы: ";
			cin >> Row;
			check_inter(Row, 1);
		} while (Row < 1);
		do {
			cout << "Введите количество колонок " << k + 1 << " матрицы: ";
			cin >> Col;
			check_inter(Col, 1);
		} while (Col < 1);
		matrix_double[k] = new Matrix <double>(Row, Col);
		cout << "Введите данные в " << k + 1 << " матрицу:\n";
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
	cout << "\nМатрица " << tmp_vyb1 <<"\n";
	matrix_int[tmp_vyb1 - 1]->Show();
	cout << "\nМатрица " << tmp_vyb2 << "\n";
	matrix_int[tmp_vyb2 - 1]->Show();
	switch (operators) {
	case 1: 
		cout << "\nСумма матриц " << tmp_vyb1 << " и " << tmp_vyb2 << "\n";
		*matrix = *matrix_int[tmp_vyb1 - 1] + *matrix_int[tmp_vyb2 - 1];          // сложение
		break;
	case 2:
		cout << "\nРазность матриц " << tmp_vyb1 << " и " << tmp_vyb2 << "\n";
		*matrix = *matrix_int[tmp_vyb1 - 1] - *matrix_int[tmp_vyb2 - 1];          // сложение
		break;
	case 3:
		cout << "\nПроизведение матриц " << tmp_vyb1 << " и " << tmp_vyb2 << "\n";
		*matrix = *matrix_int[tmp_vyb1 - 1] * (*matrix_int[tmp_vyb2 - 1]);      // умножение
		break;
	case 4:
		cout << "\nДеление матрицы " << tmp_vyb1 << " на матрицу " << tmp_vyb2 << "\n";
		int determinant = 0;
		if (matrix_int[tmp_vyb2 - 1]->Get_Rows() == matrix_int[tmp_vyb2 - 1]->Get_Cols() &&
			matrix_int[tmp_vyb2 - 1]->Get_Rows()<=3 && 
			matrix_int[tmp_vyb2 - 1]->Revers_determinant(matrix_int[tmp_vyb2 - 1], determinant)) 
		{
			*matrix = *matrix_int[tmp_vyb1 - 1] / *matrix_int[tmp_vyb2 - 1];          // деление
			matrix->Show();
		}
		else if (matrix_int[tmp_vyb2 - 1]->Get_Rows() != matrix_int[tmp_vyb2 - 1]->Get_Cols()) 
			cout << "не имеет однозначного решения. Матрица " << tmp_vyb2 << " не является квадратной.\n";
		else if (matrix_int[tmp_vyb2 - 1]->Get_Rows() > 3) 
			cout << "невозможно. Программа не расчитана на деление матрицы размерностью больше чем 3х3.\n";
		else if (determinant==0) 
			cout << "не имеет однозначного решения. Определитель матрицы " << tmp_vyb2 << " равен 0.\n";
		break;
	}
	if (operators!=4) matrix->Show();
	vyb = tmp_vyb1 = tmp_vyb2 = 0;
	delete matrix;
}

void show_action_matrix(Matrix <double> *matrix, Matrix <double> **matrix_double, int &vyb, int &tmp_vyb1, int &tmp_vyb2, int operators) {
	cout << "\nМатрица " << tmp_vyb1 << "\n";
	matrix_double[tmp_vyb1 - 1]->Show();
	cout << "\nМатрица " << tmp_vyb2 << "\n";
	matrix_double[tmp_vyb2 - 1]->Show();
	switch (operators) {
	case 1:
		cout << "\nСумма матриц " << tmp_vyb1 << " и " << tmp_vyb2 << "\n";
		*matrix = *matrix_double[tmp_vyb1 - 1] + *matrix_double[tmp_vyb2 - 1];          // сложение
		break;
	case 2:
		cout << "\nРазность матриц " << tmp_vyb1 << " и " << tmp_vyb2 << "\n";
		*matrix = *matrix_double[tmp_vyb1 - 1] - *matrix_double[tmp_vyb2 - 1];          // сложение
		break;
	case 3:
		cout << "\nПроизведение матриц " << tmp_vyb1 << " и " << tmp_vyb2 << "\n";
		*matrix = *matrix_double[tmp_vyb1 - 1] * (*matrix_double[tmp_vyb2 - 1]);      // умножение
		break;
	case 4:
		cout << "\nДеление матрицы " << tmp_vyb1 << " на матрицу " << tmp_vyb2 << "\n";
		double determinant = 0;
		if (matrix_double[tmp_vyb2 - 1]->Get_Rows() == matrix_double[tmp_vyb2 - 1]->Get_Cols() &&
			matrix_double[tmp_vyb2 - 1]->Get_Rows() <= 3 &&
			matrix_double[tmp_vyb2 - 1]->Revers_determinant(matrix_double[tmp_vyb2 - 1], determinant))
		{
			*matrix = *matrix_double[tmp_vyb1 - 1] / *matrix_double[tmp_vyb2 - 1];          // деление
			matrix->Show();
		}
		else if (matrix_double[tmp_vyb2 - 1]->Get_Rows() != matrix_double[tmp_vyb2 - 1]->Get_Cols())
			cout << "не имеет однозначного решения. Матрица " << tmp_vyb2 << " не является квадратной.\n";
		else if (matrix_double[tmp_vyb2 - 1]->Get_Rows() > 3)
			cout << "невозможно. Программа не расчитана на деление матрицы размерностью больше чем 3х3.\n";
		else if (determinant == 0)
			cout << "не имеет однозначного решения. Определитель матрицы " << tmp_vyb2 << " равен 0.\n";
		break;
	}
	if (operators != 4) matrix->Show();
	vyb = tmp_vyb1 = tmp_vyb2 = 0;
	delete matrix;
}

