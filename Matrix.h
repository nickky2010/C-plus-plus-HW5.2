#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
template <class M> class Matrix
{
private:
	int Rows;        // �����
	int Cols;        // �������
	M ** Data;       // ��� ������� � ������, ������ ���������� �� ����� ������, �.�. ��������� �� ���������
	M * DataMin;     // ��������� �� ����������� ��������
	M * DataMax;     // ��������� �� ������������ ��������

public:
	Matrix(int Row, int Col);
	Matrix(int Row, int Col, M max, M min, M c);
	~Matrix();
	Matrix(const Matrix& ob);
	M Get(int Row, int Col);
	int Get_Rows();
	int Get_Cols();
	M Get_Min(int Row);
	M Get_Max(int Row);
	void Set(int Row, int Col, M Data);
	void MinMax(int Row, M & Min, M & Max);
	void Init_Rand(M max, M min, M c);
	void Show();
	bool �ompare_sum(Matrix<M> ob1[], Matrix<M> ob2[]);
	bool �ompare_mult(Matrix<M> ob1[], Matrix<M> ob2[]);
	Matrix<M> operator+(const Matrix<M>& ob);
	Matrix<M> operator-(const Matrix<M>& ob);
	Matrix<M> operator*(Matrix<M>& ob);
	Matrix<M> operator/(Matrix<M>& ob);
	Matrix<M> operator=(const Matrix<M> ob);
	Matrix<M> transpose(Matrix<M>& ob);
	bool Revers_determinant(Matrix<M> ob[], M& determinant);
};

template<class M>
inline Matrix<M>::Matrix(int Row, int Col)           // �����������
{
	if (Row < 1) Row = 1;
	if (Col < 1) Col = 1;
	Rows = Row;                                      // �������� ���������� ���������� ���������� ���������
	Cols = Col;
	DataMin = new M[Rows];
	DataMax = new M[Rows];
	Data = new M *[Rows];               // ������� ������ ��� ������� ���������� �� ������ ��� �������
	for (int i = 0; i < Rows; i++) {    // ��� ������� ���� �������� ������ ��� �������� ��������� � �������� 
		Data[i] = new M[Cols];          
		DataMin[i] = 0;                 // ����������� ������� �������� ��� ������������ � ������������� ��������
		DataMax[i] = 0;
		for (int j = 0; j < Cols; j++) {// �������� ����� �������� ������
			Data[i][j] = 0;
		}
	}
}

template<class M>
inline Matrix<M>::Matrix(int Row, int Col, M max, M min, M c)  // ����������� ��� ��������������� ����������
{
	if (Row < 1) Row = 1;
	if (Col < 1) Col = 1;
	Rows = Row;                                      // �������� ���������� ���������� ���������� ���������
	Cols = Col;
	DataMin = new M[Rows];
	DataMax = new M[Rows];
	Data = new M *[Rows];               // ������� ������ ��� ������� ���������� �� ������ ��� �������
	for (int i = 0; i < Rows; i++) {    // ��� ������� ���� �������� ������ ��� �������� ��������� � �������� 
		Data[i] = new M[Cols];
		for (int j = 0; j < Cols; j++) {// �������� ����� �������� ������
			int tmp = rand() % (int)(max - min + 1) + min;
			Data[i][j] = c*tmp;
		}
	}
}

template<class M>
inline Matrix<M>::~Matrix()             // ����������
{
	for (int j = 0; j<Rows; j++) {      // ����������� ���������� ������ ��� ������� ���� 
		delete Data[j];
	}
	delete Data;                        // ����������� ���������� ������ ��� ������� ���������� �� ����
	delete DataMin;
	delete DataMax;
}

template<class M>
Matrix<M>::Matrix(const Matrix& ob)     // ����������� �����
{
	Rows = ob.Rows;                     // �������� ���������� ���������� ���������� ���������
	Cols = ob.Cols;
	DataMin = new M[ob.Rows];
	DataMax = new M[ob.Rows];
	Data = new M *[ob.Rows];            // ������� ������ ��� ������� ���������� �� ������ ��� �������
	for (int i = 0; i < ob.Rows; i++) { // ��� ������� ���� �������� ������ ��� �������� ��������� � �������� 
		Data[i] = new M[ob.Cols];
		DataMin[i] = ob.DataMin[i];                
		DataMax[i] = ob.DataMax[i];
		for (int j = 0; j < ob.Cols; j++) {
			Data[i][j] = ob.Data[i][j];
		}
	}
}

template<class M>
inline M Matrix<M>::Get(int Row, int Col) // ��������� ������
{
	// ��� �������� ������������ ������ ������� �������� ������
	if (Row < 0 || Row > Rows)          
		Row = 0;
	if (Col < 0 || Col > Cols)
		Col = 0;
	return Data[Row][Col];
};

template<class M>
inline int Matrix<M>::Get_Rows() // ��������� ������
{
	return Rows;
};

