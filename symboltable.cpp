/*
  By: Navraj Saini && Jordan Kolody
  symboltable.h implemenations
*/
#include <iostream>
#include "symboltable.h"

using namespace std;

void Symtable::loadResvd()
{
   insert("begin");
}


int Symtable::insert(string s)
{
   if(s == "begin" || "end" || "const" || "array" || "integer" || "Boolean"
      || "proc" || "skip" || "read" || "write" || "call" || "if" || "fi"
      || "do" || "fi" || "od" || "false" || "true")
   {
      //Token begin(Symbol::begin, 273, s);
      //------------------------------------test--------
      //begin.insert(cout);
      //------------------------------------endtest-----
      //htable.push_back(begin);
      //call the hash function here....
      if (search(s) == -1)
      {
	 hashfn(s);
	 occupied++;
      }
      else
      {}
   }
   else
   {
      //---------------------------need to do-------------------
      hashfn(s);
      occupied++;
   }
}

int Symtable::search(string s)
{
   for (std::vector<int>::size_type i = 0; i != occupied; i++)
   {
      if (htable[i].getLexeme() == s)
      {
	 return i+1;
      }
      else
	 return -1;
   }
}

void Symtable::printTable()
{
   cout << "occupied is: " << occupied << endl;
   for (std::vector<int>::size_type i = 0; i != occupied; i++)
   {
      htable[i].Token::insert(cout);
   }
}

int Symtable::hashfn(string s)
{
   
}
