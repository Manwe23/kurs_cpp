#ifndef POLYNOMINAL_HPP
#define POLYNOMINAL_HPP

#include <string>
#include <iostream>

using namespace std;

class Polynominal
{
	private:
		int degree;
		double * coefficients;
	public:
		Polynominal(int d = 0,double wsp=1.0);
		Polynominal(int,double[]);
		Polynominal(const Polynominal &);
		~Polynominal(void);
		int get_degree(void) const {return degree;}; 
		Polynominal& operator =(const Polynominal &);	
		double& operator [](unsigned index)
		{
			if(index>degree)
				 throw std::string("Index out of range!");
			 return this->coefficients[index];
		}; // operator odczyt/zapis
		double operator ()(unsigned index) const
		{
			if(index>degree)
				 throw std::string("Index out of range!");
			 return coefficients[index];
		}; //operator tylko do odczytu
		double operator () (double);
		Polynominal& operator +=(const Polynominal &);
		Polynominal& operator -=(const Polynominal &);
		Polynominal& operator *=(const Polynominal &);
		friend Polynominal operator + (const Polynominal &,const Polynominal &);
		friend Polynominal operator - (const Polynominal &,const Polynominal &);
		friend Polynominal operator * (const Polynominal &,const Polynominal &);
		friend istream & operator >> (istream &,Polynominal &) ;
		friend ostream & operator << (ostream &,Polynominal &) ;

	
};


class My_double
{
public:
	bool check;
	double val;

	My_double(double v, bool c): check(c), val(v)
	{
	}
	double& operator = (double d)
	{
		if (this->check && !d) throw string ("blad ! wsp. nie moze byc 0");
		return d;
	}
};


#endif
