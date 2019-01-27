/*
  By: Navraj Saini && Jordan Kolody
  symboltable.h implemenations
*/
#include <iostream>
#include "symboltable.h"

using namespace std;

void Symtable::loadResvd()
{
   int val;
   insert("begin");
   insert("end");
   insert("const");
   insert("array");
   insert("integer");
   insert("Boolean");
   insert("proc");
   insert("skip");
   insert("read");
   insert("write");
   insert("call");
   insert("if");
   insert("do");
   insert("fi");
   insert("od");
   insert("false");
   insert("true");
}


int Symtable::insert(string s)
{
   int hashval;
   int val = Symtable::search(s);
   if (val == -1 && Symtable::full() != true)
   {
      hashval = hashfn(s);
      if (s == "begin")
      {
	 Token begin(Symbol::begin, hashval, s);
	 htable.insert (htable.begin()+hashval, begin);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "end")
      {
	 Token end(Symbol::end, hashval, s);
	 htable.insert (htable.begin()+hashval, end);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "const")
      {
	 Token const1(Symbol::const1, hashval, s);
	 htable.insert (htable.begin()+hashval, const1);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "array")
      {
	 Token array(Symbol::array, hashval, s);
	 htable.insert (htable.begin()+hashval, array);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "integer")
      {
	 Token integer(Symbol::integer, hashval, s);
	 htable.insert (htable.begin()+hashval, integer);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "Boolean")
      {
	 Token Boolean(Symbol::Boolean, hashval, s);
	 htable.insert (htable.begin()+hashval, Boolean);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "proc")
      {
	 Token proc(Symbol::proc, hashval, s);
	 htable.insert (htable.begin()+hashval, proc);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "skip")
      {
	 Token skip(Symbol::skip, hashval, s);
	 htable.insert (htable.begin()+hashval, skip);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "read")
      {
	 Token read(Symbol::read, hashval, s);
	 htable.insert (htable.begin()+hashval, read);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "write")
      {
	 Token write(Symbol::write, hashval, s);
	 htable.insert (htable.begin()+hashval, write);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "call")
      {
	 Token call(Symbol::call, hashval, s);
	 htable.insert (htable.begin()+hashval, call);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "if")
      {
	 Token if1(Symbol::if1, hashval, s);
	 htable.insert (htable.begin()+hashval, if1);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "do")
      {
	 Token do1(Symbol::do1, hashval, s);
	 htable.insert (htable.begin()+hashval, do1);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "fi")
      {
	 Token fi(Symbol::fi, hashval, s);
	 htable.insert (htable.begin()+hashval, fi);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "od")
      {
	 Token od(Symbol::od, hashval, s);
	 htable.insert (htable.begin()+hashval, od);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "false")
      {
	 Token false1(Symbol::false1, hashval, s);
	 htable.insert (htable.begin()+hashval, false1);
	 occupied++;
	 return hashval+1;
      }
      else if(s == "true")
      {
	 Token true1(Symbol::true1, hashval, s);
	 htable.insert (htable.begin()+hashval, true1);
	 occupied++;
	 return hashval+1;
      }
      else//if the reserved word is already in the table...
      {
	 val = search(s);
	 hashval = hashfn(s);
	 if (val == -1)//if the id isn't in the symbol table already
	 {
	    Token ID (Symbol::ID, hashval, s);
	    htable.insert (htable.begin()+hashval, ID);
	 occupied++;
	 return hashval;
	 }
      }
   }
   else//if it already exists
   {
      val = Symtable::search(s);
      return val;
   }

}

int Symtable::search(string s)
{
   Token a;
   string comp;
   for (std::size_t i = 0; i <= occupied; i++)
   {
      a = htable[i];
      comp = a.getLexeme();
      if (comp == s)
      {
	 return i+1;
      }
   }
   return -1;
}

void Symtable::printTable()
{
   Token a;
   for (std::size_t i = 0; i < occupied; i++)
   {
      a = htable[i];
      a.insert(cout);
   }
}

int Symtable::hashfn(string s)
{
   //it's the int value for string->>
   //return s % SYMTABLESIZE
   int i = SYMTABLESIZE-occupied;
   i = SYMTABLESIZE-i;
   return i % SYMTABLESIZE;
}
