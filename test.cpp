#include <iostream>
#include "administration.h"

using namespace std;

int main ()
{
  
   //TESTING SCANNER && ADMIN
   
   cout << endl << endl << endl;
   cout << "--------testing scanner-----------";
   string codefile, tokenfile;
   string codef[8] =
      {"test1.txt", "test2.txt", "test3.txt",
       "test4.txt", "test5.txt", "test6.txt",
       "test7.txt", "testLang.txt"};
   
   string tokenf[8] =
      {"test1Out", "test2Out", "test3Out",
       "test4Out", "test5Out", "test6Out",
       "test7Out", "testLangOut"};
   for (int i = 0; i < 8; i++)
   {
      if (i == 7)
      {
	 cout << "testing the proper testLang file." << endl
	      << "There should not be any errorrs..."
	      << endl;
      }
      codefile = codef[i];
      tokenfile = tokenf[i];
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
   }
      return 0;
}
