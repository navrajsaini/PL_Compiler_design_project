/*
  parcer.cpp implementation file
  by Navraj Saini and Jordan Kolody
*/
#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"
#include "administration.h"

using namespace std;
//constructor that initialises the lets line array and sets other vars
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
//assins the test line
void Parse::asn(int sec, int part, int numb)
{
   ln[sec+1][part]=numb;
   //test line
   //cout<<"token and line num: "<<numb<<" ";
}
//the beginning of the parsing
void Parse::parseIt()  
{  
   match();
   parseNow();
   //errorReport();
}
//creating the token string list
void Parse::tokens(string val)
{
   //test line
   //cout<<" "<<val<<" ";
   token[tokCount]=val;
   tokCount++;
   
}
//print function for tokens strings
void Parse::printToken()
{
   for(int i=0; i<156;i++)
   {
      cout<<"token '"<<i<<"' is '"<<token[i]<<"' ";
   }
}
// the match function that incriments LHS with a couple test lines.
void Parse::match()
{
   LHS=token[tokeNum];
   tokeNum++;
   //test line
   cout<<"token '"<<LHS<<"' is token '"<<tokeNum-1<<"'"<<endl;
}
//give a decent;y detailed report of the type of error that has been found
void Parse::errorReport()
{
   cout<<endl<<"With the "<<tokeNum<<"th token, there was an error on Line Number: "<<ln[tokeNum][0]+1<<" in : "<<where<<", token: "<<LHS<<", number "<<ln[tokeNum][1]<<endl; 
}
//--------------------------------------------------------------------------
//the start of the grammar
void Parse::parseNow()
{
   //test line
   //printToken();
   Program();
   
}
void Parse::check()
{
   cout<<endl<<LHS<<" "<<ln[tokeNum][1]<<" "<<where<<endl;
}
/*This is the start of the PL Grammar Parsing Stage.
  The rest of the functions are the grammar functions.
  There is minimal commenting through all of the grammar functions.
  They are self explanitory.
  I eddited the grammar to change the 0 or 1 iterations
  and also the 0 or more iterations.
  They were made into new functions
  Furthermore i removed amiguioty by adding new grammar rules
  this code also checks for error as it goes then sends back an error report
  from the result.
  Thats pretty much it for explanation here. everytime a terminal is found
  match is called then LHS is incrimented to the next look ahead.
 */
