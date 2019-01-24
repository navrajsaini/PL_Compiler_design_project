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

using namespace std;

//error for stage of prodject
enum errorType {ScanError, ParseError, ScopeError, TypeError};

using namespace std;

class Admin
{
  public:
//set up admin, input and output for the scanning
   Admin(string inFile, string outFile, Scanner &scan);
   ~Admin(){}

   //new line for input
   void newLine(){lineNo++; correctLine = true;}

   //error function for phases
   void error(string text);

   int scan();
   
  private:
   //output file

   ifstream input;
   ofstream output;
   string in;
   string out;
   //scanner
   Scanner scnr;

   //maintain current line number.
   int lineNo;

   //report an error only if the current line is true.
   bool correctLine;

   //count errors
   int errorCount;
};
#endif
