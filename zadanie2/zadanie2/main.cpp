#include <iostream>
#include <string>

#include "stos.hpp"

using namespace std;


void test(void)
{
  string option;
  double x;
  int n;
  cout << "Stack size: ";
  cin >> n;
  try
  {
	  Stos stos = Stos(n);
	  while(1)
	  {
		try
		{
			cin >> option;
			if (option == "push")
			{
				cout << "> ";
				cin >> x ;
				stos.push(x);
				continue;
			}
			if (option == "pop")
			{
				cout << stos.pop() << endl;
				continue;
			}
			if (option == "head")
			{
				cout << stos.head() << endl;
				continue;
			}
			if (option == "count")
			{
				cout << stos.count() << endl;
				continue;
			}
			if (option == "help")
			{
				cout << "push (enter) n - push n into stack" << endl;
				cout << "pop - pop item from stack" << endl;
				cout << "head - get top item of stack" << endl;
				cout << "count - get number of items on stack" << endl;
				cout << "quit - shutdown this program" << endl;
				cout << "help - get help info" << endl;
				continue;
			}
			if (option == "quit") break;
			else cout << "Syntax error!" << endl;
		}
		catch(string s)
		{
			cout << "Error occurs! :" << s << endl;
		}
	  }
  }
  catch(string e)
  {
	char answer;
	cout << "Error occurs! :" << e << endl << "Quit ? (y/n): ";
	cin >> answer ;
	if (answer == 'n') test();

  }
}

int main(int arc, char * argv[])
{
  test();
  return 0;
}
