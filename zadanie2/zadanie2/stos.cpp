#include "stos.hpp"
#include <string>

using namespace std;
Stos :: Stos (void) : size(1)
{
  stos = new double[1];
  stack_pointer = -1;
  
}

Stos :: Stos(const Stos &s) : size(s.size)
{
	stack_pointer = -1;
	stos = new double[s.size];
	for(int i = 0 ; i < s.count() ; i++ )
		this->push(s.stos[i]);
}

Stos :: Stos (int s) : size(s)
{
  if (s < 1)  throw string("Stack size must be positive.");
  stack_pointer = -1;
  stos = new double[s];
}

Stos :: ~Stos(void)
{
	delete[] stos;
}


void Stos :: push(double a)
{
  if (stack_pointer == size - 1) throw string("Unable to push a item. Stack owerflow!");

  stos[++stack_pointer] = a;
  
}

double Stos :: pop(void)
{
  if (stack_pointer == -1) throw string("Unable to pop a item. Stack empty!");
  return stos[stack_pointer--];
}


double Stos :: head(void)
{
  if (stack_pointer == -1) throw string("Stack empty!");
  return stos[stack_pointer];
}

int Stos :: count(void) const
{
	return stack_pointer + 1;
}