template<class M>
inline int Matrix<M>::Get_Cols() // ��������� ������
{
	return Cols;
};

template<class M>
inline M Matrix<M>::Get_Min(int Row) // ��������� ������
{
	// ��� �������� ������������ ������ ������� �������� ������
	if (Row < 0 || Row > Rows)
		Row = 0;
	return DataMin[Row];
};

template<class M>
inline M Matrix<M>::Get_Max(int Row) // ��������� ������
{
	// ��� �������� ������������ ������ ������� �������� ������
	if (Row < 0 || Row > Rows)
		Row = 0;
	return DataMax[Row];
};

template<class M>
inline void Matrix<M>::Set(int Row, int Col, M Data)  // ������������� (������) ������
{
	// ��� �������� ������������ ������ ������� ������ ������
	if (Row < 0 || Row > Rows)
		Row = 0;
	if (Col < 0 || Col > Cols)
		Col = 0;
	this->Data[Row][Col] = Data;
}

template<class M>
inline void Matrix<M>::MinMax(int Row, M &Min, M &Max)      // ��������� ������������ � ������������� �������� ��� ���� �������
{
	Min = Data[Row][0];                     // ������� �������� ������� ������� ����������� 
	Max = Data[Row][0];                     // ������� �������� ������� ������� ������������ 
	for (int i = 1; i < Cols; i++) {        // ���������� ������ �������� � �������
		if (Min > Data[Row][i])             // ���� ��� ������ ���� ��������, ������� �������� � DataMin, �� ����������� ����� ��������
			Min = Data[Row][i];
		if (Max < Data[Row][i])             // ���� ��� ������ ���� ��������, ������� �������� � DataMax, �� ����������� ����� ��������
			Max = Data[Row][i];
	}
}

template<class M>
inline void Matrix<M>::Init_Rand(M max, M min, M c)
{
	for (int i = 0; i<Rows; i++) {
		for (int j = 0; j<Cols; j++) {
			Data[i][j] = (M)rand() % (max - min * c + 1) + min;
		}
		MinMax(i);     // ������������� ����������� � ������������ �������� ��� ������� ����
	}
}

template<class M>
inline void Matrix<M>::Show()
{
	for (int i = 0; i<Rows; i++) {
		for (int j = 0; j<Cols; j++) {
			if (j < Cols - 1) cout << Data[i][j] << "\t";
			if (j==Cols-1) cout << Data[i][j] << "\n";
		}
	}
}

template<class M>
inline bool Matrix<M>::�ompare_sum(Matrix<M> ob1[], Matrix<M> ob2[])
{
	if (ob1->Get_Rows() == ob2->Get_Rows() && ob1->Get_Cols() == ob2->Get_Cols()) 
		return true;
	else return false;
}

template<class M>
inline bool Matrix<M>::�ompare_mult(Matrix<M> ob1[], Matrix<M> ob2[])
{
	if (ob1->Get_Cols() == ob2->Get_Rows())
		return true;
	else return false;
}

template<class M>
Matrix<M> Matrix<M>::operator +(const Matrix<M>& ob)// �������� ������
{
	Matrix<M> Temp(Rows, Cols);
	if (ob.Rows == Rows && ob.Cols == Cols) {
		for (int i = 0; i < ob.Rows; i++) { 
			for (int j = 0; j < ob.Cols; j++) {
				Temp.Data[i][j] = Data[i][j] + ob.Data[i][j];
			}
		}
	}
	return Temp;
}

template<class M>
Matrix<M> Matrix<M>::operator -(const Matrix<M>& ob)// �������� ������
{
	Matrix<M> Temp(Rows, Cols);
	if (ob.Rows == Rows && ob.Cols == Cols) {
		for (int i = 0; i < ob.Rows; i++) {
			for (int j = 0; j < ob.Cols; j++) {
				Temp.Data[i][j] = Data[i][j] - ob.Data[i][j];
			}
		}
	}
	return Temp;
}

template<class M>
Matrix<M> Matrix<M>::operator *(Matrix<M>& ob)// �������� ������
{
	Matrix<M> Temp(ob.Rows, ob.Cols);
	if (Cols == ob.Rows) {
		for (int i = 0; i < ob.Rows; i++) {
			for (int j = 0; j < ob.Cols; j++) {
				for (int k = 0; k < Cols; k++) {
					Temp.Data[i][j] += Data[i][k] * ob.Data[k][j];
				}
			}
		}
	}
	return Temp;
}

