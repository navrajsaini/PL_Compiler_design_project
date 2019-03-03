/*
  administration.h for administration.cpp
 */
#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include <fstream>
#include "scanner.h"
//#include "parser.h"

#define MAXERRORS 10

using namespace std;

//error for stage of prodject
enum errorType {ScanError, ParseError, ScopeError, TypeError};

using namespace std;

class Admin
{
  public:
//set up admin, input and output for the scanning
   Admin(string inFile, string outFile, Scanner &sn);
   ~Admin(){}

   //new line for input
   void newLine(){lineNo++; correctLine = true;}
   // Getter for line number.
   int getLineNo();
   
   //error function for phases
   void error(string text);
   //calls the scanner and sends it a line to be scanned.
   int scan();

   //printing for the symtable
   void print();
   void parse();
   string doTheThing(int);
   
  private:
   ifstream input;//for input file
   ofstream output;//for output file
   string in;//name of input file
   string out;//name of output file
   //scanner
   Scanner view;//created scanner for admin
   void lineAsn();
   int lin[256][2];
   string parserAsn(int value);

   //maintain current line number.
   int lineNo;

   //report an error only if the current line is true.
   bool correctLine;

   //count errors
   int errorCount;

   int TL[256];
   
};
#endif
