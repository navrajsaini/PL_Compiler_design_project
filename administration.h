/*
  administration.h for administration.cpp
 */
#ifndef ADMIN_H
#define ADMIN_H
#include <string>
#include <iostream>
#include <fstream>
#include "scanner.h"
#include "interp.h"
#include "Assembler.h"
#define MAXERRORS 10

using namespace std;

//error for stage of prodject
enum errorType {ScanError, ParseError, ScopeError, TypeError};

using namespace std;

class Admin
{
  public:
//set up admin, input and output for the scanning
   Admin();  
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
   //the parse function
   void parse();
   //-----------
   //Specific functions for code Gen part
   //irrelivant function, keeping for testing purposes
   string doTheThing(int);
   void emit1 (string);
   void emit2 (string, int);
   void emit3 (string, int, int);
   bool emitting = 1;
   bool ctd = true, tst = 0;
   
   //--------
  private:
   ifstream input;//for input file
   ofstream output, outsource;//for output file
   string in;//name of input file
   string out;//name of output file
   string codeGen = "psudogen";
   //scanner
   Scanner view;//created scanner for admin
   //assn test line
   void lineAsn();
   //another of the test line arrays
   //I was having some problems passing line back from scanner,
   //and then to parser so i made these
   int lin[256][2];
   string parserAsn(int value);

   //maintain current line number.
   int lineNo;

   //report an error only if the current line is true.
   bool correctLine;

   //count errors
   int errorCount;
   //test line array
   int TL[256];

   //bool to make sure we can still input stuff to the output file

   
};
#endif
