/*
  By: Navraj Saini && Jordan Kolody
  symboltable.h implemenations
*/

#include "symboltable.h"

using namespace std;

void loadResvd()
{
   for (int i = 273; i < 289; i++)
   {
      insert(Symbol[i]);
   }
}


int insert(string s)
{
   if (search (s) != -1)
   {
      switch s
      {
	 case "begin": Token begin(begin, )
   }
}
