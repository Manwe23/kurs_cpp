#include <iostream>

#include "dateTime.hpp"
#include "structures.hpp"


using namespace std;

void test(void)
{
	DateTime dt = DateTime();
	EventPair e;
	List * list = new List();
	Queue * queue = new Queue();
	int idx = 0;
	string s ;
	try
	{
		bool run = true;
		int option = 0;
		while(run)
		{
			cout << "wybierz opcje:" << endl;
			cout << "1 - Dodaj element do listy (format: index string)" << endl;
			cout << "2 - Usun element z listy (format index)" << endl;
			cout << "3 - Pokaz ilosc elementow na liscie" << endl;
			cout << "4 - Wyswietle Liste" << endl;
			cout << "6 - Dodaj element do kolejki (format string)" << endl;
			cout << "7 - Usun element z kolejki" << endl;
			cout << "8 - Pokaz ilosc elementow na liscie" << endl;
			cout << "9 - wyswietl kolejke" << endl;
			cout << "0 - zakoncz dzialanie programu" << endl;
			cin >> option;
			switch (option)
			{
				case 1:
					cin >> idx;
					cin >> s ;
					e = EventPair(s);
					cout << e << endl;
					list->add(e,idx);
					break;
				case 2:
					cin >> idx;
					list->remove(idx);
					break;
				case 3:
					cout << "Rozmiar listy: " << list->get_size() << endl;
					break;
				case 4:
					cout << *list << endl;
					break;
				case 6:
					cin >> s ;
					e = EventPair(s);
					queue->add(e);
					break;
				case 7:
					queue->remove();
					break;
				case 8:
					cout << "Rozmiar kolejki: " << queue->get_size() << endl;
					break;
				case 9:
					cout << *queue << endl;
					break;
				case 0:
					cout << "Bye! " << endl;
					run = false;
					break;
				default:
					cout << "Niepoprawna opcja !" << endl;
			}
		}
		delete list;
		delete queue;
	}
	catch (string err)
	{
		cerr << "Error occured: " << err << endl;
	}
}


int main()
{
	test();
	/*
	DateTime dt = DateTime();
	DateTime dt2;
	
	//cout << dt << endl;
	EventPair e1 = EventPair("ala ma kota");
	EventPair e = EventPair("0");
	e1 = e;
	List * list = new List(e);
	Queue * queue = new Queue(e);
	Queue queue2 = Queue(e);
	queue2 = *queue;
	cout << queue2;
	e.pair_event = "1";
	list->add(e,0);
	e.pair_event = "2";
	list->add(e,1);
	e.pair_event = "3";
	list->add(e,1);
	e.pair_event = "4";
	list->add(e,1);
	list->remove(1);
	List list1 = List(e);
	list1 = *list;
	cout << *list << endl;
	delete list;
	delete queue;
	cout << "przeszlo " << endl;
	cout << "size: " << list1.get_size() << endl;
	list1.add(e,0);
	cout << list1[2] << endl;
	cout << "przeszlo " << endl;
	dt2 = dt;
	cout << e1 << endl;
	char c; cin >> c;*/
	return 1;
}