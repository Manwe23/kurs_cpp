#include <iostream>
#include "expression.hpp"

using namespace std;

int main(void)
{
	Expression *e1 = new Add(
				new Number(3.0),
				new Number(5.0)
				);

	cout << e1->count() << endl;
	cout << e1->description() << endl;

	Expression *e2 = new Add(
				new Number(2.0),
				new Multiply(
					new Variable("x"),
					new Number(7.0)
					)
				);
	cout << e2->count() << endl;
	cout << e2->description() << endl;

	Expression *e3 = new Divide(
						new Subtract(
							new Multiply(
								new Number(3.0),
								new Number(11.0)
							),
							new Number(1.0)
						),
						new Add(
							new Number(7),
							new Number(5)
							)
				);

	cout << e3->count() << endl;
	cout << e3->description() << endl;
	
	Expression *e4 = new Divide(
						new Multiply(
							new Add(
								new Variable("x"),
								new Number(1)
							),
							new Variable("x")
							),
						new Number(2.0)
					);

	cout << e4->count() << endl;
	cout << e4->description() << endl;


	Expression *e5 = new Sinus(
						new Add(
							new Multiply(
								new Number(2),
								new Variable("x")
							),
							new Number(1)
						)
					);

	cout << e5->count() << endl;
	cout << e5->description() << endl;

	char c;
	cin >> c ;
	cout << "Bye!" << endl;

	return 1;
}