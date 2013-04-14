#include "structures.hpp"
#include <iostream>
#include <string>

List :: List(void) : size(0), list(nullptr) {}


List :: List (EventPair & e)
{
	list = new Node(e);
	size = 1;
}


List :: ~List (void)
{
	
	if (size != 0) delete list;
	//cout << "Zakonczylem dzialanie destruktora List" << endl;
}


List::List (const List &l)
{
	Node * ptr = l.list;
	list = new Node(*(l.list->head));
	Node * ptr2 = list;
	while(ptr->tail != nullptr)
	{
		ptr = ptr->tail;
		ptr2->tail = new Node(*(ptr->head));
		ptr2 = ptr2->tail;
		++size;
	}
}

List & List::operator=(const List &l)
{
	//cout << "operator =" << endl;
	Node * ptr = l.list;
	if (size != 0) delete list;
	list = new Node(*(l.list->head));
	Node * ptr2 = list;
	while(ptr->tail != nullptr)
	{
		ptr2->tail = new Node(*(ptr->head));
		//cout << "wewnatrz '=', " << *(ptr->head) << endl;
		ptr2 = ptr2->tail;
		ptr = ptr->tail;
		++size;
	}
	
	return *this;
}

List & List::add(EventPair & e, int idx = 0)
{
	if (idx > size) throw string("Index out of range");
	Node * ptr = list;
	if (idx == 0)
		list = new Node(e,ptr);
	else
	{
		for (int i = idx ; i > 1 ; --i )
		{
			ptr = ptr->tail;
		}
		ptr->tail = new Node(e,ptr->tail);
	}
	++size;
	return *this;
}

List & List::remove(int idx = 0)
{
	if (idx >= size) throw string("Index out of range");
	Node * ptr = list;
	Node * removed_node;
	if (idx == 0)
	{
		list = list->tail;
		ptr->tail = nullptr;
		delete ptr;
	}
	else
	{
		for (int i = idx ; i > 1 ; --i )
		{
			ptr = ptr->tail;
		}
		removed_node = ptr->tail;
		ptr->tail = ptr->tail->tail;
		removed_node->tail = nullptr;
		delete removed_node;
	}
	--size;
	return *this;
}


ostream & operator << (ostream &output, List &l)
{
	List::Node * ptr = l.list;
	if (l.get_size() == 0) output << "List is empty";
	else
	{
		output << "{ " ;
		while(ptr != nullptr)
		{
			output <<  *(ptr->head) ;
			ptr = ptr->tail;
			if (ptr != nullptr) output << ", " ;
		}
		output << " }" ;
	}
	return output;
}



EventPair & List::operator[] (int idx)
{
	Node * ptr = list;
	if (idx >= size) throw string("Index out of range");
	for (int i = idx ; i > 0 ; --i )
	{
		ptr = ptr->tail;
	}
	return *ptr->head;

}

ostream & operator << (ostream &output, Queue &q)
{
	output << (List)q ;
	return output;
}


Queue & Queue::add(EventPair & e)
{
	List::add(e,size);
	return *this;
}


Queue & Queue::remove(void)
{
	List::remove(0);
	return *this;
}