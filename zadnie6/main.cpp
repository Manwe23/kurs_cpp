#include <iostream>
#include "expression.hpp"

using namespace std;

int main(void)
{
	Number *n = new Number(2.0);
	Variable *x = new Variable("x");
	Add *a = new Add(n,x);
	Expression *e = new Add(
				new Number(2.0),
				new Multiply(
					new Variable("x"),
					new Number(7.0)
					)
				);
	cout << e->count() << endl;
	cout << e->description();
	cout << "Bye!" << endl;
	return 1;
}
