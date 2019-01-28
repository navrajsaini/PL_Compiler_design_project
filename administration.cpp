/*
  provide services that are nto directly related to compiler phases.
  admininstration.cpp
 */
#include "administration.h"
#include <fstream>
#include <iostream>

using namespace std;
//constructing an admin object
Admin::Admin(string inFile, string outFile, Scanner &sn)
{
   in = inFile;
   out = outFile;
   //scnr = &scan;
   view.setName(in, out);
   view.symbolTable.loadResvd();
}

//returning line number
int Admin::getLineNo()
{
   return lineNo;
}
//printing token list
void Admin::print()
{
   view.symbolTable.printTable();
}
//the scan function for admin, it wipes out now[] then it takes a line and inserts
// into now, after that it will call tokenLine to deal with the contents of now[]
//it ends when eof has been reached
//test exist inside, view symtbl prints the table.
int Admin::scan()
{
   char now[256];
   input.open(in.c_str());

   do{
      //clearing the array of characters
      for(int j=0;j<255;j++)
	 now[j]=' ';  
      input.getline(now,256);   
      view.tokenLine(now, 256);
      lineNo++;
   }while(!input.eof());
/*
  for debuging purposes
  view.symbolTable.printTable();
*/
   return 1;
}
