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
   //first(program)
   if(LHS=="begin")
   {
      Block();
   
      if(LHS==".")
      {
	 cout<<endl<<"YOU SUCCESSFULY PARSED, CONGRATS!!!!"<<endl;
      }else
	 errorReport();
   }else
      errorReport();
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

      }else
	 errorReport();
   }else
      errorReport();
}

void Parse::DefPtr()
{
   if(LHS=="const"||LHS=="integer"||LHS=="boolean"||LHS=="proc")
   {
      Def();
      if(LHS==";")
      {
	 match();
	 DefPtr();
      }
   }  
}
void Parse::Def()
{
   if(LHS=="const")
   {
      ConstDef();
   }else if(LHS=="integer"||LHS=="boolean")
   {  
      VarDef();
   }else if(LHS=="proc")
   {
      ProcDef();
   }
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
   if(LHS=="boolean"||LHS=="integer")
   {
      TypeSym();
      VarDefB();
   }else
   {
      errorReport();
   } 
}
void Parse::VarDefB()
{
   if(LHS=="id")
   {
      VarList();
   }else if(LHS=="array")
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
   }else
   {
      errorReport();
   }
}

void Parse::TypeSym()
{
   if(LHS=="integer")
   {
      match();
   }else if(LHS=="boolean")
   {
      match();
   }else
      errorReport();
}
void Parse::VarList()
{
   if(LHS=="id")
   {
      VarName();
      VarListB();
   }else
      errorReport();
}
void Parse::VarListB()
{
   if(LHS==",")
   {
      match();
      VarName();
      VarListB();
   }else
   {
      
   }
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
   if(LHS=="skip"||LHS=="read"||LHS=="write"||LHS=="id"||LHS=="do"||LHS=="call"||LHS=="if")
   {
      Stat();
      if(LHS==";")
      {
	 match();
	 StatPtr();
      }
   }else
   {
   }
}
void Parse::Stat()
{
   if(LHS=="read")
   {
      EmptyStat();
   }else if(LHS=="skip")
   {
      ReadStat();
   }else if(LHS=="write")
   {
   WriteStat();
   }else if(LHS=="id")
   {
   AsnStat();
   }else if(LHS=="call") 
   {
      ProcStat();
   }else if(LHS=="if")
   {
      IfStat();
   }else if(LHS=="do")
   {
      DoStat();
   }else
      errorReport();
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
   if(LHS=="id")
   {
      VarAc();
      VarAcListB();
   }else
      errorReport();
}
void Parse::VarAcListB()
{
   if(LHS==",")
   {
      match();
      VarAc();
      VarAcListB();
   }else
   {
      
   }
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
   if(LHS=="+"||LHS=="-"||LHS==">"||LHS=="<"||LHS=="="||LHS=="|"||LHS=="->"||LHS=="&"){
      Exp();
      ExpListB();
   }else
      errorReport();
}
void Parse::ExpListB()
{
   if(LHS==",")
   {
      match();
      Exp();
      ExpListB();
   }else
   {
      
   }
}
void Parse::AsnStat()
{
   if(LHS=="id")
   {
      VarAcList();
      if(LHS==":=")
      {
	 match();
	 ExpList();
      }else
	 errorReport();
   }else
      errorReport();
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
   }else
   {
      
   }
}

void Parse::GarCmd()
{
   Exp();
   if(LHS=="->")
   {
      match();
      StatPtr();
   }else
      errorReport();

}
void Parse::Exp()
{
   if(LHS=="+"||LHS=="-"||LHS=="<"||LHS==">"||LHS=="=")
   {
      PrimExp();
      ExpB();
   }else
      errorReport();
}

void Parse::ExpB()
{
   if(LHS=="+"||LHS=="-"||LHS=="<"||LHS==">"||LHS=="=")
   {
      PrimOp();
      PrimExp();
      ExpB();
   }else
   {

   }
}
void Parse::PrimOp()
{
   if(LHS=="&")
   {
      match();
   }else if(LHS=="|")
   {
      match();
   }else
      errorReport();
}

void Parse::PrimExp()
{
      SimpExp();
      PrimExpB();
}
void Parse::PrimExpB()
{
   if(LHS=="<"||LHS=="="||LHS==">")
   {
      RelatOp();
      SimpExp();
   }else
   {
      
   }
}
void Parse::RelatOp()
{
   if(LHS=="<")
   {
      match();
   }else if(LHS=="=")
   {
      match();
   }else if(LHS==">")
   {
      match();
   }else
      errorReport();
}
void Parse::SimpExp()
{
   if(LHS=="-"||LHS=="num"||LHS=="false"||LHS=="true"||LHS=="id"||LHS=="("||LHS=="~")
   {
      Line();
      Term();
      SimpExpB();
   }else
      errorReport();
}

void Parse::Line()
{
   if(LHS=="-")
   {
      match();
   }else
   {

   }
}

void Parse::SimpExpB()
{
   if(LHS=="-"||LHS=="+")
   {
      AddOp();
      Term();
      SimpExpB();
   }else
   {

   }
}
void Parse::AddOp()
{
   if(LHS=="+")
   {
      match();
   }else if(LHS=="-")
   {
      match();
   }else
      errorReport();
}
void Parse::Term()
{
   if(LHS=="num"||LHS=="false"||LHS=="true"||LHS=="id"||LHS=="("||LHS=="~")
   {
      Factor();
      TermB();
   }else
      errorReport();
}
void Parse::TermB()
{
   if(LHS=="*"||LHS=="%"||LHS=="/")
   {
      MultOp();
      Factor();
      TermB();
   }else
   {

   }
}
void Parse::MultOp()
{
   if(LHS=="*")
   {
      match();
   }else if(LHS=="%")
   {
      match();
   }else if(LHS=="/")
   {
      match();
   }else
      errorReport();
}
void Parse::Factor()
{
   if(LHS=="num"||LHS=="false"||LHS=="true")
   {
      Const();
   }else if(LHS=="id")
   {
      VarAc();
   }else if(LHS=="(")
   {
      match();
      Exp();
      if(LHS==")")
      {
	 match();
      }else
	 errorReport();
   }else if(LHS=="~")
   {
      match();
      Factor();
   }else
      errorReport();
}

void Parse::VarAc()
{
   if(LHS=="id")
   {
      VarName();
      VarAcB();
   }else
      errorReport();
}

void Parse::VarAcB()
{
   if(LHS=="[")
   {
      IndexSelect();
   }else
   {

   }
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
   if(LHS=="num")
   {
      Num();
   }else if(LHS=="true"||LHS=="false")
   {
      BoolSym();
   }else if(LHS=="id")
   {
      ConstName();
   }else
      errorReport();
}

void Parse::BoolSym()
{
   if(LHS=="false")
   {
      match();
   }else if(LHS=="true")
   {
      match();
   }else
      errorReport();
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
   }else
      errorReport();
}

void Parse::Num()
{
   if(LHS=="id")
   {
      match();
   }else
      errorReport();
}

void Parse::ProcName()
{
   if(LHS=="id")
   {
      match();
   }else
      errorReport();
}
   
