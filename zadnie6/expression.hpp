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


class Number : public Expression
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


class Variable : public Expression
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
		
		static void add_var_val(string var, double value);
		static double get_var_val(string var)
		{ return 1.0;}
};


class Add : public Expression
{
	public:
		Expression *left,*right;
	
		Add(Expression* l, Expression* r)
		{
			left = l;
			right = r;
		}
		virtual double count(void);
		/*{
			return left->count() + right->count();
		}*/
		virtual string description(void);
		/*{
			return "test";
		}*/
		void testowa(void);
				
};


class Subtract : public Expression
{
	public:
		Expression *left,*right;
	
		Subtract(Expression* l, Expression* r)
		{
			left = l;
			right = r;
		}
		virtual double count(void);
		
		virtual string description(void);
		
				
};


class Multiply : public Expression
{
	public:
		Expression *left,*right;
	
		Multiply(Expression* l, Expression* r)
		{
			left = l;
			right = r;
		}
		virtual double count(void);
		
		virtual string description(void);
		
				
};


class Divide : public Expression
{
	public:
		Expression *left,*right;
	
		Divide(Expression* l, Expression* r)
		{
			left = l;
			right = r;
		}
		virtual double count(void);
		
		virtual string description(void);
		
				
};


class Neg : public Expression
{
	public:
		Expression * value;
		
		Neg (Expression* v) : value(v) {};
		
		virtual double count(void);
		virtual string description(void);
};

class Sinus : public Expression
{
	public:
		Expression * value;
		
		Sinus (Expression* v) : value(v) {};
		
		virtual double count(void);
		virtual string description(void);
};



class Cosinus : public Expression
{
	public:
		Expression * value;
		
		Cosinus (Expression* v) : value(v) {};
		
		virtual double count(void);
		virtual string description(void);
};


class Absolute : public Expression
{
	public:
		Expression * value;
		
		Absolute (Expression* v) : value(v) {};
		
		virtual double count(void);
		virtual string description(void);
};


class Log : public Expression
{
	public:
		Expression *left,*right;
	
		Log(Expression* l, Expression* r)
		{
			left = l;
			right = r;
		}
		virtual double count(void);
		
		virtual string description(void);
		
				
};


class Power : public Expression
{
	public:
		Expression *left,*right;
	
		Power(Expression* l, Expression* r)
		{
			left = l;
			right = r;
		}
		virtual double count(void);
		
		virtual string description(void);
		
				
};







#endif
























