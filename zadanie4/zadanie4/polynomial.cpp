#include "polynomial.hpp"
#include <string>

using namespace std;


Polynominal::Polynominal(int d ,double wsp) : degree(d)
{
	coefficients = new double[degree+1];
	for (unsigned i = 0; i <= degree; ++i) coefficients[i] = wsp;
}


Polynominal::Polynominal(int d,double wsp[]) : degree(d)
{
	int s;
	coefficients = new double[degree+1];
	if (wsp[d] == 0.0 && degree != 0) throw string("Wspolczynniki przy najwyzszej potedze nie moze byc rowny 0.");
	for (unsigned i = 0; i <= d ; ++i)
	{
		coefficients[i] = wsp[i];
	}
}


Polynominal::Polynominal(const Polynominal &p) : degree(p.degree) 
{
	coefficients = new double[degree + 1];
	for (unsigned i = 0; i <= p.degree; ++i)
		coefficients[i] = p.coefficients[i];
}



inline Polynominal::~Polynominal(void)
{
	delete[] coefficients;
}


Polynominal& Polynominal::operator=(const Polynominal &p)
{
	degree = p.degree;
	coefficients = new double[degree+1];
	for (unsigned i = 0; i <= p.degree; ++i)
		coefficients[i] = p.coefficients[i];
	return *this;
}


inline Polynominal& Polynominal::operator += (const Polynominal &p)
{
	*this = *this + p;
	return *this ;
}


inline Polynominal& Polynominal::operator -= (const Polynominal &p)
{
	*this = *this - p;
	return *this ;
}


inline Polynominal& Polynominal::operator *= (const Polynominal &p)
{
	*this = *this * p;
	return *this ;
}



Polynominal operator + (const Polynominal &p1,const Polynominal &p2)
{
	int size_of_bigger = p1.get_degree() > p2.get_degree() ? p1.get_degree() : p2.get_degree();
	Polynominal poly = Polynominal(size_of_bigger);
	for (int i = 0 ; i <= size_of_bigger ; ++i)
	{
		poly[i] =  (p1.get_degree() >= i ? p1(i) : 0.0) + (p2.get_degree() >= i ? p2(i) : 0.0);
	}
	return poly;
}


Polynominal operator - (const Polynominal &p1,const Polynominal &p2)
{
	int size_of_bigger = p1.degree > p2.degree ? p1.degree : p2.degree;
	if(p1.degree == p2.degree)
		 while(size_of_bigger && p1.coefficients[size_of_bigger] == p2.coefficients[size_of_bigger] )
			 --size_of_bigger;
	Polynominal poly = Polynominal(size_of_bigger);
	for (int i = 0 ; i <= size_of_bigger ; ++i)
	{
		poly[i] =  (p1.degree >= i ? p1.coefficients[i] : 0.0) - (p2.degree >= i ? p2.coefficients[i] : 0.0);
	}
	return poly;
}



Polynominal operator * (const Polynominal &p1,const Polynominal &p2)
{
	int size = p1.degree + p2.degree;
	double *table = new double[size+1];
	for (int i = 0 ; i <= size ; ++i) table[i] = 0.0;
	
	for(int i = 0 ; i <= p1.degree ; ++i)
	{
		for(int j = 0 ; j <= p2.degree ; ++j)
		{
			table[i+j] +=  p1.coefficients[i] * p2.coefficients[j];
		}
	}
	Polynominal poly = Polynominal(size,table);
	delete[] table;
	return poly;
}


istream & operator >> (istream &input,Polynominal &p) 
{
	input >> p.degree ;
	delete[] p.coefficients;
	p.coefficients = new double[p.degree+1];
	for (unsigned i = 0; i <= p.degree; ++i)
		input >> p.coefficients[i];
	return input;
}


ostream & operator << (ostream &output,Polynominal &p) 
{
	output << p.degree << " " ;
	for (unsigned i = 0; i <= p.degree; ++i)
		output << p[i] << "x^" << i << " ";
	return output;
}


double Polynominal::operator () (double x)
{
	double result = coefficients[this->degree];
	for (int i = this->degree ; i > 0 ; --i)
	{
		result = x * result+ coefficients[i-1];
	}
	return result;
}



