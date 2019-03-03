/*
  parcer.cpp implementation file
  by Navraj Saini and Jordan Kolody
*/
#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include "administration.h"
//#include "scanner.h"
//#include "global.cpp"
using namespace std;
Parse::Parse(string in)
{
   file=in;
   tokeNum=0;
   for(int i=1; i<256; i++)
   {
      ln[i][0]=0;
      ln[i][1]=0;
   }
}

void Parse::asn(int sec, int part, int numb)
{
   ln[sec][part]=numb;
   //cout<<"token and line num: "<<numb<<" ";
}
void Parse::parseIt()  
{  
   match();
   parseNow();
   //errorReport();
}
void Parse::tokens(string val)
{
   //cout<<" "<<val<<" ";
   token[tokCount]=val;
   tokCount++;
   
}
void Parse::printToken()
{
   for(int i=0; i<156;i++)
   {
      cout<<"token '"<<i<<"' is '"<<token[i]<<"' ";
   }
}
void Parse::parseNow()
{
   //printToken();
   Program();
   
}
void Parse::match()
{  
   LHS=token[tokeNum];
   tokeNum++;
   cout<<"token '"<<LHS<<"' is token '"<<tokeNum-1<<"'"<<endl;
}

void Parse::errorReport()
{
   cout<<endl<<"There was an error on Line Number: "<<ln[tokeNum][0]<<" and token: "<<ln[tokeNum][1]<<endl; 
}

//This is the start of the PL Grammar Parsing Stage.
void Parse::Program()
{
   Block();
   
   if(LHS==".")
   {
      cout<<endl<<"YOU SUCCESSFULY PARSED, CONGRATS!!!!"<<endl;
   }else
      cout<<"nope"<<endl;
      //errorReport();
}

void Parse::Block()
{
   if(LHS=="begin")
   {
      match();
      DefPtr();
      StatPtr();
      
      if(LHS=="end")
      {

      }
      else
	 cout<<" inside Block ";
	 //errorReport();
   }else
      cout<<" next to ";
      //errorReport();
}

void Parse::DefPtr()
{
   Def();
   if(LHS==";")
   {
      match();
      DefPtr();
   }
//or
//epsilon
   
   
}
void Parse::Def()
{
   ConstDef();
//or
   VarDef();
//or
   ProcDef();
}
void Parse::ConstDef()
{
   if(LHS=="const")
   {
      match();
      ConstName();
      if(LHS=="=")
      {
	 match();
	 Const();
      }
   }
}
void Parse::VarDef()
{
   TypeSym();
   VarList();
//or
   TypeSym();
      if(LHS=="array")
      {
	 match();
	 VarList();
	 if(LHS=="[")
	 {
	    match();
	    Const();
	 
	    if(LHS=="]")
	    {
	       match();
	    }
	 }
      }

}

void Parse::TypeSym()
{
   if(LHS=="integer")
   {
      match();
   }
//or
   if(LHS=="boolean")
   {
      match();
   }
}
void Parse::VarList()
{
   VarName();
   VarListB();
}
void Parse::VarListB()
{
   if(LHS==",")
   {
      match();
      VarName();
      VarListB();
   }
//or
//epsilon

}
void Parse::ProcDef()
{
   if(LHS=="proc")
   {
      match();
      ProcName();
      Block();
   }
}

void Parse::StatPtr()
{
   Stat();
   if(LHS==";")
   {
      match();
      StatPtr();
   }
//or
//epsilon   
}
void Parse::Stat()
{
   EmptyStat();
//or
   ReadStat();
//or
   WriteStat();
//or   
   AsnStat();
//or   
   ProcStat();
//or   
   IfStat();
//or   
   DoStat();
}
void Parse::EmptyStat()
{
   if(LHS=="skip")
   {
      match();
   }
}
void Parse::ReadStat()
{
   if(LHS=="read")
   {
      match();
      VarAcList();
   }
}

void Parse::VarAcList()
{
   VarAc();
   VarAcListB();
}
void Parse::VarAcListB()
{
   if(LHS==",")
   {
      match();
      VarAc();
      VarAcListB();
   }
//or
//epsilon

}
void Parse::WriteStat()
{
   if(LHS=="write")
   {
      match();
      ExpList();
   }
}
void Parse::ExpList()
{
   Exp();
   ExpListB();
}

