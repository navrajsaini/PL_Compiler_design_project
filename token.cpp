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
   switch (s)
   {
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

	 //the error handling and reporting symbols
      case BADNUM: return "Bad Number error"; break;
      case BADNAME: return "Bad Name error"; break;
      case NEWLINE: return "New Line error"; break;
      case NONAME: return "No Name error"; break;
      case ENDOFFILE: return "End of File"; break;
      case BADCHAR: return "Bad Character error"; break;
   }
}

//it prints the different parts of the token that is passed by cout << a;
ostream& operator<< (ostream &os, Token& a)
{
   os << "Token: " << spellS(a.getSymbol()) << endl
      << "\tAttributes: " << endl
      << "\t\tLexeme: " << a.getLexeme() << endl
      << "\t\tValue: " << a.getValue() << endl;
}
