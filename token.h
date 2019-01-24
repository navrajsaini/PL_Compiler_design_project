#ifndef TOKEN_H
#define TOKEN_H

/*
  BY: Navraj Saini & Jordan Kolody

  has attributes  (i.e.   data  members)
  of  type Symbol (sname) and type attvalue (sval).
  
  The Token class has member functions
  for getting and setting the data members
  as well as other members as needed.
  
  token.h for token.cpp
*/

#include <iostream>
#include <string>
#include "symbol.h"

using namespace std;

string spellS(Symbol);//prototype to spell the corresponding tokens

class Token
{
  public:
   //default constructor
   Token():sname(NONAME),svalue(attval(-1, "")){}

//constructor
   Token (Symbol s, int v, string l) : sname(s), svalue(attval(v, l)) {}

   //Destructor
   ~Token(){}

//get the terminal symbol
   Symbol getSymbol()const {return sname;}
   
//get the attribute values
   int getValue()const {return svalue.value;}
   string getLexeme()const {return svalue.lexeme;}

//print function
   void insert (ostream &os)
   {
      os << "Token: " << spellS(sname) << endl
	 << "\tAttributes: " << endl
	 << "\t\tLexeme: " << getLexeme() << endl
	 << "\t\tValue: " << getValue() << endl;
   }
  private:
   struct attval
   {
      int value;
      string lexeme;
      attval (int i, string s) :value(i),lexeme(s){}
   };
   attval svalue;
   Symbol sname;

};
//overload operator
ostream& operator<< (ostream&, Token&);

#endif
