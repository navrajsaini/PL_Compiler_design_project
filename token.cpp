/*
  member functions for getting and setting the data members
  as well as other members as needed.
  token.cpp
*/
#include "token.h"
#include <iostream>

using namespace std;
/*
  spell the symbol passed based on switch cases
 */
string spellS(Symbol s)
{
   switch (s)
   {
      case NUM: return "Number"; break;
      case DIV: return "div"; break;
      case MOD: return "mod"; break;
      case SEMICOLON: return "semicolon"; break;
      case PLUS: return "plus"; break;
      case MINUS: return "minus"; break;
      case TIMES: return "times"; break;
      case DIVIDE: return "div"; break;
      case LEFTP: return "leftP"; break;
      case RIGHTP: return "rightP"; break;

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
	 
      case Symbol::colon: return "colon"; break;
      case Symbol::period: return "period"; break;
      case Symbol::comma: return "comma"; break;
      case Symbol::rightB: return "["; break;
      case Symbol::leftB: return "]"; break;
      case Symbol::and1: return "and"; break;
      case Symbol::or1: return "or"; break;
      case Symbol::not1: return "not"; break;
      case Symbol::greater: return "greater"; break;
      case Symbol::less: return "less"; break;
      case Symbol::equal: return "equal"; break;
      case closedS: return "[]"; break;
      case assign: return "assign"; break;
      case arrow: return "arrow"; break;
	 //need to have it go from symbol to string...
      default: return "ID"; break;
   }
}

//it prints the different parts of the token that is passed by cout << a;
ostream& operator<< (ostream &os, Token& a)
{
   os << "Token: " << spellS(a.getSymbol()) << endl
      << "\tAttributes: " << endl
      << "\t\tLexeme: " << a.getLexeme() << endl
      << "\t\tValue: " << a.getValue()+1 << endl;
}
