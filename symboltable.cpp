/*
  By: Navraj Saini && Jordan Kolody
  symboltable.h implemenations
*/
#include <iostream>
#include "symboltable.h"
#include <cmath>
#include <cstring>
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
      val = insert(ins[i]);
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
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token begin(Symbol::begin, hashval, s);
	    htable.insert (htable.begin()+hashval, begin);
	    occupied++;
	    return hashval;
	 }
	 else//increment the hashval and insert the token into a free loc
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	       //keep looking for a free location
	    {
	       hashval += 1;
	    }
	    Token begin(Symbol::begin, hashval, s);
	    htable.insert (htable.begin()+hashval, begin);
	    occupied++;
	    return hashval;
	 }
      }
      
      else if(s == "end")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token end(Symbol::end, hashval, s);
	    htable.insert (htable.begin()+hashval, end);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	       //keep looking for a free location
	    {
	       hashval += 1;
	    }
	    Token end(Symbol::end, hashval, s);
	    htable.insert (htable.begin()+hashval, end);
	 }
	    occupied++;
	    return hashval;
      }
      
      else if(s == "const")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token const1(Symbol::const1, hashval, s);
	    htable.insert (htable.begin()+hashval, const1);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	       //keep looking for a free location
	    {
	       hashval += 1;
	    }
	    Token const1(Symbol::const1, hashval, s);
	    htable.insert (htable.begin()+hashval, const1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "array")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token array(Symbol::array, hashval, s);
	    htable.insert (htable.begin()+hashval, array);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token array(Symbol::array, hashval, s);
	    htable.insert (htable.begin()+hashval, array);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "integer")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token integer(Symbol::integer, hashval, s);
	    htable.insert (htable.begin()+hashval, integer);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token integer(Symbol::integer, hashval, s);
	    htable.insert (htable.begin()+hashval, integer);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "Boolean")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token Boolean(Symbol::Boolean, hashval, s);
	    htable.insert (htable.begin()+hashval, Boolean);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token Boolean(Symbol::Boolean, hashval, s);
	    htable.insert (htable.begin()+hashval, Boolean);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "proc")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token proc(Symbol::proc, hashval, s);
	    htable.insert (htable.begin()+hashval, proc);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token proc(Symbol::proc, hashval, s);
	    htable.insert (htable.begin()+hashval, proc);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "skip")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token skip(Symbol::skip, hashval, s);
	    htable.insert (htable.begin()+hashval, skip);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token skip(Symbol::skip, hashval, s);
	    htable.insert (htable.begin()+hashval, skip);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "read")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token read(Symbol::read, hashval, s);
	    htable.insert (htable.begin()+hashval, read);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token read(Symbol::read, hashval, s);
	    htable.insert (htable.begin()+hashval, read);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "write")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token write(Symbol::write, hashval, s);
	    htable.insert (htable.begin()+hashval, write);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token write(Symbol::write, hashval, s);
	    htable.insert (htable.begin()+hashval, write);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "call")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token call(Symbol::call, hashval, s);
	    htable.insert (htable.begin()+hashval, call);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token call(Symbol::call, hashval, s);
	    htable.insert (htable.begin()+hashval, call);
	 }
	 occupied++;
	 return hashval;
      }
      else if(s == "if")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token if1(Symbol::if1, hashval, s);
	    htable.insert (htable.begin()+hashval, if1);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token if1(Symbol::if1, hashval, s);
	    htable.insert (htable.begin()+hashval, if1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "do")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
	 {
	    Token do1(Symbol::do1, hashval, s);
	    htable.insert (htable.begin()+hashval, do1);
	 }
	 else
	 {
	    while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval +=1;
	    }
	    Token do1(Symbol::do1, hashval, s);
	    htable.insert (htable.begin()+hashval, do1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "fi")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token fi(Symbol::fi, hashval, s);
	    htable.insert (htable.begin()+hashval, fi);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;	       
	    }
	    Token fi(Symbol::fi, hashval, s);
	    htable.insert (htable.begin()+hashval, fi);
	 }
	 occupied++;
	 return hashval;
	 
      }
      
      else if(s == "od")
      {
	 
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token od(Symbol::od, hashval, s);
	    htable.insert (htable.begin()+hashval, od);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token od(Symbol::od, hashval, s);
	    htable.insert(htable.begin()+hashval, od);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "false")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token false1(Symbol::false1, hashval, s);
	    htable.insert (htable.begin()+hashval, false1);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token false1(Symbol::false1, hashval, s);
	    htable.insert (htable.begin()+hashval, false1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "true")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token true1(Symbol::true1, hashval, s);
	    htable.insert (htable.begin()+hashval, true1);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token true1(Symbol::true1, hashval, s);
	    htable.insert (htable.begin()+hashval, true1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == ",")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token comma(Symbol::comma, hashval, s);
	    htable.insert (htable.begin()+hashval, comma);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token comma(Symbol::comma, hashval, s);
	    htable.insert (htable.begin()+hashval, comma);
	 }
	 occupied++;
	 return hashval;
      }
      else if(s == ".")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token period(Symbol::period, hashval, s);
	    htable.insert (htable.begin()+hashval, period);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token period(Symbol::period, hashval, s);
	    htable.insert (htable.begin()+hashval, period);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "[")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token rightB(Symbol::rightB, hashval, s);
	    htable.insert (htable.begin()+hashval, rightB);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token rightB(Symbol::rightB, hashval, s);
	    htable.insert (htable.begin()+hashval, rightB);
	 }
	 occupied++;
	 return hashval;
      }

      else if(s == "]")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token leftB(Symbol::leftB, hashval, s);
	    htable.insert (htable.begin()+hashval, leftB);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token leftB(Symbol::leftB, hashval, s);
	    htable.insert (htable.begin()+hashval, leftB);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "&")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token and1(Symbol::and1, hashval, s);
	    htable.insert (htable.begin()+hashval, and1);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token and1(Symbol::and1, hashval, s);
	    htable.insert (htable.begin()+hashval, and1);
	 }
	 occupied++;
	 return hashval;
      }

      else if(s == "|")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token or1(Symbol::or1, hashval, s);
	    htable.insert (htable.begin()+hashval, or1);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token or1(Symbol::or1, hashval, s);
	    htable.insert (htable.begin()+hashval, or1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "~")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token not1(Symbol::not1, hashval, s);
	    htable.insert (htable.begin()+hashval, not1);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token not1(Symbol::not1, hashval, s);
	    htable.insert (htable.begin()+hashval, not1);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "<")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token less(Symbol::less, hashval, s);
	    htable.insert (htable.begin()+hashval, less);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token less(Symbol::less, hashval, s);
	    htable.insert (htable.begin()+hashval, less);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == ">")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token greater(Symbol::greater, hashval, s);
	    htable.insert (htable.begin()+hashval, greater);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token greater(Symbol::greater, hashval, s);
	    htable.insert (htable.begin()+hashval, greater);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "=")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token equal(Symbol::equal, hashval, s);
	    htable.insert (htable.begin()+hashval, equal);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token equal(Symbol::equal, hashval, s);
	    htable.insert (htable.begin()+hashval, equal);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "[]")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token closedS(Symbol::closedS, hashval, s);
	    htable.insert (htable.begin()+hashval, closedS);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token closedS(Symbol::closedS, hashval, s);
	    htable.insert (htable.begin()+hashval, closedS);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == ":=")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token assign(Symbol::assign, hashval, s);
	    htable.insert (htable.begin()+hashval, assign);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token assign(Symbol::assign, hashval, s);
	    htable.insert (htable.begin()+hashval, assign);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == ":")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token colon(Symbol::colon, hashval, s);
	    htable.insert (htable.begin()+hashval, colon);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token colon(Symbol::colon, hashval, s);
	    htable.insert (htable.begin()+hashval, colon);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == ";")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token semicolon(Symbol::SEMICOLON, hashval, s);
	    htable.insert (htable.begin()+hashval, semicolon);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token semicolon(Symbol::SEMICOLON, hashval, s);
	    htable.insert (htable.begin()+hashval, semicolon);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "/")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token div(Symbol::DIV, hashval, s);
	    htable.insert (htable.begin()+hashval, div);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token div(Symbol::DIV, hashval, s);
	    htable.insert (htable.begin()+hashval, div);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "%")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token mod(Symbol::MOD, hashval, s);
	    htable.insert (htable.begin()+hashval, mod);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token mod(Symbol::MOD, hashval, s);
	    htable.insert (htable.begin()+hashval, mod);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "+")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token plus(Symbol::PLUS, hashval, s);
	    htable.insert (htable.begin()+hashval, plus);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token plus(Symbol::PLUS, hashval, s);
	    htable.insert (htable.begin()+hashval, plus);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "-")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token minus(Symbol::MINUS, hashval, s);
	    htable.insert (htable.begin()+hashval, minus);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token minus(Symbol::MINUS, hashval, s);
	    htable.insert (htable.begin()+hashval, minus);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "*")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token times(Symbol::TIMES, hashval, s);
	    htable.insert (htable.begin()+hashval, times);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token times(Symbol::TIMES, hashval, s);
	    htable.insert (htable.begin()+hashval, times);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "->")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token arrow(Symbol::arrow, hashval, s);
	    htable.insert (htable.begin()+hashval, arrow);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token arrow(Symbol::arrow, hashval, s);
	    htable.insert (htable.begin()+hashval, arrow);
	 }
	 occupied++;
	 return hashval;
      }
      
      else if(s == "(")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token leftP(Symbol::LEFTP, hashval, s);
	    htable.insert (htable.begin()+hashval, leftP);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token leftP(Symbol::LEFTP, hashval, s);
	    htable.insert (htable.begin()+hashval, leftP);
	 }
	 occupied++;
	 return hashval;
      }
      else if(s == ")")
      {
	 if (spellS (htable[hashval].getSymbol()) == "NONAME")
	 {
	    Token rightP(Symbol::RIGHTP, hashval, s);
	    htable.insert (htable.begin()+hashval, rightP);
	 }
	 else
	 {
	    while (spellS (htable[hashval].getSymbol()) != "NONAME")
	    {
	       hashval += 1;
	    }
	    Token rightP(Symbol::RIGHTP, hashval, s);
	    htable.insert (htable.begin()+hashval, rightP);
	 }
	 occupied++;
	 return hashval;
      }
      else//if the reserved word isn't already in the table...
	 //create a token for it and insert it in
      {
	 hashval = hashfn(s);
	 if (val == -1)//if the id isn't in the symbol table already
	 {
	    if (spellS (htable[hashval].getSymbol()) == "NONAME")
	    {
	       Token ID (Symbol::ID, hashval, s);
	       htable.insert (htable.begin()+hashval, ID);
	    }
	    else
	    {
	       while (spellS (htable[hashval].getSymbol()) != "NONAME")
	       {
		  hashval += 1;
	       }
	       Token ID (Symbol::ID, hashval, s);
	       htable.insert (htable.begin()+hashval, ID);
	    }
	    occupied++;
	    return hashval;
	 }
	 else//return the value of where it is
	 {
	    return val;
	 }
      }
   }
   else//if it already exists return the location
   {
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
   for (/*std::size_t*/int i = 0; i < 307; i++)//check all the loctions that are
      //occupied
   {
      a = htable[i];
      comp = a.getLexeme();
      if ( spellS (a.getSymbol()) != "NONAME")
      {
	 if ( comp == s )
	 {
	    return i;//if found return it's location
	 }
	 else
	    ;
      }
      else
	 ;
   }
   return -1;//return -1 if not found
}
void Symtable::printTable()
{
   Token a;
   for (std::size_t i = 0; i < 307; i++)
   {
      a = htable[i];
      if (spellS (a.getSymbol()) != "NONAME")
      {
	 a.insert(cout);
      }
   }
}

int Symtable::hashfn(string s)
//hash function. for now it's just a mod function
//will edit it later for a more appropriate
//hash func
{
   
   int i = SYMTABLESIZE-occupied;
   i = (SYMTABLESIZE-i) *  311;
   return i % (SYMTABLESIZE-1);
}

int Symtable::insertNum(string s)
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
      if (spellS (htable[hashval].getSymbol()) == "NONAME")//if the location is empty
      {
	 Token NUM(Symbol::NUM, hashval, s);
	 htable.insert (htable.begin()+hashval, NUM);
	 occupied++;
	 return hashval;
      }
      else//increment the hashval and insert the token into a free loc
      {
	 while ( spellS(htable[hashval].getSymbol()) != "NONAME")
	    //keep looking for a free location
	 {
	    hashval += 1;
	 }
	 Token NUM(Symbol::NUM, hashval, s);
	 htable.insert (htable.begin()+hashval, NUM);
	 occupied++;
	 return hashval;
      }
   }
}

//receives a value from admin for the location of the token
//returns the lexeme for the token to be used in the parcer
string Symtable::giveLex(int val)
{
   Symbol a = htable[val].getSymbol();
   return spellS(a);
}
