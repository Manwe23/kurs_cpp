#include <iostream>
#include <string>


#include "polynomial.hpp"


using namespace std;


void test(void)
{
	double x;
	try
	{
		Polynominal w1 = Polynominal();
		Polynominal w2 = Polynominal();
		Polynominal w3 = Polynominal();
		cout << "Wielomian 1 (format: stopien a1 a2 a3 ... an)" << endl;
		cin >> w1 ;
		cout << "Wielomian 2 (format: stopien a1 a2 a3 ... an)" << endl;
		cin >> w2 ;
		w3 = w1 + w2;
		cout << w1 << endl << "+ " << w2 << endl << "= " << w3 << endl;
		w3 = w1 - w2;
		cout << w1 << endl << "- " << w2 << endl << "= " << w3 << endl;
		w3 = w1 * w2;
		cout << w1 << endl << "* " << w2 << endl << "= " << w3 << endl;
		cout << "dla jakiego x wyliczyc wartosc? :" ;
		cin >> x;
		cout << w1 << "(dla x = " << x << ") = " << w1(x) << endl;
		cout << w2 << "(dla x = " << x << ") = " << w2(x) << endl;
		cout << w3 << "(dla x = " << x << ") = " << w3(x) << endl;
	}
	catch(string e)
	{
		cerr << e << endl;
	}
}


int main(void)
{
	test();
	cout << "aby zakonczyc dzialanie programy wpisz dowolny znak... ";
	char c;cin >> c;
	return 1; 
}


