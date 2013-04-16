#include <iostream>

#include "matrix.hpp"
#include <string>

using namespace std;


Matrix::Matrix(void) : width(0), heigth(0)
{
	matrix = NULL;
	//matrix = nullptr; //g++ nie obsluguje nullptr
}


Matrix::Matrix(int h, int w) : width(w), heigth(h)
{
	matrix = new double*[w];
	for (int i = 0 ; i < w ; i++)
	{
		matrix[i] = new double[h];
		for (int j = 0 ; j < h ; j++)
		{
			matrix[i][j] = 0;
		}
	}
}



Matrix::Matrix(const Matrix & m) : width(m.width), heigth(m.heigth)
{
	matrix = new double*[m.width];
	for (int i = 0 ; i < m.width ; i++)
	{
		matrix[i] = new double[m.heigth];
		for (int j = 0 ; j < m.heigth ; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
}


Matrix Matrix::operator=(const Matrix & m)
{
	width = m.width;
	heigth = m.heigth;
	matrix = new double*[m.width];
	for (int i = 0 ; i < m.width ; i++)
	{
		matrix[i] = new double[m.heigth];
		for (int j = 0 ; j < m.heigth ; j++)
		{
			matrix[i][j] = m.matrix[i][j];
		}
	}
	return *this;
}



Matrix::~Matrix(void)
{
	for (int i = 0 ; i < width ; ++i)
		delete[] matrix[i];
	delete[] matrix;
}


void Matrix::transpose(void)
{
	double **new_matrix = new double*[heigth];
	for (int i = 0 ; i < heigth ; ++i)
	{
		new_matrix[i] = new double[width];
		for(int j = 0 ; j < width ; ++j)
			new_matrix[i][j] = matrix[j][i];
	}
	int tmp = width;
	width = heigth;
	heigth = tmp;
	for (int i = 0 ; i < width ; ++i)
		delete[] matrix[i];
	delete[] matrix;
	matrix = new_matrix;
}



Matrix operator *(double x, const Matrix & m)
{
	Matrix *matrix = new Matrix(m);
	

	for (int i = 0 ; i < matrix->width ; ++i)
		for (int j = 0 ; j < matrix->heigth; ++j)
			matrix->matrix[i][j] *= x;
	return *matrix;
}



Matrix operator *(const Matrix & m1, const Matrix & m2)
{
	Matrix *matrix = new Matrix(m1.heigth,m2.width);
	
	for (int i = 0 ; i < matrix->width ; ++i)
		for (int j = 0 ; j < matrix->heigth; ++j)
		{
			double sum = 0.0;
			for(int k = 0; k < m1.width; ++k)
				sum += m1.matrix[k][i] * m2.matrix[j][k];
			matrix->matrix[i][j] = sum;
		}	
	return *matrix;
}



Matrix operator +(const Matrix & m1, const Matrix & m2)
{
	Matrix *matrix = new Matrix(m1);
	

	for (int i = 0 ; i < matrix->width ; ++i)
		for (int j = 0 ; j < matrix->heigth; ++j)
			matrix->matrix[i][j] += m2.matrix[i][j];
	return *matrix;
}


Matrix operator -(const Matrix & m1, const Matrix & m2)
{
	Matrix *matrix = new Matrix(m1);
	

	for (int i = 0 ; i < matrix->width ; ++i)
		for (int j = 0 ; j < matrix->heigth; ++j)
			matrix->matrix[i][j] -= m2.matrix[i][j];
	return *matrix;
}



Matrix Matrix::operator*=(double x)
{
	for (int i = 0 ; i < width ; ++i)
		for (int j = 0 ; j < heigth; ++j)
			matrix[i][j] *= x;
	return *this;
}



Matrix Matrix::operator+=(const Matrix & m)
{
	for (int i = 0 ; i < width ; ++i)
		for (int j = 0 ; j < heigth; ++j)
			matrix[i][j] *= m.matrix[i][j];
	return *this;
}



Matrix Matrix::operator-=(const Matrix & m)
{
	for (int i = 0 ; i < width ; ++i)
		for (int j = 0 ; j < heigth; ++j)
			matrix[i][j] *= m.matrix[i][j];
	return *this;
}



istream & operator >> (istream & input, Matrix &m)
{
	
	for (int i = 0 ; i < m.heigth ; ++i)
	{
		for (int j = 0 ; j < m.width ; ++j)
			input >> m.matrix[j][i];
	}
	return input;
}


ostream & operator << (ostream & output, const Matrix &m)
{
	if(m.matrix == NULL) output << "empty";
	for (int i = 0 ; i < m.heigth ; ++i)
	{
		for (int j = 0 ; j < m.width ; ++j)
			output << m.matrix[j][i] << " ";
		output << endl;
	}
	output << endl;
	return output;
}
