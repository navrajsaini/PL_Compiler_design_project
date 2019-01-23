/*
  By: Navraj Saini && Jordan Kolody
  symboltable.h implemenations
*/
#include <iostream>
#include "symboltable.h"
#include "symbol.h"
#include "token.h"
using namespace std;

void Symtable::loadResvd()
{
   insert("begin");
}


int Symtable::insert(string s)
{
   if(s == "begin")
   {
      Token beginT(begin, 273, s);
      htable.push_back(beginT);
      occupied++;
   }
	 /*
	   case "end": Token end(end, 274, "end"); htable.insert(end);
	   occupied++; break;
	   case "const": Token const1(const1, 275, "const"); htable.insert(const1);
	   occupied++; break;
	   case "array": Token array(array, 276, "array"); htable.insert(array);
	   occupied++; break;
	   case "integer": Token integer(integer, 277, "integer");
	   htable.insert(integer); occuped++; break;
	   case "Boolean": Token Boolean(Boolean, 278, "Boolean");
	   htable.insert(Boolean); occupied++; break;
	   case "proc": Token proc(proc, 279, "proc"); htable.insert(proc);
	   occupied++; break;
	   case "skip": Token skip(skip, 280, "skip"); htable.insert(skip);
	   occupied++; break;
	 */
}
