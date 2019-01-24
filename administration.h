/*
  administration.h for administration.cpp
 */
#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include <fstream>
#include "scanner.h"

#define MAXERRORS 10
//error for stage of prodject
enum errorType {ScanError, ParseError, ScopeError, TypeError};

using namespace std;

class Admin
{
  public:
//set up admin, input and output for the scanning
   Admin(ifstream& codeOn, ofstream tokenOut, Scanner &scan);
   ~Admin(){}

   //new line for input
   void newLine(){lineNo++; correctLine = true;}

   //error function for phases
   void error(string text);

   int scan();
  private:
   //output file
   ofstream *outputFilePtr;
   //scanner
   Scanner &scnr;

   //maintain current line number.
   int lineNo;

   //report an error only if the current line is true.
   bool correctLine;

   //count errors
   int errorCount;
};
#endif
