/*
  parcer.cpp implementation file
  by Navraj Saini and Jordan Kolody
*/
#include <iostream>
#include <fstream>
#include <string>
#include "parser.h"


using namespace std;
//constructor that initialises the lets line array and sets other vars
Parse::Parse(string in)
{
   file=in;
   //tokeNum=0;
   for(int i=0; i<256; i++)
   {
      ln[i][0]=0;
      ln[i][1]=0;
      ln[i][2]=0;
   }
}
//assins the test line
void Parse::asn(int sec, int part, int numb)
{
   ln[sec][part] = numb;
   //test line
   cout<<"token/line/num: "<<numb<<" "<<endl;
}
void Parse::asnS(int sec, string s)
{
   lnLex[sec] = s;
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
   NS=LHS;
   LHS=token[tokeNum];
   tokeNum++;
   //test line
   //cout<<"token '"<<LHS<<"' is the '"<<tokeNum-1<<"' token parsed"<<endl;
}
//give a decent;y detailed report of the type of error that has been found
void Parse::errorReport()
{
   cout<<endl<<"Total tokens parsed: '"<<tokeNum;
   cout<<"' There was an error on Line Number: '";
   cout<<ln[tokeNum][0]<<"'"<<endl;
   cout<<"This, has the last function to be called acronymed as: '";
   cout<<where<<"'"<<endl;
   cout<<"The token of issue is: '"<<NS;
   cout<<"' with a hashval of: '"<<ln[tokeNum-1][1]<<"'"<<endl; 
}
//check for user input to then pring parsing as it occours
void Parse::check()
{
   if(yn==1)
   {
      cout<<endl<<LHS<<" "<<ln[tokeNum-1][1]<<" "<<where<<endl;
   }
}
//outputs the error msg for the scope
void Parse::scopeError(string s)
{
   cout<<s<<endl;
}
//wipe the variables for the next type check
void Parse::eraseVar()
{
   index = -1;
   eKind = UNDEFINED;
   eType = UNIVERSAL;
   checkLex = -1;
   size = 1;

}

//checks the scope and inserts into the table
bool Parse::checkDef()
{       
   if (!bTable.define(index, eKind, eType, size, checkLex))
   {
      eraseVar();
      return false;
   }
   eraseVar();
   return true;
}
//assigns both index and checkLex
void Parse::asnIndexLex()
{
   index = ln[tokeNum][1];
   checkLex = ln[tokeNum][2];
}
//this is initializing the list depth level of index and lex to their values.
void Parse::asnIndexLexList()
{
   varListIndex[listDepth] = ln[tokeNum][1];
   varListLex[listDepth] = ln[tokeNum][2];
   listDepth++;
}
//this does the same thing as check Deff but parses through a list of pairs of values
bool Parse::checkDefList()
{
   for(listDepth = 0; listDepth <= 10; listDepth++)
   {
      if (!bTable.define(varListIndex[listDepth], eKind, eType, size, varListLex[listDepth]))
      {
	 eraseList();
	 return false;
      }
   }
   eraseList();
   return true;
}
//erases the list for the next line that has it.
void Parse::eraseList()
{
   eraseVar();
   for(listDepth = 0; listDepth <= 10; listDepth++)
   {
      varListIndex[listDepth] = -1;
      varListLex[listDepth] =-1; 
   }
   listDepth = 0;
}

//--------------------------------------------------------------------------
//the start of the grammar
void Parse::parseNow()
{
   //test line
   //printToken();
   NS=LHS;
   Program();
   
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

  the names of the functions are added in in the comments.
 */
void Parse::Program()
{where="P";check();
   if(LHS=="begin")
   {
      //create a new block
      if(!bTable.newBlock())
	 scopeError("Exceded Block limit");
      //
      
      Block();
   
      if(LHS==".")
      {
	 bTable.endBlock();
	 cout<<endl<<"YOU SUCCESSFULY PARSED, CONGRATS!!!!"<<endl;
      }else
	 errorReport();
   }else
      errorReport();
}
//-----
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
      }else
	 errorReport();
   }else
      errorReport();
}
//-----
void Parse::DefPtr()
{where="DP";check();
   if(LHS=="const"||LHS=="integer"||LHS=="boolean"||LHS=="proc"||LHS=="Boolean")
   {
      Def();
      if(LHS==";")
      {
	 match();
	 DefPtr();
      }else	 
	 errorReport();
   }  
}
//-----
void Parse::Def()//definition function
{where="D";check();
   if(LHS=="const")
   {
      ConstDef();
      if(!checkDef())
	 scopeError("Ambiguous definition of constant");
      
   }else if(LHS=="integer"||LHS=="boolean"||LHS=="Boolean")
   {
      VarDef();     
      if(!checkDef())
	 scopeError("Ambiguous definition of Variable");
   }else if(LHS=="proc")
   {
      ProcDef();
   }else
      errorReport();
}
//----
void Parse::ConstDef()
{where="CD";check();
   if(LHS=="const")
   {
      //Initializing
      eType = UNIVERSAL;
      eKind = CONSTANT;
      //
      match();
      ConstName();
      if(LHS=="=")
      {
	 match();
	 Const();
      }
   }
}
void Parse::VarDef()//variable definition
{where="VD";check();
   if(LHS=="boolean"||LHS=="Boolean"||LHS=="integer")
   {
//Scope/Type
      eKind=VAR;
//
      TypeSym();
      VarDefB();
   }else
   {
      errorReport();
   } 
}

