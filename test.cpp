#include <iostream>
#include "administration.h"

using namespace std;

int main ()
{
  
   //TESTING SCANNER && ADMIN
   
   bool space, alpha, num;
   
   cout << endl << endl << endl;
   cout << "--------testing scanner-----------";
   string codefile = "testLang1.txt", tokenfile = "testOutput";
   
   //remove(tokenfile.c_str());
   cout << endl;
   
   Scanner scanTest (codefile, tokenfile);
   
      
   Admin compiler(codefile, tokenfile, scanTest);
   cout << "finished making the compiler..." << endl;
   int fin = compiler.scan();
   cout << "compile finished, output is: " << fin << endl;
   cout << endl << endl << "about to print... " << endl;
   compiler.print();

   cout << "the location of begin is: " << scanTest.getToken("begin") << endl;

   cout << "------------------testing parser-----------" << endl;
   compiler.parse();
   return 0;
}
