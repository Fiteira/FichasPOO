#include <iostream>
#include <exception>
#include <math.h>
#include <vector>
using namespace std;
#include <fstream>


// https://www.tutorialspoint.com/cplusplus/cpp_exceptions_handling.htm
// https://www.geeksforgeeks.org/exception-handling-c/

//--------------------------------------------
void Excepcoes_EX_1(int i) {
    cout << " -------<" << __FUNCTION__ << ">" << endl;
	try {
		if (i < 0)
			throw i;
		if (i == 0)
			throw "Valor Nulo";
		throw 15.24;
	}
	catch(char *s) {
		cout << "Catch string: " << s << endl;
	}
	catch(int i) {
		cout << "Catch inteiro: " << i << endl;
	}
	catch(...) {
		cout << "Catch por defeito " << endl;
	}
}

//--------------------------------------------
void Excepcoes_EX_2(int age = 16)
{
    cout << " -------<" << __FUNCTION__ << ">" << endl;
    try {
        if (age >= 18) {
            cout << "Access granted" << endl;;
        }
        else {
            throw (age);
        }
    }
    catch (int myNum) {
        cout << "Access denied - You must be at least 18 years old.\n";
        cout << "Age is: " << myNum  << endl;
    }

 	catch(std::exception& Ex)
	{
        cout << "Error: " << Ex.what() << endl;
	}
}


double division(int a, int b) {
   if( b == 0 ) {
      //throw "Division by zero condition!";
      throw 10;
   }
   return (a/b);
}
//--------------------------------------------
void Excepcoes_EX_3(double x, int y)
{
  cout << " -------<" << __FUNCTION__ << ">" << endl;
   try {
      double z = division(x, y);
      cout << "Result of division: " << z << endl;
   }
   catch (int msg) {
     cerr << msg << endl;
   }
   catch (const char* msg) {
     cerr << msg << endl;
   }
}

//--------------------------------------------
void Excepcoes_EX_4()
{
  cout << " -------<" << __FUNCTION__ << ">" << endl;
  try
  {
     int * myarray = new int[1000000000000];
  }
  catch (bad_alloc &Ex)
  {
     cout << "bad_alloc detected: " << Ex.what() << endl;
  }
  catch (exception &Ex)
  {
     cout << "Exception Geral: " << Ex.what() << endl;
  }
}
//--------------------------------------------
void Excepcoes_EX_5()
{
  cout << " -------<" << __FUNCTION__ << ">" << endl;
  try
  {
     vector<int> V;
     V.push_back(10);
     V.push_back(20);
     cout << "Element at position 5 is: " << V.at(5) << endl;
  }
  catch (out_of_range &Ex)
  {
     cout << "out_of_range detected: " << Ex.what() << endl;
  }
    catch (domain_error &Ex)
  {
     cout << "domain_error detected: " << Ex.what() << endl;
  }
    catch (bad_alloc &Ex)
  {
     cout << "bad_alloc detected: " << Ex.what() << endl;
  }
    catch (exception &Ex)
  {
     cout << "Exception Geral: " << Ex.what() << endl;
  }
}
//--------------------------------------------
void Excepcoes_EX_6()
{
  cout << " -------<" << __FUNCTION__ << ">" << endl;
  try
  {
     FILE *F = fopen("ola", "r");
  }
  catch (domain_error &Ex)
  {
     cout << "domain_error detected: " << Ex.what() << endl;
  }
  catch (exception &Ex)
  {
     cout << "Exception Geral: " << Ex.what() << endl;
  }

}
//--------------------------------------------

class newException : public exception
{
    public:
	virtual const char* what() const throw()
	{
		return "newException occurred";
	}
} ;

void Excepcoes_EX_7() {
   cout << " -------<" << __FUNCTION__ << ">" << endl;
   try
   {
      throw newException();
   }
   catch(newException& Ex)
   {
      cout << "MyException caught" << Ex.what() << endl;
   }

   catch(exception& Ex) {
      cout << "Exception Geral: " << Ex.what() << endl;
   }

}
int main()
{
	cout << "INICIO Exemplos de Excepções" << endl;
	Excepcoes_EX_1(-3);
	Excepcoes_EX_1(0);
	Excepcoes_EX_1(8);

	Excepcoes_EX_2(89);
	Excepcoes_EX_2(12);

	Excepcoes_EX_3(2, 0);

	Excepcoes_EX_4();

	Excepcoes_EX_5();

	Excepcoes_EX_6();

	Excepcoes_EX_7();

	ofstream F("lixo.txt");
	F << "olala alala Muitos closes!" << endl;
	F.close();
	F.close();
	F.close();
	cout << "FIM Exemplos de Excepções" << endl;
}
