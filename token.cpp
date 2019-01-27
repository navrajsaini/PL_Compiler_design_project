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
	 //The reserved words
      case Symbol::begin: return "begin"; break;
      case Symbol::end: return "end"; break;
      case const1: return "const"; break;
      case array: return "array"; break;
      case integer: return "integer"; break;
      case Boolean: return "Boolean"; break;
      case proc: return "proc"; break;
      case skip: return "skip"; break;
      case read: return "read"; break;
      case write: return "write"; break;
      case call: return "call"; break; 
      case if1: return "if"; break; 
      case do1: return "do"; break;
      case fi: return "fi"; break;
      case od: return "od"; break;
      case false1: return "false"; break;
      case true1: return "true"; break;
      default: return s; break;
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
