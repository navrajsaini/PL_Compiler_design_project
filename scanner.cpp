/*
  part one, scanner.cpp
 */
#include "scanner.h"
#include <iostream>
using namespace std;

bool isWhitespace (char a)
{
   if(a==\0)
   {
      return true;
   }
}

bool isAlpha (char a)
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
}

bool isNumeric (char a)
{
   if(a>=48)
   {
      if(a<=57)
      {
	 return true;
      }
   }
   
}

bool isSpecial (char a)
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
      case'$':
      case':':
   }
   return false

   
}
