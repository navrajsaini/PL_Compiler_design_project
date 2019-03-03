/*
  parcer.cpp implementation file
  by Navraj Saini and Jordan Kolody
*/
#include <iostream>
#include <fstream>
#include <string>
#include <parser.h>
using namespace std;

Parse::Parse(string in)
{
   file=in;
   tokeNum=0
}

void Parse::parseFile()  
{
   
   input.open(file.c_str());
   input>>LHS;
   parseNow
   input.close()
}
void Parse::parseNow()
{
   Program();
}



void Parse::match()
{  
   input>>LHS;
   tokeNum++;
}

void Parse::errorReport()
{
   cout<<endl<<"There was an error on Line Number: "<<lineToke[tokeNum][0]<<" and token: "<<lineToke[tokeNum][1]<<endl; 
}

//This is the start of the PL Grammar Parsing Stage.
void Parse::Program()
{
   Block();
   if(LHS==".")
   {
      cout<<endl<<"YOU SUCCESSFULY PARSED, CONGRATS!!!!"<<endl;
   }else
   {
      errorReport();
   }
   
}

void Parse::Block()
{
   if(LHS=="begin")
   {
      match();
      
      if(LHS=="end")
      {

      }    
   }
}
