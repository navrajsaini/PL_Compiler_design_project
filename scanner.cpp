/*
  part one, scanner.cpp
 */
#include "scanner.h"
#include <iostream>
using namespace std;

//Returns true if character is whitespace

Scanner::Scanner(string inCodeName)//, Symtable &symbolTable)
{
   codeFileName=inCodeName;
   //infileptr.open(inCodeName.c_str());
}

bool Scanner::isWhitespace (char a)
{
   if(a==' ')
   {
      return true;
   }
   return false;
}
//returns true if character is an alphabet, based on ascii value
bool Scanner::isAlpha (char a)
{
   if(a>=65)
   {
      if(a<=90)
      {
	 return true;
      }
      if(a>=91)
      {
	 if(a<=122)
	 {
	    return true;
	 }
      }
   }
   return false;
}
//returns true if character is a numeric value via ascii
bool Scanner::isNumeric (char a)
{
   if(a>=48)
   {
      if(a<=57)
      {
	 return true;
      }
   }
   return false;
   
}
//returns true if character is special
bool Scanner::isSpecial (char a)
{
   switch(a)
   {
      case'.':
      case',':
      case';':
      case'[':
      case']':
      case'&':
      case'|':
      case'~':
      case'<':
      case'=':
      case'>':
      case'+':
      case'-':
      case'*':
      case'/':
      case 92:
      case'(':
      case')':
	 //case'$':
      case':':
	 break;
      default:
	 break;
   }
   return false;
}

Token Scanner::getToken()
{
//for self
//Token (Symbol s, int v, string l) : sname(s), svalue(attval(v, l))


   Symbol sym;
   int in;
   string strn;
   
   Token token(sym, in, strn);

      
   return token;
}

Token recognizeName()
{
   
}
Token recognizeSpecial();
Token recognizeNumeral();
Token recognizeComment();