void Parse::ExpListB()
{
   if(LHS==",")
   {
      match();
      Exp();
      ExpListB();
   }
//or
//epsilon
}
void Parse::AsnStat()
{
   VarAcList();
   if(LHS==":=")
   {
      match();
      ExpList();
   }
}
void Parse::ProcStat()
{
   if(LHS=="call")
   {
      match();
      ProcName();
   }
}
void Parse::IfStat()
{
   if(LHS=="if")
   {
      match();
      GarCmdList();
      if(LHS=="fi")
      {
	 match();
      }
   }
}

void Parse::DoStat()
{
   if(LHS=="do")
   {
      match();
      GarCmdList();
      if(LHS=="od")
      {
	 match();
      }
   }
}

void Parse::GarCmdList()
{
   GarCmd();
   GarCmdListB();
}
void Parse::GarCmdListB()
{
   if(LHS=="[]")
   {
      match();
      GarCmd();
      GarCmdListB();
   }
//or
//epsilon
}

void Parse::GarCmd()
{
   Exp();
   if(LHS=="->")
   {
      match();
      StatPtr();
   }

}
void Parse::Exp()
{
   PrimExp();
   ExpB();
}

void Parse::ExpB()
{
   PrimOp();
   PrimExp();
   ExpB();
//or
//epsilon
}
void Parse::PrimOp()
{
   if(LHS=="&")
   {
      match();
   }
//or
   if(LHS=="|")
   {
      match();
   }
}

void Parse::PrimExp()
{
   SimpExp();
   PrimExpB();
}
void Parse::PrimExpB()
{
   RelatOp();
   SimpExp();
//or
//epsilon

}
void Parse::RelatOp()
{
if(LHS=="<")
   {
      match();
   }
//or
if(LHS=="=")
   {
      match();
   }
//or
if(LHS==">")
   {
      match();
   }
}
void Parse::SimpExp()
{
   Line();
   Term();
   SimpExpB();
}

void Parse::Line()
{
   if(LHS=="-")
   {
      match();
   }
//or
//epsilon
}

void Parse::SimpExpB()
{
   AddOp();
   Term();
   SimpExpB();
//or
//epsilon
}
void Parse::AddOp()
{
   if(LHS=="+")
   {
      match();
   }
//or
   if(LHS=="-")
   {
      match();
   }
}
void Parse::Term()
{
   Factor();
   TermB();
}
void Parse::TermB()
{
   MultOp();
   Factor();
   TermB();
//or
//epsilon
}
void Parse::MultOp()
{
   if(LHS=="*")
   {
      match();
   }
//or
   if(LHS=="%")
   {
      match();
   }
//or
   if(LHS=="/")
   {
      match();
   }
}
void Parse::Factor()
{
   Const();
//or
   VarAc();
//or
   if(LHS=="(")
   {
      match();
      Exp();
      if(LHS==")")
      {
	 match();
      }
   }
//or
   if(LHS=="~")
   {
      match();
      Factor();
   } 
}

void Parse::VarAc()
{
   VarName();
   VarAcB();
}

void Parse::VarAcB()
{
   IndexSelect();
//or
//epsilon
}

void Parse::IndexSelect()
{
   if(LHS=="[")
   {
      match();
      Exp();
      if(LHS=="]")
      {
	 match();
      }
   }
}

void Parse::Const()
{
   Num();
//or
   BoolSym();
//or
   ConstName();
}

void Parse::BoolSym()
{
   if(LHS=="false")
   {
      match();
   }
//or
   if(LHS=="true")
   {
      match();
   }
}

void Parse::VarName()
{
   if(LHS=="id")
   {
      match();
   }
}

void Parse::ConstName()
{
   if(LHS=="id")
   {
      match();
   }
}

void Parse::Num()
{
   if(LHS=="id")
   {
      match();
   }
}

void Parse::ProcName()
{
   if(LHS=="id")
   {
      match();
   }
}