void Parse::Program()
{where="P";check();
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
{where="B";check();
   if(LHS=="begin")
   {
      match();
      DefPtr();
      StatPtr();
      
      if(LHS=="end")
      {
	 match();
      }else{
	 cout << "in the first else in B." << endl;
	 where="B";
	 errorReport();
      }
   }else
   {
      cout << "in the last else in B..." << endl;
      where="B";
      errorReport();
   }
}

void Parse::DefPtr()
{where="DP";check();
   if(LHS=="const"||LHS=="integer"||LHS=="boolean"||LHS=="proc")
   {
      Def();
      //cout<<" ."<<LHS<<". ";
      if(LHS==";")
      {
	 match();
	 DefPtr();
      }else
      {
	 where="DP";	 
	 errorReport();
      }
   }  
}
void Parse::Def()
{where="D";check();
   if(LHS=="const")
   {
      ConstDef();
   }else if(LHS=="integer"||LHS=="boolean")
   {  
      VarDef();
   }else if(LHS=="proc")
   {
      ProcDef();
   }else
      errorReport();
}
void Parse::ConstDef()
{where="CD";check();
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
{where="VD";check();
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
{where="VDB";check();
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
{where="TS";check();
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
{where="VL";check();
   if(LHS=="id")
   {
      VarName();
      VarListB();
   }else
      errorReport();
}
void Parse::VarListB()
{where="VLB";check();
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
{where="PD";check();
   if(LHS=="proc")
   {
      match();
      ProcName();
      Block();
   }
}

void Parse::StatPtr()
{where="SP";check();
   if(LHS=="skip"||LHS=="read"||LHS=="write"||LHS=="id"||LHS=="do"||LHS=="call"||LHS=="if")
   {
      Stat();
      if(LHS==";")
      {
	 match();
	 StatPtr();
      }else
      {
	 where = "SP";
	 errorReport();
      }
   }else
   {
   }
}
void Parse::Stat()
{where="S";check();
   if(LHS=="read")
   {
      ReadStat();
   }else if(LHS=="skip")
   {
      EmptyStat();
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
{where="ES";check();
   if(LHS=="skip")
   {
      match();
   }
}
void Parse::ReadStat()
{where="RS";check();
   if(LHS=="read")
   {
      match();
      VarAcList();
   }else
   {
      //where="RS";
      //errorReport();
   }
}

void Parse::VarAcList()
{where="VAL";check();
   if(LHS=="id")
   {
      VarAc();
      VarAcListB();
   }else
      errorReport();
}
void Parse::VarAcListB()
{where="VALB";check();
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
{where="WS";check();
   if(LHS=="write")
   {
      match();
      ExpList();
   }
}
void Parse::ExpList()
{where="EL";check();
   if(LHS=="+"||LHS=="-"||LHS==">"||LHS=="<"||LHS=="="||LHS=="|"||LHS=="->"||LHS=="&"||LHS=="num"||LHS=="true"||LHS=="false"||LHS=="id"||LHS=="~"||LHS==","){
      Exp();
      ExpListB();
   }else
      errorReport();
}
void Parse::ExpListB()
{where="ELB";check();
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
{where="AS";check();
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
{where="PS";check();
   if(LHS=="call")
   {
      match();
      ProcName();
   }
}
void Parse::IfStat()
{where="IS";check();
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
{where="DS";check();
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
{where="GCL";check();
   //didnt include all the possibilities
   GarCmd();
   GarCmdListB();
}
void Parse::GarCmdListB()
{where="GCLB";check();
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
{where="GC";check();
   Exp();
   if(LHS=="->")
   {
      match();
      StatPtr();
   }else
      errorReport();

}
void Parse::Exp()
{where="E";check();
//   if(LHS=="num"||LHS=="true"||LHS=="false"||LHS=="id"||LHS=="("||LHS=="~"||LHS=="num"||LHS=="true"||LHS=="false"||LHS=="id"||LHS=="("||LHS=="+")
//   {
      PrimExp();
      ExpB();
//   }else
//      errorReport();
}

void Parse::ExpB()
{where="EB";check();
   if(LHS=="|"||LHS=="&")
   {
      PrimOp();
      PrimExp();
      ExpB();
   }else
   {
      
   }
}
void Parse::PrimOp()
{where="PO";check();
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
{where="PE";check();
   
      SimpExp();
      PrimExpB();
}
void Parse::PrimExpB()
{where="PEB";check();
   if(LHS=="<"||LHS=="="||LHS==">")
   {
      RelatOp();
      SimpExp();
   }else
   {
      
   }
}
void Parse::RelatOp()
{where="RO";check();
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
{where="SE";check();
//   if(LHS=="-"||LHS=="num"||LHS=="false"||LHS=="true"||LHS=="id"||LHS=="("||LHS=="~")
//   {
      Line();
      Term();
      SimpExpB();
//   }else
//      errorReport();
}

void Parse::Line()
{where="L";check();
   if(LHS=="-")
   {
      match();
   }else
   {

   }
}

void Parse::SimpExpB()
{where="SEB";check();
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
{where="AO";check();
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
{where="T";check();
   if(LHS=="num"||LHS=="false"||LHS=="true"||LHS=="id"||LHS=="("||LHS=="~")
   {
      Factor();
      TermB();
   }else
      errorReport();
}
void Parse::TermB()
{where="TB";check();
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
{where="MO";check();
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
{where="F";check();
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
{where="Va";check();
   if(LHS=="id")
   {
      VarName();
      VarAcB();
   }else if(LHS=="num")
   {
    }else
      errorReport();
}
void Parse::VarAcB()
{where="VAB";check();
   if(LHS=="[")
   {
      IndexSelect();
   }else
   {

   }
}
void Parse::IndexSelect()
{where="IS";check();
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
{where="C";check();
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
{where="BS";check();
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
{where="VN";check();
   if(LHS=="id")
   {
      match();
   }
}

void Parse::ConstName()
{where="CN";check();
   if(LHS=="id")
   {
      match();
   }else
      errorReport();
}

void Parse::Num()
{where="N";check();
   if(LHS=="num")
   {
      match();
   }else
      errorReport();
}

void Parse::ProcName()
{where="PN";check();
   if(LHS=="id")
   {
      match();
   }else
      errorReport();
}
   
