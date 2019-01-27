/*
  part one, scanner.cpp
 */
#include "scanner.h"
#include <iostream>
#include <fstream>
using namespace std;

//Returns true if character is whitespace

Scanner::Scanner(string inCodeName, string outCodeName)//, Symtable &symbolTable)
{
   codeFileName=inCodeName;
   //infileptr.open(inCodeName.c_str());
   tokenFileName=outCodeName;
}

bool Scanner::isSpace(char a)
{
   if(a==' ')
   {
      return true;
   }
   return false;
}
void Scanner::setName(string in, string ot)
{
   codeFileName = in;
   tokenFileName = ot;

}
//returns true if character is an alphabet, based on ascii value
bool Scanner::isAlpha (char a)
{
   if(a>=65)
   {
      if(a<=90)
      {
	 return true;
      }
      if(a>=91)
      {
	 if(a<=122)
	 {
	    return true;
	 }
      }
   }
   return false;
}
//returns true if character is a numeric value via ascii
bool Scanner::isNumeric (char a)
{
   if(a>=48)
   {
      if(a<=57)
      {
	 return true;
      }
   }
   return false;
   
}
//returns true if character is special
bool Scanner::isSpecial (char a)
{
   switch(a)
   {
      case'.':
	 return true;
      case',':
	 return true;
      case';':
	 return true;
      case'[':
	 return true;
      case']':
	 return true;
      case'&':
	 return true;
      case'|':
	 return true;
      case'~':
	 return true;
      case'<':
	 return true;
      case'=':
	 return true;
      case'>':
	 return true;
      case'+':
	 return true;
      case'-':
	 return true;
      case'*':
	 return true;
      case'/':
	 return true;
      case 92:
	 return true;
      case'(':
	 return true;
      case')':
	 return true;
      case':':
	 return true;
      default:
	 return false;
	 break;
	 
   }
   
}

int Scanner::getToken(string token)
{
   int storeVal;
   //Symtable symbolTable2;
   
   storeVal = symbolTable.insert(token);
   //cout<<storeVal<<endl;
   return storeVal;
}


void Scanner::tokenLine(char now[], int y)
{
//for self
//Token (Symbol s, int v, string l) : sname(s), svalue(attval(v, l))
   out.open(tokenFileName.c_str(), ios::app);
   string token;
   int a5a;
   for(int i=0;i<=255;i++)
   {
      ahead=now[i+1];      
      //cout<<now[i]<<" "<<ahead;
      if(isComment(now[i])==true)
      {
	 out.close();
	 return;
      }
      while(isSpace(now[i])==true)
      {
	 i++;
      }
      //isAlpha(ahead)==true
      if(isAlpha(now[i])==true)
      {
	 while(isAlpha(now[i])==true)
	 {
	    token.push_back(now[i]);
	    i++;
	    while(isNumeric(now[i])==true)
	    {
	       token.push_back(now[i]);
	       i++;
	    }
	    
	 }
	 //call to store token and move to next token, in this case a special
	 a5a = getToken(token);
	 cout<<a5a<<" ";
	 out<<a5a<<" ";
      }
      else if(isNumeric(now[i])==true)
      {
	 while(isNumeric(now[i]==true))
	 {
	    token.push_back(now[i]);
	    i++;
	    
	 }
	 a5a = getToken(token);
      }
      else if(isSpecial(now[i])==true)
      {
	 if(isSpecial(ahead)==true)
	 {
	    
	 }
      }
      
      //cout<<now[i];
      
      






      
      
      
   }
   out.close();
   
}


bool Scanner::isComment(char a)
{
   if( a=='$')
      return true;
   return false;
}
