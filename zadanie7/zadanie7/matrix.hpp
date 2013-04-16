#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>

using namespace std;

class Matrix
{
	private:
		int width,heigth;
		double **matrix; 
	public:
		Matrix(int,int);
		Matrix(void);
		Matrix(const Matrix &);
		~Matrix(void);

		Matrix operator = (const Matrix &);
		Matrix operator *= (double);
		Matrix operator += (const Matrix &);
		Matrix operator -= (const Matrix &);
	
		void transpose(void);
		friend Matrix operator * (double x, const Matrix & m);
		friend Matrix operator * (const Matrix & m1, const Matrix & m2);
		friend Matrix operator + (const Matrix & m1, const Matrix & m2);
		friend Matrix operator - (const Matrix & m1, const Matrix & m2);
		friend istream & operator >> (istream &, Matrix &m);
		friend ostream & operator << (ostream &, const Matrix &m);
		
};

#endif
