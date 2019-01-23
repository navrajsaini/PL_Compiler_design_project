/*
  By: Navraj Saini and Jordan Kolody
  part one, scanner.h
  scanner class interface
  main interface function" Token getToken()
   reads the input stream and recognizes adn returns the next token
*/

#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include <fstream>
#include <string>
#include "token.h"
#include "symboltable.h"

using namespace std;

class Scanner
{
  public:
   Scanner(){}//default constructor, doesn't do anything
   Scanner(ifstream &in, Symtable &symt);
   ~Scanner();//destructor
   Token getToken();

  private:
   ifstream *infileptr;
   Symtable *symtableptr;
   chat laChar;//look ahead character

   bool isWhitespace (char a);
   bool isAlpha (char a);
   bool isNumeric (char a);
   bool isSpecial (char a);
   Token recognizeName();
   Token recognizeSpecial();
   Token recognizeNumeral();
   Token recognizeComment();
};
#endif
