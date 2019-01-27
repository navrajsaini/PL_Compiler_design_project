/*
  driver program
*/

#include <iostream>
#include <fstream>
//#include "scanner.h"
#include "administration.h"
//#include "symboltable.h"
//#include "token.h"
#include <stdio.h>

using namespace std;

int main ()
{
   // variables for file names
   
   /*remove testLang.txt when project complete*/
   string codeFileName = "testLang.txt", tokenFileName = "tokenFile";

   //get the file name for input and then declare and open file
   cout<<"Welcome to compiler4600, please enter your code input file name: ";
   
   /*fix the commented out cin when complete */
   //cin>>CodeFileName;
   
   //ifstream codeFileIn;// TokenFileIn, 
   //codeFileIn.open(codeFileName.c_str());

   //get the file name for output and then declare and open file
   cout<<endl<< "Now, please enter your scanner output file: ";
   
   /*fix the commented out cin when complete */
   //cin>>TokenFileName;
   
   //ofstream tokenFileOut;
   remove(tokenFileName.c_str());
   //tokenFileOut.open(tokenFileName.c_str(), trunc);
   
   //tokenFileOut.close();
   

   cout<<endl;

   //create symbol table

   /*remove comments for the symbol table creation*/
   //Symtable table;
   
   //creating a scanner
   
   /* remove comments for scanner when scanner complete */
   Scanner scan(codeFileName, tokenFileName);//, table);


   //run the compiler

   /*decomment for running*/
   Admin compiler(codeFileName, tokenFileName, scan);

   /**/
   int stat = compiler.scan();
   /*
     if(stat == 1)
     cout<< "Scan Complete" << endl;
     else
     cout << "Scan errors have occoured" <<endl;
   */


   //codeFileIn.close();
   return 0;
}
