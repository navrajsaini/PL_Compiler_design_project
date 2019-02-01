#include <iostream>
#include "administration.h"

using namespace std;

int main ()
{
   /*
   //TEST THE TOKEN FUNCTIONS and SYMBOL FUNCTIONS
   cout << "---------testing the token and symbol functions----" << endl;
   Token a (NUM, 5, "five");
   cout << "a.getvalue: " << a.getValue() << endl;
   cout << "a.getSymbol: " << spellS(a.getSymbol()) << endl;
   cout << "a.getLexeme: " << a.getLexeme() << endl;
   
   cout << "testing the insert fuction... " << endl;
   a.insert(cout);
   
   cout << "testing the overloaded << funciton: " << endl << a;
   cout << "testing the overloaded = func: " << endl;
   Token b = a;
   b.insert(cout);
   //---------------------------------------------------------
   //TESTING THE SYMBOLTABLE
   cout << endl << endl << endl;
   cout << "--------testing the symboltable functions-----------" << endl;
   Symtable symtest;
   cout << "loading the reserved words...." << endl;
   symtest.loadResvd();
   
   cout << endl << "Printing the hash table..." << endl;
   symtest.printTable();

   cout << "testing search function" << endl;
   int symb = symtest.search("end");
   cout << "location for end token is: " << symb << endl;
   cout << "testing inserting a id that's already in it. "
	<< "the loc of od: " << symtest.insert("od") << endl;
   
   cout << "the loc of if: " << symtest.search("if") << endl
	<< "the loc of fi: " << symtest.search("fi") << endl;

   */
   //---------------------------------------------------------
   //TESTING SCANNER && ADMIN
   
   bool space, alpha, num;
   
   cout << endl << endl << endl;
   cout << "--------testing scanner-----------";
   string codefile = "testLang1.txt", tokenfile = "testOutput";
   
   //remove(tokenfile.c_str());
   cout << endl;
   
   Scanner scanTest (codefile, tokenfile);
   
   cout << "the location of do is: " << scanTest.getToken("do") << endl;
   
   Admin compiler(codefile, tokenfile, scanTest);
   cout << "finished making the compiler..." << endl;
   int fin = compiler.scan();
   cout << "compile finished, output is: " << fin << endl;
   cout << endl << endl << "about to print... " << endl;
   compiler.print();
   
   /*
   space = scanTest.isSpace(' ');
   alpha = scanTest.isAlpha('A');
   num = scanTest.isNumeric('5');

   cout << "' ' is a space? " << space << endl
   << "A is alpha? " << alpha << endl
	<< "5 is numeric? " << num << endl;
   */
   return 0;
}
