/*
  part one, scanner.cpp
 */
#include "scanner.h"
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

//scanner constructor, it load reserve word and stores the name of the files
Scanner::Scanner(string inCodeName, string outCodeName)//, Symtable &symbolTable)
{
   setName(inCodeName, outCodeName);
   symbolTable.loadResvd();
   LN=1;
   TN=1;
   while(TN<255)
   {
      lineToke[TN][0];
      lineToke[TN][1];
      lineToke[TN][2];
      TN++;
   }
   TN=1;
	 
}

//this function determines if the caracter is white space, if it is it returns true
bool Scanner::isSpace(char a)
{
   if(a==' ')
   {
      return true;
   }
   return false;
}

//this sets the names in scanner
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
   return false;
}
//returns true if character is a numeric value
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
      case 92:// backslash is reserved so its being compared to casted ascii value
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
//test line
void Scanner::inc(int SV)
{
lineToke[TN][1] = SV;
lineToke[TN][0] = LN;
lineToke[TN][2] = 0;
//cout<<TN
TN++;

}
//called to get the token value then returned to be storred in file
int Scanner::getToken(string token)
{
   int storeVal;
   
   storeVal = symbolTable.insert(token);

   inc(storeVal);

   
   return storeVal;
}
//new function to fix id number problem
int Scanner::getNum(string token)
{
   int storeVal;
   storeVal = symbolTable.insertNum(token);
   inc(storeVal);
   return storeVal;
   
}

/*TOKENLINE BLOCK 0
  tokenline will go through the line as a forloop,
  and then detrimin what the char is
  once it is determined it then makes a sring and then sends it to get token to
  retrieve the token value to be stored.
  if the char it is white space, it skips it, if it is a comment it skips the
  line by returning true.
--TOKENLINE BLOCK 1
  if it determines an alpha it will begin creating a string
  this string can have numbers after the first alpha character.
  once it has gone through to the end of the word it will pass it to
  get token, recieves the correct token value and stores it
--TOKENLINE BLOCK 2
  this goes through numeric in the same way.
--TOKENLINE BLOCK 3
  This goes throught the special in the same manner.
  By calling isSpecial, it sends the different specials, of which are returned
  as the, then stored token value for reference.
  it also deals with any of the special multi character special symbols
--TOKENLINE BLOCK 4
  Created a case for if token was equal to nothing
  function will finnish by seeing if the character is unidentified and throw an
  error if so. then it will close the file after the forloop is exhausted.
*/
void Scanner::tokenLine(char now[], int y)
{
   out.open(tokenFileName.c_str(), ios::app);
   string token;
   int prnt, i, b=0;
   //TOKENLINE BLOCK 0
   for(i=0; i<=255; i++)
   {
      ahead=now[i+1];      
      if(isComment(now[i])==true)
      {
	 out.close();
	 return;
      }
      //wiping token for next iteration
      token="";
      while(isSpace(now[i])==true)
      {
	 i++;
	 ahead=now[i+1];
      }
      //TOKENLINE BLOCK 1
      if(isAlpha(now[i])==true)
      {
	 while(isAlpha(now[i])==true)
	 {
	    token.push_back(now[i]);
	    i++;
	    ahead=now[i+1];
	    //just incase there is a numeral inside the word
	    while(isNumeric(now[i])==true)
	    {
	       token.push_back(now[i]);
	       i++;
	       ahead=now[i+1];
	    }	    
	 }
	 //call to store token and move to next token, in this case an alpha
	 prnt = getToken(token);
	 out<<prnt<<" ";
	 i--;
	 ahead=now[i+1];
      }
      //TOKENLINE BLOCK 2
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
	 //call to store token and move to next token, in this case a numeric
	 prnt = getNum(token);
	 //minus 1 becasue it was incrimnted inside getnum
	 lineToke[TN-1][2] = numericVAl(token);
	 out<<prnt<<" ";
	 i--;
	 ahead=now[i+1];
      }
      //TOKENLINE BLOCK 3
      else if(isSpecial(now[i])==true)
      {
	 token.push_back(now[i]);
	 if(now[i]==':'&&ahead=='=')
	 {
	    token.push_back(ahead);
	    i++;
	    ahead=now[i+1];	    
	 }
	 else if(now[i]=='-'&&ahead=='>')
	 {
	    token.push_back(ahead);
	    i++;
	    ahead=now[i+1];	    
	 }
	 else if(now[i]=='['&&ahead==']')
	 {
	    token.push_back(ahead);
	    i++;
	    ahead=now[i+1];
	    
	 }else
	 {
	 }
	 if(now[i]==92)
	 {
	    prnt = getToken("%");
	    out<<prnt<<" ";
	 }
	 else
	 {
	    //call to store token and move to next token, in this case an alpha
	    prnt = getToken(token);
	    out<<prnt<<" ";
	 }
      }
      //TOKENLINE BLOCK 4
      else if(token=="")
      {
	 //the case of if token is empty is the same as if now[i] is empty
	 //since token has not been initialised to anything from before.
      }
      else
      {	 
	 cout<<endl<<token<<" is a not identified token on line: "<<LN;
	 cout<<endl;
      }
      
   }
   out.close();
}

//is comment check if the char is $ then returns true to skip the comment line
bool Scanner::isComment(char a)
{
   if( a=='$')
      return true;
   return false;
}
int Scanner::numericVAl(string s)
{
   //cout<<s<<", "<<s.size()<<endl;
   int sSize = s.size()-1;
   int total = 0;
   int inc = 0;
   for(int i = sSize; 0 <= i; i--)
   {
      //cout<<inc<<", "<<sSize;
      char a = s[i];
      switch(a)
      {
	 case '1':
	    total = total + (1 * pow(10, inc));
	    break;
	 case '2':
	    total = total + (2 * pow(10, inc));
	    break;
	 case '3':
	    total = total + (3 * pow(10, inc));
	    break;	    
	 case '4':
	    total = total + (4 * pow(10, inc));
	    break;			 
	 case '5':
	    total = total + (5 * pow(10, inc));
	    break;	    
	 case '6':
	    total = total + (6 * pow(10, inc));
	    break;			 
	 case '7':
	    total = total + (7 * pow(10, inc));
	    break;	    
	 case '8':
	    total = total + (8 * pow(10, inc));
	    break;	    
	 case '9':
	    total = total + (9 * pow(10, inc));
	    break;	    
	 case '0':
	    total=total;	    
	 default:
	    break;
      }
      //cout<<", "<<total<<endl; 
      inc++;
   }
   //cout<<total<<endl;
   return total;  
}