void Parse::VarDefB()//variable definition for multiple itirations
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

void Parse::TypeSym()//Type Symbol
{where="TS";check();
   if(LHS=="integer")
   {
      eType = INT;
      
      match();
   }else if(LHS=="boolean"||LHS=="Boolean")
   {
      eType = BOOL;
      match();
   }else
      errorReport();
}
void Parse::VarList()//variable list
{where="VL";check();
   if(LHS=="id")
   {
      VarName();
      VarListB();
   }else
      errorReport();
}
void Parse::VarListB()//variable list for multiple itiretions
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
void Parse::ProcDef()//procedure definition
{where="PD";check();
   if(LHS=="proc")
   {
      match();
      ProcName();
      Block();
   }
}

void Parse::StatPtr()//statement part
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
void Parse::Stat()//statement
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
void Parse::EmptyStat()//empty statement
{where="ES";check();
      match(); 
}
void Parse::ReadStat()//read statement
{where="RS";check();
   if(LHS=="read")
   {
      match();
      VarAcList();
   }else
   {

   }
}

void Parse::VarAcList()//variable access list
{where="VAL";check();
   if(LHS=="id")
   {
      VarAc();
      VarAcListB();
   }else
      errorReport();
}
void Parse::VarAcListB()//variable access list for iterations
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
void Parse::WriteStat()//write statement
{where="WS";check();
   if(LHS=="write")
   {
      match();
      ExpList();
   }
}
void Parse::ExpList()//expression list
{where="EL";check();
      Exp();
      ExpListB();
}
void Parse::ExpListB()//expression list for multiple iterations
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
void Parse::AsnStat()//assignment statement
{where="AS";check();
 
      VarAcList();
      if(LHS==":=")
      {
	 match();
	 ExpList();
      }else
	 errorReport();

}
void Parse::ProcStat()//procedure statement
{where="PS";check();
   if(LHS=="call")
   {
      match();
      ProcName();
   }
}
void Parse::IfStat()//if statements
{where="IS";check();
      match();
      GarCmdList();
      if(LHS=="fi")
      {
	 match();
      }else
	 errorReport();
}

void Parse::DoStat()//do statement
{where="DS";check();

      match();
      GarCmdList();
      if(LHS=="od")
      {
	 match();
      }else
	 errorReport();
}

void Parse::GarCmdList()//guarded command list
{where="GCL";check();
   GarCmd();
   GarCmdListB();
}
void Parse::GarCmdListB()//guarded command list for multiple iterations
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

void Parse::GarCmd()//guarded command
{where="GC";check();
   Exp();
   if(LHS=="->")
   {
      match();
      StatPtr();
   }else
      errorReport();
}
void Parse::Exp()//expression
{where="E";check();
      PrimExp();
      ExpB();
}

void Parse::ExpB()//expression for multiple iterations
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
void Parse::PrimOp()//primary operations
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

void Parse::PrimExp()//primary expressions
{where="PE";check();
   
      SimpExp();
      PrimExpB();
}
void Parse::PrimExpB()//primary expression for multiple iterations
{where="PEB";check();
   if(LHS=="<"||LHS=="="||LHS==">")
   {
      RelatOp();
      SimpExp();
   }else
   {
      
   }
}
void Parse::RelatOp()//relational operator
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
void Parse::SimpExp()//simple expression
{where="SE";check();

      Line();
      Term();
      SimpExpB();

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

void Parse::SimpExpB()//simple expression for multiple iterations
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
void Parse::AddOp()//Add/subtract operator
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
void Parse::Term()//Term
{where="T";check();

      Factor();
      TermB();

}
void Parse::TermB()//term for multiple iterations
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
void Parse::MultOp()//multiplying, div, and mod operator
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
void Parse::Factor()//factor
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
void Parse::VarAc()//Variable access
{where="Va";check();
      VarName();
      VarAcB();
}
void Parse::VarAcB()//variable access for mulitple iterations
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
void Parse::Const()//constant
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
void Parse::BoolSym()//boolean symbol
{where="BS";check();
   if(LHS=="false")
   {
      asnIndexLex();
      match();
   }else if(LHS=="true")
   {
      asnIndexLex();
      match();
   }else
      errorReport();
}

void Parse::VarName()//variable name
{where="VN";check();
   if(LHS=="id")
   {
      asnIndexLex();
      match();
   }
}

void Parse::ConstName()//constant name
{where="CN";check();
   if(LHS=="id")
   {
      asnIndexLex();
      match();
   }else
      errorReport();
}

void Parse::Num()//number
{where="N";check();
   if(LHS=="num")
   {
      asnIndexLex();
      match();
   }else
      errorReport();
}

void Parse::ProcName()//procedure name
{where="PN";check();
   if(LHS=="id")
   {  
      asnIndexLex();
      
      match();
   }else
      errorReport();
}
   
