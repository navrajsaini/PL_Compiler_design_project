/*
  driver program
*/

#include <iostream>
#include <fstream>
#include "administration.h"
#include <stdio.h>
using namespace std;


int main ()
{
   // variables for file names
   /*remove testLang.txt when project complete*/
   //string codeFileName /*= "testLang.txt"*/, tokenFileName /* = "tokenFile"*/;
   string codeFileName = "./testfiles/testLang.txt",
         tokenFileName  = "./testfiles/tokenFile";
   //get the file name for input and then declare and open file
   cout<<"Welcome to compiler4600, please enter your code input file name: ";
   //cin>>codeFileName;
   //get the file name for output and then declare and open file
   cout<<endl<< "Now, please enter your scanner output file: ";
   //cin>>tokenFileName;
   
   remove(tokenFileName.c_str()); 

   cout<<endl;
   
   //creating a scanner 
   Scanner scan(codeFileName, tokenFileName);

   //run the compiler
   Admin compiler(codeFileName, tokenFileName, scan);

   //calls the scanner function.
   int stat = compiler.scan();
   char answer;
   //result msg
   if(stat == 1)
   {
	cout<< "Scan Complete" << endl;
	cout<<"would you like us to output the completed syboltable?";
	cout<<endl<<"Y(y)/N(n): ";
	cin>>answer;

	if(answer=='y'||answer=='Y')
	   compiler.print();//printing token list
   }
   else
      cout << "Scan errors have occoured" <<endl;
   
   //Time to parse
   compiler.parse();
   
   //--------------------------assembler-------------------
   //open the psudogen and create the output file for the interpreter
   ifstream infile;//psudogen is given to the assembler
   infile.open ("psudogen");

   //psudogen.Out file is given to the assember then passed to the interpreter
   ofstream outfile;
   outfile.open ("psudogen.Out");
   
   Assembler assemble(infile, outfile);

   cout << "Assembler first pass: "<<endl;
   assemble.firstPass();

   infile.close();
   infile.open ("psudogen");

   cout << "Assembler second pass: " << endl;
   assemble.secondPass();
   cout << "Assembler output file is: psudogen.Out. This will be passed"
	<< " to the interpreter now." << endl;
   Interpreter interp("psudogen.Out", true);
   return 0;
}
