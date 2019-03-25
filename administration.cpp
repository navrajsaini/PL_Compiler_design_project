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
//irrelivant function, for testing purposes,
//that is soon to be removed in clean up
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
      view.LN++;
      lineNo++;
   }while(!input.eof());
/*
  for debuging purposes
  view.symbolTable.printTable();
  
*/
input.close();
   return 1;
}
//for the line test function stuff
//this is specically for the errreport in parser
void Admin::lineAsn()
{
   for(int i=1; i<256; i++)
   {  
      lin[i][0]=view.lineToke[i][0];
      lin[i][1]=view.lineToke[i][1];
   }
}
//theAdmin parse function
//starts by creating the parser then it goes onto launch the testline
//system for the error reporting 
//finaly it gets the tokens and proceeds to call the parser to parse through
//and find any errors
void Admin::parse()
{
   Parse parser(out);
   cout<<"Would you like to see the parser functions and info as they are called?";
   cout<<endl<<"Y(y)/N(n): ";
   string yn, yn2;
   cin>>yn;
   cout<<"Would you like to see completed block table before it is popped";
   cout<<endl<<"Y(y)/N(n): ";
   cin>>yn2;
   if(yn=="Y"||yn=="y")
      parser.yn=1;
   if(yn2=="Y"||yn2=="y")
      parser.yn2=1;
   string tempStr;
   for(int i=1; i<256; i++)
   {
      parser.asn(i, 0, view.lineToke[i][0]);
      parser.asn(i, 1, view.lineToke[i][1]);
      parser.asn(i, 2, view.lineToke[i][2]);
      //tempStr = view.symbolTable.htable[(view.lineToke[i][1])].getLexeme();
      //parser.asnS(i, tempStr);
   }
   input.open(parser.file.c_str());
   string lex;
   int value;
   while(!input.eof())
   {
      input>>value;
      parser.tokens(parserAsn(value));
   }
   input.close();
   parser.parseIt();

}
//for test line
string Admin::parserAsn(int value)
{
return view.symbolTable.giveLex(value);
}


