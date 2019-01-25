#include <iostream>
#include "token.h"
#include "symboltable.h"

using namespace std;

int main ()
{
   //TEST THE TOKEN FUNCTIONS and SYMBOL FUNCTIONS
   cout << "starting..." << endl;
   Token a (NUM, 5, "five");
   cout << "a.getvalue: " << a.getValue() << endl;
   cout << "a.getSymbol: " << spellS(a.getSymbol()) << endl;
   cout << "a.getLexeme: " << a.getLexeme() << endl;
   
   cout << "testing the insert fuction... " << endl;
   a.insert(cout);
   
   cout << "testing the overloaded << funciton: " << endl << a;

   //---------------------------------------------------------
   //TESTING THE SYMBOLTABLE
   cout << endl << endl << endl;
   cout << "testing the insert symboltable function" << endl;
   Symtable symtest;
   int symb = symtest.insert("begin");
   cout << symb << endl << endl;

   cout << "Printing the hash table test... won't do anything" << endl
	<< "because whenever we run the <Token>.insert(cout) or "
	<< "cout << <Token>" << endl
	<< "the program decides it doesn't like me..." << endl
	<< "it's the spellS function." << endl;
   symtest.printTable();
   cout << endl << endl << "testing search function" << endl;
   symb = symtest.search("begin");
   cout << "location for begin token is: " << symb << endl;
   return 0;
}
