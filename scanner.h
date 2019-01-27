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
   Scanner(string inCodeName, string outFileName);//, Symtable &symbolTable);
   //~Scanner();//destructor
   int getToken(string token);
   void tokenLine(char now[], int y);
   
   void setName(string in, string out);
   char ahead;//look ahead character
   Symtable symbolTable;
  private:
   
   int luck;

   ofstream out;
   string codeFileName;
   string tokenFileName;

   

   bool isSpace (char a);
   
   bool isAlpha (char a);
   
   bool isNumeric (char a);
   
   bool isSpecial (char a);
   
   int recognizeName();
   int recognizeSpecial();
   int recognizeNumeral();
   bool isComment(char a);
};
#endif
