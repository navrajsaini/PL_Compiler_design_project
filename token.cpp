/*
  member functions for getting and setting the data members
  as well as other members as needed.
  token.cpp
 */
#include "token.h"
#include <iostream>

using namespace std;

string spellS(Symbol s)
{
   switch (s){
      case NUM: return "Number"; break;
      case DIV: return "/"; break;
      case MOD: return "%"; break;
      case SEMICOLON: return ";"; break;
      case PLUS: return "+"; break;
      case MINUS: return "-"; break;
      case TIMES: return "*"; break;
      case DIVIDE: return "/"; break;
      case LEFTP: return "("; break;
      case RIGHTP: return ")"; break;
   }
}
