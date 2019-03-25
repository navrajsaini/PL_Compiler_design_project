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
   ~Scanner(){}//destructor
   int getToken(string token);//gets and stores token, sends back token value
   //this fixes the lexeme problem with numbers.
   int getNum(string token);
   void tokenLine(char now[], int y);//looks at and goes through each line of text
   //then stores the token in the vecotor and the value in a file

   void setName(string in, string out);   //set name for files
   char ahead;//look ahead character
   Symtable symbolTable;//symbol table that has inserted tokens
   int lineToke[256][3]; //line token test stuff

   int LN;//   line number 
   int numericVAl(string);
  private:
   

   int TN=1;// Token number
   void inc(int);
   ofstream out;//for outputing to file in tokenLine
   string codeFileName;//name of codefile
   string tokenFileName;//name of token file

   bool isSpace (char a);//checks if char is a space
   bool isAlpha (char a);//checks is char is alpha
   bool isNumeric (char a);//checks if char is numeric
   bool isSpecial (char a);//checks if char is a special symbol
   bool isComment(char a);//checks if there is a comment on this line.
};
#endif
