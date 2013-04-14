#ifndef DATETIME_HPP
#define DATETIME_HPP

#include <iostream>
#include <string>

#include "date.hpp"
using namespace std;

class DateTime : public Date
{
	public:
		const int hour,minute,second;
		DateTime(void);
		DateTime(int,int,int,int,int,int);
		DateTime(const DateTime&);
		DateTime & operator = (const DateTime &dt) { return DateTime(dt);}; // zapytac
		friend ostream & operator << (ostream &output, DateTime &dt);
};

class EventPair
{
	public:
		DateTime date_time;
		string pair_event;

		EventPair(void) : date_time(DateTime()),pair_event("") {}
		EventPair(const EventPair & e) : date_time(e.date_time),pair_event(e.pair_event) {}
		EventPair(string s)
		{
			date_time = DateTime();
			pair_event = s;
		}
		EventPair(string s,DateTime dt) : date_time(dt),pair_event(s){}
		EventPair & operator = (const EventPair &e) 
		{
			date_time = e.date_time;
			pair_event = e.pair_event;
			return *this;
		}; 
		DateTime first(void) {return date_time;}
		string second(void) {return pair_event;}
		friend ostream & operator << (ostream &output, EventPair &e);
};


#endif