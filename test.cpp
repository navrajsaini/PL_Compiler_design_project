#include "token.h"
#include "administration.h"
#include "scanner.h"
#include "symbol.h"


using namespace std;

int main ()
{
   //test the spellS function
   cout << spellS(NUM) << endl;
   //test the create a token function
   Token a(NUM, 5, "five");
   //create using the default contructor
   Token b;   
}
