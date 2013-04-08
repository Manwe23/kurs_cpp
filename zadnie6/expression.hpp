#ifndef EXPRESSION_HPP
#define EXPRESSION_HPP

#include <string>
#include <sstream>
#include <vector>

using namespace std;

class Expression
{
	public:
		virtual double count(void) = 0;
		virtual std::string description(void) = 0;
};


class Number : Expression
{
	public:
		double value;

	Number(double v) : value(v){};
	virtual double count(void)
	{
		return value;
	}
	virtual std::string description(void)
	{
		std::ostringstream tmp;
		tmp << value;
		return tmp.str(); 
	}
};


class Variable : Expression
{
	public:
		std::string name;
		static vector<pair<string,double> > var_val;		

		Variable (string s) : name(s){}
		virtual double count(void)
		{
			return get_var_val(name) ;
		}
		virtual string description(void)
		{

			return name;
		}
		static double get_var_val(string var)
		{ return 1.0;}
};

#endif
