#include <iostream>
#include "administration.h"
#include "BlockTable.h"
using namespace std;

int main ()
{
  
   //TESTING SCANNER && ADMIN
   
   cout << endl << endl << endl;
   cout << "--------testing scanner-----------";
   string codefile, tokenfile;
   string codef[8] =
      {"./test/test1.txt", "./test/test2.txt", "./test/test3.txt",
       "./test/test4.txt", "./test/test5.txt", "./test/test6.txt",
       "./test/test7.txt", "./test/testLang.txt"};
   
   string tokenf[8] =
      {"./test/test1.Out", "./test/1test2.Out", "./test/test3.Out",
       "./test/test4.Out", "./test/test5.Out", "./test/test6.Out",
       "./test/test7.Out", "./test/testLang.Out"};
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
