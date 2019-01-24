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
   cout << "testing the insert function" << endl;
   Symtable symtest;
   int symb = symtest.insert("begin");
   cout << symb << endl;

   cout << "Printing the hash table..." << endl;
   symtest.printTable();
   
   cout << "testing search function" << endl;
   symb = symtest.search("begin");
   cout << "location is: " << symb << endl;
   
}
