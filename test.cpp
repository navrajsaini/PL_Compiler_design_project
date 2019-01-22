#include <iostream>
#include "token.h"
#include "symbol.h"

using namespace std;

int main ()
{
   //TEST THE TOKEN FUNCTIONS and SYMBOL FUNCTIONS
   cout << "starting..." << endl;
   Token a (NUM, 5, "five");
   cout << "a.getvalue: " << a.getValue() << endl;
   cout << "a.getSymbol: " << spellS(a.getSymbol()) << endl;
   cout << "a.getLexeme: " << a.getLexeme() << endl;
   return 0;
}
