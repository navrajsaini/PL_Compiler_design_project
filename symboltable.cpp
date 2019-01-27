/*
  By: Navraj Saini && Jordan Kolody
  symboltable.h implemenations
*/
#include <iostream>
#include "symboltable.h"

using namespace std;
/*
  load the reserve words via the insert function to the symbol table
 */
void Symtable::loadResvd()
{
   
   string ins[39] =
      {"begin", "end", "const", "array", "integer",
       "Boolean", "proc", "skip", "read", "write", "call",
       "if", "do", "fi", "od", "false", "true", ".",
       ",", "[", "]", "&", "|", "~", ">", "<", "=", "[]", "->",
       "(", ")", "/", "%", "*", ":=", "+", "-", ";", ":"
      };
   int val;
   for (int i = 0; i < sizeof(ins)/sizeof(ins[0]); i++)
   {
      insert(ins[i]);
      
   }
}
/*
  insert the words that are sent via the scanner
 */
int Symtable::insert(string s)
{
   int hashval;
   int val = Symtable::search(s);//check if the word is in the table already
   //if not and the table is not full insert it based on if the word is a
   //keyword or special char or a user input ID
   if (val == -1 && Symtable::full() != true)
   {
      hashval = hashfn(s);
      //if and else if statements to create the token for the
      //keywords or the special chars which are then inserted.
      if (s == "begin")
      {
	 Token begin(Symbol::begin, hashval, s);
	 htable.insert (htable.begin()+hashval, begin);
	 occupied++;
	 return hashval;
      }
      else if(s == "end")
      {
	 Token end(Symbol::end, hashval, s);
	 htable.insert (htable.begin()+hashval, end);
	 occupied++;
	 return hashval;
      }
      else if(s == "const")
      {
	 Token const1(Symbol::const1, hashval, s);
	 htable.insert (htable.begin()+hashval, const1);
	 occupied++;
	 return hashval;
      }
      else if(s == "array")
      {
	 Token array(Symbol::array, hashval, s);
	 htable.insert (htable.begin()+hashval, array);
	 occupied++;
	 return hashval;
      }
      else if(s == "integer")
      {
	 Token integer(Symbol::integer, hashval, s);
	 htable.insert (htable.begin()+hashval, integer);
	 occupied++;
	 return hashval;
      }
      else if(s == "Boolean")
      {
	 Token Boolean(Symbol::Boolean, hashval, s);
	 htable.insert (htable.begin()+hashval, Boolean);
	 occupied++;
	 return hashval;
      }
      else if(s == "proc")
      {
	 Token proc(Symbol::proc, hashval, s);
	 htable.insert (htable.begin()+hashval, proc);
	 occupied++;
	 return hashval;
      }
      else if(s == "skip")
      {
	 Token skip(Symbol::skip, hashval, s);
	 htable.insert (htable.begin()+hashval, skip);
	 occupied++;
	 return hashval;
      }
      else if(s == "read")
      {
	 Token read(Symbol::read, hashval, s);
	 htable.insert (htable.begin()+hashval, read);
	 occupied++;
	 return hashval;
      }
      else if(s == "write")
      {
	 Token write(Symbol::write, hashval, s);
	 htable.insert (htable.begin()+hashval, write);
	 occupied++;
	 return hashval;
      }
      else if(s == "call")
      {
	 Token call(Symbol::call, hashval, s);
	 htable.insert (htable.begin()+hashval, call);
	 occupied++;
	 return hashval;
      }
      else if(s == "if")
      {
	 Token if1(Symbol::if1, hashval, s);
	 htable.insert (htable.begin()+hashval, if1);
	 occupied++;
	 return hashval;
      }
      else if(s == "do")
      {
	 Token do1(Symbol::do1, hashval, s);
	 htable.insert (htable.begin()+hashval, do1);
	 occupied++;
	 return hashval;
      }
      else if(s == "fi")
      {
	 Token fi(Symbol::fi, hashval, s);
	 htable.insert (htable.begin()+hashval, fi);
	 occupied++;
	 return hashval;
      }
      else if(s == "od")
      {
	 Token od(Symbol::od, hashval, s);
	 htable.insert (htable.begin()+hashval, od);
	 occupied++;
	 return hashval;
      }
      else if(s == "false")
      {
	 Token false1(Symbol::false1, hashval, s);
	 htable.insert (htable.begin()+hashval, false1);
	 occupied++;
	 return hashval;
      }
      else if(s == "true")
      {
	 Token true1(Symbol::true1, hashval, s);
	 htable.insert (htable.begin()+hashval, true1);
	 occupied++;
	 return hashval;
      }
      else if(s == ",")
      {
	 Token comma(Symbol::comma, hashval, s);
	 htable.insert (htable.begin()+hashval, comma);
	 occupied++;
	 return hashval;
      }
      else if(s == ".")
      {
	 Token period(Symbol::period, hashval, s);
	 htable.insert (htable.begin()+hashval, period);
	 occupied++;
	 return hashval;
      }
      else if(s == "[")
      {
	 Token rightB(Symbol::rightB, hashval, s);
	 htable.insert (htable.begin()+hashval, rightB);
	 occupied++;
	 return hashval;
      }
      else if(s == "]")
      {
	 Token leftB(Symbol::leftB, hashval, s);
	 htable.insert (htable.begin()+hashval, leftB);
	 occupied++;
	 return hashval;
      }
      else if(s == "&")
      {
	 Token and1(Symbol::and1, hashval, s);
	 htable.insert (htable.begin()+hashval, and1);
	 occupied++;
	 return hashval;
      }
      else if(s == "|")
      {
	 Token or1(Symbol::or1, hashval, s);
	 htable.insert (htable.begin()+hashval, or1);
	 occupied++;
	 return hashval;
      }
      else if(s == "~")
      {
	 Token not1(Symbol::not1, hashval, s);
	 htable.insert (htable.begin()+hashval, not1);
	 occupied++;
	 return hashval;
      }
      else if(s == "<")
      {
	 Token less(Symbol::less, hashval, s);
	 htable.insert (htable.begin()+hashval, less);
	 occupied++;
	 return hashval;
      }
      else if(s == ">")
      {
	 Token greater(Symbol::greater, hashval, s);
	 htable.insert (htable.begin()+hashval, greater);
	 occupied++;
	 return hashval;
      }
      else if(s == "=")
      {
	 Token equal(Symbol::equal, hashval, s);
	 htable.insert (htable.begin()+hashval, equal);
	 occupied++;
	 return hashval;
      }
      else if(s == "[]")
      {
	 Token closedS(Symbol::closedS, hashval, s);
	 htable.insert (htable.begin()+hashval, closedS);
	 occupied++;
	 return hashval;
      }
      else if(s == ":=")
      {
	 Token assign(Symbol::assign, hashval, s);
	 htable.insert (htable.begin()+hashval, assign);
	 occupied++;
	 return hashval;
      }
      else if(s == ":")
      {
	 Token colon(Symbol::colon, hashval, s);
	 htable.insert (htable.begin()+hashval, colon);
	 occupied++;
	 return hashval;
      }
      else if(s == ";")
      {
	 Token semicolon(Symbol::SEMICOLON, hashval, s);
	 htable.insert (htable.begin()+hashval, semicolon);
	 occupied++;
	 return hashval;
      }
      else if(s == "/")
      {
	 Token div(Symbol::DIV, hashval, s);
	 htable.insert (htable.begin()+hashval, div);
	 occupied++;
	 return hashval;
      }
      else if(s == "%")
      {
	 Token mod(Symbol::MOD, hashval, s);
	 htable.insert (htable.begin()+hashval, mod);
	 occupied++;
	 return hashval;
      }
      else if(s == "+")
      {
	 Token plus(Symbol::PLUS, hashval, s);
	 htable.insert (htable.begin()+hashval, plus);
	 occupied++;
	 return hashval;
      }
      else if(s == "-")
      {
	 Token minus(Symbol::MINUS, hashval, s);
	 htable.insert (htable.begin()+hashval, minus);
	 occupied++;
	 return hashval;
      }
      else if(s == "*")
      {
	 Token times(Symbol::TIMES, hashval, s);
	 htable.insert (htable.begin()+hashval, times);
	 occupied++;
	 return hashval;
      }
      else if(s == "->")
      {
	 Token arrow(Symbol::arrow, hashval, s);
	 htable.insert (htable.begin()+hashval, arrow);
	 occupied++;
	 return hashval;
      }
      else if(s == "(")
      {
	 Token leftP(Symbol::LEFTP, hashval, s);
	 htable.insert (htable.begin()+hashval, leftP);
	 occupied++;
	 return hashval;
      }
      else if(s == ")")
      {
	 Token rightP(Symbol::RIGHTP, hashval, s);
	 htable.insert (htable.begin()+hashval, rightP);
	 occupied++;
	 return hashval;
      }
      else//if the reserved word isn't already in the table...
	 //create a token for it and insert it in
      {
	 val = search(s);
	 hashval = hashfn(s);
	 if (val == -1)//if the id isn't in the symbol table already
	 {
	    Token ID (Symbol::ID, hashval, s);
	    htable.insert (htable.begin()+hashval, ID);
	    occupied++;
	    return hashval+1;
	 }
      }
   }
   else//if it already exists return the location
   {
      val = Symtable::search(s);
      return val;
   }

}
/*
  search function to make sure the word isn't already in the symbol table
 */
int Symtable::search(string s)
{
   Token a;
   string comp;
   for (std::size_t i = 0; i <= occupied; i++)//check all the loctions that are
                                              //occupied
   {
      a = htable[i];
      comp = a.getLexeme();
      if (comp == s)
      {
	 return i+1;//if found return it's location
      }
   }
   return -1;//return -1 if not found
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
//hash function. for now it's just a mod function
//will edit it later for a more appropriate
//hash func
{
   int i = SYMTABLESIZE-occupied;
   i = SYMTABLESIZE-i;
   return i % SYMTABLESIZE;
}
