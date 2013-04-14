#ifndef STRUCTURES_HPP
#define STRUCTURES_HPP


#include "dateTime.hpp"
#include <iostream>


class List
{
	class Node
	{
		public:
			EventPair * head;
			Node * tail;
			Node(EventPair & e)
			{
				tail = nullptr;
				head = new EventPair(e);
			}
			Node(EventPair & e, Node * list)
			{
				head = new  EventPair(e);
				tail = list;
			}
			~Node(void)
			{
				delete head;
				if (tail != nullptr)
				{
					
					delete tail;
				}
			}
	};
	protected:
		Node * list;
		int size;
	public:
		List (void) ;
		List (EventPair &);
		List (const List &);
		~List(void);
		List & operator = (const List &) ;

		List & add(EventPair &, int idx);
		List & remove(int idx);
		EventPair & operator [] (int);
		int get_size(void){return size;}
		friend ostream & operator << (ostream &output, List &l);
};


class Queue : private List
{
	public:
		Queue (void) : List() {} 
		Queue (EventPair & e): List(e) {}
		Queue (const Queue & q) : List(q) {}
		~Queue(void) {};
		Queue & add(EventPair &e) ;
		Queue & remove(void);
		int get_size(void) {return List::get_size();}
		friend ostream & operator << (ostream &output, Queue &q);
};


#endif