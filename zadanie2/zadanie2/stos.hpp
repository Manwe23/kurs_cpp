#ifndef STOS_H
#define STOS_H

class Stos
{
  private:
    double * stos;
    int stack_pointer;
  public:
    
    const int size;

    Stos (void);
	Stos(const Stos &s);
    Stos (int) ;
	~Stos(void);

    void push(double);
    double pop(void);
	double head(void);
	int count(void) const;
};


#endif
