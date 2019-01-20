/*
  member functions for getting and setting the data members
  as well as other members as needed.
  token.cpp
 */
#include "token.h"
#include <iostream>

Symbol token::getSymbol()const
{
   return sname;
}

int token::getValue()const
{
   return svalue.value;
}
string token::getLexeme()const
{
   return svalue.lexeme;
}