template<class M>
Matrix<M> Matrix<M>::operator /(Matrix<M>& ob)// ������� ������
{
	Matrix<M> Temp(ob.Rows, ob.Cols);
	Matrix<M> Temp1(ob.Rows, ob.Cols);
	for (int i = 0; i < ob.Rows; i++) {
		for (int j = 0; j < ob.Cols; j++) {
			Temp.Data[i][j] = ob.Data[i][j];
		}
	}
	M determinant = 0;
	if (Temp.Rows == Temp.Cols && Temp.Rows <= 3 && Temp.Revers_determinant(&Temp, determinant)) // ������� ������������ �������
	{
		if (Temp.Rows == 2) 
		{
			M tmp;
			tmp = Temp.Data[0][0];
			Temp.Data[0][0] = Temp.Data[1][1];
			Temp.Data[0][1] *= -1;
			Temp.Data[1][0] *= -1;
			Temp.Data[1][1] = tmp;
			for (int i = 0; i < ob.Rows; i++) {  // ������� �������� �������
				for (int j = 0; j < ob.Cols; j++) {
					Temp.Data[i][j] /= determinant;
				}
			}
			for (int i = 0; i < ob.Rows; i++) {  // "�����" �������
				for (int j = 0; j < ob.Cols; j++) {
					Temp1.Data[i][j] = Data[i][j] * Temp.Data[i][j];
				}
			}
			return Temp1;
		}
		if (Temp.Rows == 3)
		{   // �������������� ����������
			Temp.Data[0][0] = Temp.Data[1][1] * Temp.Data[2][2] - Temp.Data[2][1] * Temp.Data[1][2];
			Temp.Data[0][1] = -(Temp.Data[1][0] * Temp.Data[2][2] - Temp.Data[1][2] * Temp.Data[2][0]);
			Temp.Data[0][2] = Temp.Data[1][0] * Temp.Data[2][1] - Temp.Data[2][0] * Temp.Data[1][1];
			Temp.Data[1][0] = -(Temp.Data[0][1] * Temp.Data[2][2] - Temp.Data[2][1] * Temp.Data[0][2]);
			Temp.Data[1][1] = Temp.Data[0][0] * Temp.Data[2][2] - Temp.Data[0][2] * Temp.Data[2][0];
			Temp.Data[1][2] = -(Temp.Data[0][0] * Temp.Data[2][1] - Temp.Data[0][1] * Temp.Data[2][0]);
			Temp.Data[2][0] = Temp.Data[0][1] * Temp.Data[1][2] - Temp.Data[0][2] * Temp.Data[1][1];
			Temp.Data[2][1] = -(Temp.Data[0][0] * Temp.Data[1][2] - Temp.Data[0][2] * Temp.Data[1][0]);
			Temp.Data[2][2] = Temp.Data[0][0] * Temp.Data[1][1] - Temp.Data[0][1] * Temp.Data[1][0];
			for (int i = 0; i < ob.Rows; i++) {  // ������� �������� �������
				for (int j = 0; j < ob.Cols; j++) {
					Temp.Data[i][j] /= determinant;
				}
			}
			for (int i = 0; i < ob.Rows; i++) {  // "�����" �������
				for (int j = 0; j < ob.Cols; j++) {
					Temp1.Data[i][j] = Data[i][j]*Temp.Data[i][j];
				}
			}
		}
		return Temp1;
	}
	return *this;
}

template<class M>
Matrix<M> Matrix<M>::operator =(const Matrix<M> ob)// ������������ ������
{
	for (int i = 0; i < ob.Rows; i++) {
		for (int j = 0; j < ob.Cols; j++) {
			Data[i][j] = ob.Data[i][j];
		}
		DataMin[i] = ob.DataMin[i];
		DataMax[i] = ob.DataMax[i];
	}
	return *this;
}

template<class M>
Matrix<M> Matrix<M>::transpose(Matrix<M>& ob)// ���������������� �������
{
	Matrix<M> Temp(ob.Rows, ob.Cols);
	for (int i = 0; i < ob.Rows; i++) {
		for (int j = 0; j < ob.Cols; j++) {
			Temp.Data[i][j] = ob.Data[j][i];
		}
	}
	return Temp;
}

template<class M>
inline bool Matrix<M>::Revers_determinant(Matrix<M> ob[], M& determinant) // ������� ������������ �������
{
	determinant = 0;                          // ������������ �������
	if (ob->Get_Rows() == ob->Get_Cols() && ob->Get_Rows() <= 3) {
		if (ob->Get_Rows() == 2) 
		{
			determinant = ob->Get(0, 0)*ob->Get(1, 1) - ob->Get(0, 1)*ob->Get(1, 0);
		}
		else if (ob->Get_Rows() == 3) 
		{
			determinant = ob->Get(0, 0)*ob->Get(1, 1)*ob->Get(2, 2) - ob->Get(0, 0)*ob->Get(1, 2)*ob->Get(2, 1) -
				ob->Get(1, 0)*ob->Get(0, 1)*ob->Get(2, 2) + ob->Get(1, 0)*ob->Get(0, 2)*ob->Get(2, 1) +
				ob->Get(2, 0)*ob->Get(0, 1)*ob->Get(1, 2)- ob->Get(2, 0)*ob->Get(1, 1)*ob->Get(0, 2);
		}
	}
	if(determinant!=0) return true;
	else return false;
}




