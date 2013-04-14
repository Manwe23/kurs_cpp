#include "expression.hpp"
#include <string>
#include <cmath>

using namespace std;
void Add::testowa(void)
{
	1 == 1;
}

double Add::count (void)
{
	return left->count() + right->count();
}

string Add::description(void)
{
	return "("+left->description() + " + " + right->description()+")";

}


double Subtract::count (void)
{
	return left->count() - right->count();
}

string Subtract::description(void)
{
	return "("+left->description() + " - " + right->description()+")";

}


double Multiply::count (void)
{
	return left->count() * right->count();
}

string Multiply::description(void)
{
	return "("+left->description() + " * " + right->description()+")";

}


double Divide::count (void)
{
	return left->count() / right->count();
}

string Divide::description(void)
{
	return "("+left->description() + " / " + right->description()+")";

}



double Neg::count (void)
{
	return (-1.0) * value->count();
}

string Neg::description(void)
{
	return " -" + value->description();

}


double Sinus::count (void)
{
	return sin(value->count());
}

string Sinus::description(void)
{
	return "sin(" + value->description()+")";

}


double Cosinus::count (void)
{
	return cos(value->count());
}

string Cosinus::description(void)
{
	return " cos(" + value->description()+")";

}


double Absolute::count (void)
{
	return  abs(value->count());
}

string Absolute::description(void)
{
	return "|" + value->description()+"|";

}


double Log::count (void)
{
	double tmp = left->count();
	if (tmp == 2.72) return log(right->count());
	else if (tmp == 10.0) return log10(right->count());
	else throw string("Logarithm base must be E or 10.0");
}

string Log::description(void)
{
	return  "log_"+left->description()+"^" + right->description();

}


double Power::count (void)
{
	return pow(left->count(),right->count());

}

string Power::description(void)
{
	return left->description() + "^" + right->description();

}








