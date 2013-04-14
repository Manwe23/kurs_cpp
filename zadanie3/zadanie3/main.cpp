#include <iostream>
#include <string>

#include "date.hpp"

using namespace std;

enum week
{
	Poniedzialek = 0,
	Wtorek = 1,
	Sroda = 2,
	Czwartek = 3,
	Piatek = 4,
	Sobota = 5,
	Niedziela = 6,
};


void test(void)
{
	int d,m,y;
	int w;
	Date data = Date();
	Date * data2;
	while(1)
	{
		cin >> d >> m >> y ;
		try
		{
			data2 = new Date(d,m,y);
			cout << "Od dzien: " << data.day << " miesiac: " << data.month << " rok: " << data.year << endl;
			cout << "Do dzien: " << data2->day << " miesiac: " << data2->month << " rok: " << data2->year << endl;
			cout << "uplynalo " << Date::days_from_to(*data2,data) << " dni" << endl;

			w = Date::days_from_to(Date(1,1,1582),*data2) + 4;
			switch(w%7)
			{
				case Poniedzialek:
					cout << "Jest to Poniedzialek" << endl;
					break;
				case Wtorek:
					cout << "Jest to Wtorek" << endl;
					break;
				case Sroda:
					cout << "Jest to Sroda" << endl;
					break;
				case Czwartek:
					cout << "Jest to Czwartek" << endl;
					break;
				case Piatek:
					cout << "Jest to Piatek" << endl;
					break;
				case Sobota:
					cout << "Jest to Sobota" << endl;
					break;
				case Niedziela:
					cout << "Jest to Niedziela" << endl;
					break;
			}
		}
		catch(string e)
		{
			cerr << e << endl;
		}
	}
}

int main(int arc, char * argv[])
{
	test();
	return 0;
}