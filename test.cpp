#include <iostream>
#include "administration.h"
#include "BlockTable.h"
#include "Assembler.h"
#include "interp.h"
using namespace std;

int main ()
{

   //TESING SCANNER && ADMIN
   ifstream infile;
   ofstream outfile;
   cout << endl << endl << endl;
   cout << "--------testing scanner-----------";
   string codefile, tokenfile;
   string codef[8] =
      {
	 "./testfiles/test1.txt", "./testfiles/test2.txt",
	 "./testfiles/test3.txt", "./testfiles/test4.txt",
	 "./testfiles/test5.txt", "./testfiles/test6.txt",
	 "./testfiles/test7.txt", "./testfiles/testLang.txt"};

   string tokenf[8] =
      {"./testfiles/test1.Out", "./testfiles/test2.Out",
       "./testfiles/test3.Out", "./testfiles/test4.Out",
       "./testfiles/test5.Out", "./testfiles/test6.Out",
       "./testfiles/test7.Out", "./testfiles/testLang.Out"};
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
      cout << endl;

      Scanner scanTest (codefile, tokenfile);
      Admin compiler(codefile, tokenfile, scanTest);
      cout << "finished making the compiler..." << endl;
      int fin = compiler.scan();
      cout << "compile finished, output is: " << fin << endl;
      cout << endl << endl << "about to print... " << endl;
      compiler.print();

      //   cout << "the location of begin is: " << scanTest.getToken("begin") << endl;

      cout << "------------------testing parser-----------" << endl;
      compiler.parse();
      // if ctd is false there is a error in the parser
      // so the assembler will not run.
      if (compiler.ctd == true)
      {
	 cout << "-------------------testing assembler----------" << endl;
	 outfile.open(tokenfile);
	 infile.open("psudogen");
	 Assembler a(infile, outfile);
	 
	 cout << "first run" << endl;
	 a.firstPass();
	 
	 cout << "second run" << endl;
	 outfile.close();
	 infile.close();
	 
	 outfile.open(tokenfile);
	 infile.open("psudogen");
	 a.secondPass();
	 
	 cout << "------------------testing interpreter----------" << endl;
	 Interpreter b(tokenfile, true);
      }
      return 0;
   }
}
