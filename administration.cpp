/*
  provide services that are nto directly related to compiler phases.
  admininstration.cpp
 */
#include "administration.h"
#include <fstream>
#include <iostream>
#include "parser.h"


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
string Admin::doTheThing(int value)
{
   return view.symbolTable.giveLex(value);
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
input.close();
   return 1;
}

void Admin::lineAsn()
{
   for(int i=1; i<256; i++)
   {  
      lin[i][0]=view.lineToke[i][0];
lin[i][1]=view.lineToke[i][1];
cout<<lin[i][0]<<" "<<lin[i][1]<<" ";

   }
}
void Admin::parse()
{


   Parse parser(out);
   for(int i=1; i<256; i++)
   {
      parser.asn(i, 0, view.lineToke[i][0]);
      parser.asn(i, 1, view.lineToke[i][1]);
   }
input.open("tokenFile");
//cout<<parser.file.c_str()<<" ";
   string lex;
   int value;
   do{
      input>>value;
      parser.tokens(parserAsn(value));
//cout<<" "<<value<<" ";
   }while(!input.eof());

   input.close();

   parser.parseIt();

}
string Admin::parserAsn(int value)
{

return view.symbolTable.giveLex(value);
}
