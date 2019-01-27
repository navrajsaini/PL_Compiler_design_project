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
   symbolTable.loadResvd();
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
      if(a>=97)
      {
	 if(a<=122)
	 {
	    return true;
	 }
      }
   }
   //cout<<"not alpha: "<<a<<endl;
   return false;
}
//returns true if character is a numeric value via ascii
bool Scanner::isNumeric (char a)
{

   
   switch(a)
   {
      case '1':
	 return true;
      case '2':
	 return true;
      case '3':
	 return true;
      case '4':
	 return true;
      case '5':
	 return true;
      case '6':
	 return true;
      case '7':
	 return true;
      case '8':
	 return true;
      case '9':
	 return true;
      case '0':
	 return true;
      default:
	 return false;
	 //cout<<"not numeric:"<<a<<endl;
   }

   
   
   
}
//returns true if character is special
bool Scanner::isSpecial (char a)
{
   switch(a)
   {
      case '.':
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
  
   storeVal = symbolTable.insert(token);
   return storeVal;
}


void Scanner::tokenLine(char now[], int y)
{
//for self
//Token (Symbol s, int v, string l) : sname(s), svalue(attval(v, l))
   out.open(tokenFileName.c_str(), ios::app);
   string token;
   int a5a, i, b=0;
   
   for(i=0; i<=255; i++)
   {
      ahead=now[i+1];      
      //cout<<now[i]<<" "<<ahead;
      if(isComment(now[i])==true)
      {
	 out.close();
	 return;
      }
      token="";
      while(isSpace(now[i])==true)
      {
	 i++;
      }
      if(isAlpha(now[i])==true)
      {
	 while(isAlpha(now[i])==true)
	 {
	    token.push_back(now[i]);
	    i++;
	    ahead=now[i+1];

	    while(isNumeric(now[i])==true)
	    {
	       token.push_back(now[i]);
	       i++;
	       ahead=now[i+1];
	    }
	    
	 }
	 //call to store token and move to next token, in this case a special
	 a5a = getToken(token);
	 //cout<<a5a<<" ";
	 out<<a5a<<" ";
	 i--;
      }
      else if(isNumeric(now[i])==true)
      {
	 while(isNumeric(now[i])==true)
	 {
	    token.push_back(now[i]);
	    i++;
	    ahead=now[i+1];
	    
	 }
	 if(isAlpha(now[i]==true))
	 {
	    
	    cout<<endl<<spellS(BADNAME)<<" on line:" ;
	    return;
	 }
	 a5a = getToken(token);
	 //cout<<a5a<<" ";
	 out<<a5a<<" ";
	 i--;
      }
      else if(isSpecial(now[i])==true)
      {
	 token.push_back(now[i]);
	 if(now[i]==':'&&ahead=='=')
	 {
	    token.push_back(now[i]);
	    i++;
	 }
	 else if(now[i]=='-'&&ahead=='>')
	 {
	    token.push_back(now[i]);
	    i++;
	    
	    
	 }
	 else if(now[i]=='['&&ahead==']')
	 {
	    token.push_back(now[i]);
	    i++;
	    
	 }
	 
	 a5a = getToken(token);
	 //cout<<a5a<<" ";
	 out<<a5a<<" ";
      }
      else if(token=="")
      {
	 
      }
      else
      {
	 
	 cout<<endl<<b<<token<<"not identified token";
	 //i++;
      }    
   }
   out.close();
}


bool Scanner::isComment(char a)
{
   if( a=='$')
      return true;
   return false;
}
