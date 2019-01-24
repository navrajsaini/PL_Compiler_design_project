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
   if(s == "begin")
   {
      Token begin(Symbol::begin, 273, s);
      //------------------------------------test--------
      begin.insert(cout);
      //------------------------------------endtest-----
      htable.push_back(begin);
      occupied++;
   }
   else if(s == "end")
   {
      Token end(Symbol::end, 274, s);
      htable.push_back(end);
      occupied++;
   }
   else if(s == "const")
   {
      Token const1(Symbol::const1, 275, s);
      htable.push_back(const1);
      occupied++;
   }
   else if(s == "const")
   {
      Token array(Symbol::array, 276, s);
      htable.push_back(array);
      occupied++;
   }
   else if(s == "integer")
   {
      Token integer(Symbol::integer, 277, s);
      htable.push_back(integer);
      occupied++;
   }
   else if(s == "Boolean")
   {
      Token Boolean(Symbol::Boolean, 278, s);
      htable.push_back(Boolean);
      occupied++;
   }
   else if(s == "proc")
   {
      Token proc(Symbol::proc, 279, s);
      htable.push_back(proc);
      occupied++;
   }
   else if(s == "skip")
   {
      Token skip(Symbol::skip, 280, s);
      htable.push_back(skip);
      occupied++;
   }
   else
   {
      //---------------------------need to do-------------------
   }
}

int Symtable::search(string s)
{
   for (std::vector<int>::size_type i = 0; i != occupied; i++)
   {
      cout << "i is: " << i << "." << endl;
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
