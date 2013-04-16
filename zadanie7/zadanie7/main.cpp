#include <iostream>

#include "matrix.hpp"


using namespace std;

int main()
{
	cout << "dziala" << endl;
	Matrix *m = new Matrix(2,3);
	Matrix m2 = Matrix(*m);
	cout << m2;
	cin >> m2;
	*m = m2;
	m2.transpose();
	cout << (*m)  * m2;
	char c;
	cin >> c;
	return 1;
}
