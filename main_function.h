#pragma once
void quit();
void check_inter(int vyb, int min, int max);
void check_inter(int vyb, int min);
void choice(int& vyb, int kol_matrix);
void choice(int& vyb, const char* s);
void choice(int& vyb, int kol_matrix, int number);
void choice_show(int& vyb, const char* s);
void create_int_array_matrix(Matrix <int> **&matrix_int, int &kol_int);
void create_double_array_matrix(Matrix <double> **&matrix_int, int &kol_double);
void show_action_matrix(Matrix <int> *matrix, Matrix <int> **matrix_int, int &vyb, int &tmp_vyb1, int &tmp_vyb2, int operators);
void show_action_matrix(Matrix <double> *matrix, Matrix <double> **matrix_int, int &vyb, int &tmp_vyb1, int &tmp_vyb2, int operators);
void check_inter_row_col(Matrix <int> **matrix, int &row, int &col, int tmp_vyb1, const char* s, const char* str);
void check_inter_row_col(Matrix <double> **matrix, int &row, int &col, int tmp_vyb1, const char* s, const char* str);