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
   if(s == "begin" || "end" || "const" || "array" || "integer" || "Boolean"
      || "proc" || "skip" || "read" || "write" || "call" || "if" || "fi"
      || "do" || "fi" || "od" || "false" || "true")
   {
      int hashval;
      int val = Symtable::search(s);
      if (val == -1)
      {
	 hashval = hashfn(s);
	 if (s == "begin")
	 {
	    Token begin(Symbol::begin, hashval, s);
	    htable.insert (htable.begin()+hashval, begin);
	    occupied++;
	 }
	 else if(s == "end")
	 {
	    Token end(Symbol::end, hashval, s);
	    htable.insert (htable.begin()+hashval, end);
	    occupied++;
	 }
	 else if(s == "const")
	 {
	    Token const1(Symbol::const1, hashval, s);
	    htable.insert (htable.begin()+hashval, const1);
	    occupied++;
	 }
	 else if(s == "const")
	 {
	    Token array(Symbol::array, hashval, s);
	    htable.insert (htable.begin()+hashval, array);
	    occupied++;
	 }
	 else if(s == "integer")
	 {
	    Token integer(Symbol::integer, hashval, s);
	    htable.insert (htable.begin()+hashval, integer);
	    occupied++;
	 }
	 else if(s == "Boolean")
	 {
	    Token Boolean(Symbol::Boolean, hashval, s);
	    htable.insert (htable.begin()+hashval, Boolean);
	    occupied++;
	 }
	 else if(s == "proc")
	 {
	    Token proc(Symbol::proc, hashval, s);
	    htable.insert (htable.begin()+hashval, proc);
	    occupied++;
	 }
	 else if(s == "skip")
	 {
	    Token skip(Symbol::skip, hashval, s);
	    htable.insert (htable.begin()+hashval, skip);
	    occupied++;
	 }
	 else if(s == "read")
	 {
	    Token read(Symbol::read, hashval, s);
	    htable.insert (htable.begin()+hashval, read);
	    occupied++;
	 }
	 else if(s == "write")
	 {
	    Token write(Symbol::write, hashval, s);
	    htable.insert (htable.begin()+hashval, write);
	    occupied++;
	 }
	 else if(s == "call")
	 {
	    Token call(Symbol::call, hashval, s);
	    htable.insert (htable.begin()+hashval, call);
	    occupied++;
	 }
	 else if(s == "if")
	 {
	    Token if1(Symbol::if1, hashval, s);
	    htable.insert (htable.begin()+hashval, if1);
	    occupied++;
	 }
	 else if(s == "do")
	 {
	    Token do1(Symbol::do1, hashval, s);
	    htable.insert (htable.begin()+hashval, do1);
	    occupied++;
	 }
	 else if(s == "fi")
	 {
	    Token fi(Symbol::fi, hashval, s);
	    htable.insert (htable.begin()+hashval, fi);
	    occupied++;
	 }
	 else if(s == "od")
	 {
	    Token od(Symbol::od, hashval, s);
	    htable.insert (htable.begin()+hashval, od);
	    occupied++;
	 }
	 else if(s == "false")
	 {
	    Token false1(Symbol::false1, hashval, s);
	    htable.insert (htable.begin()+hashval, false1);
	    occupied++;
	 }
	 else if(s == "true")
	 {
	    Token true1(Symbol::true1, hashval, s);
	    htable.insert (htable.begin()+hashval, true1);
	    occupied++;
	 }
	 return hashval;
      }
      else
      {}
   }
   else
   {
      cout << "shouldn't be here... " << endl;
      //---------------------------need to do-------------------
      //hashfn(s);
      //occupied++;
   }
}

int Symtable::search(string s)
{
   Token a;
   string comp;
   cout << "in Search, occupied is: " << occupied << endl;
   //this for loop doesn't work properly....
   for (std::size_t i = 0; i <= occupied; ++i)
   {
      a = htable[i];
      comp = a.getLexeme();
      if (comp == s)
      {
	 cout << "i is: " << i << endl;
	 return i+1;
      }
      else
      {
	 return -1;
      }
   }
}

void Symtable::printTable()
{
   auto iter = htable.begin();
   for ( ; iter < htable.begin()+occupied; iter++)
   {
      Token a = *iter;
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
