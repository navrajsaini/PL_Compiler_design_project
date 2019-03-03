/*
  Parcer.h file
  by Navraj and Jordan
  Helper functions for parcing the token file retrieved from the scanner
  uses the lookahead symbol
 */

#ifndef PARSE_H
#define PARSE_H

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Parse
{
  public:

   Parse(string in);
   void parseIt();
   void asn(int, int, int);
   void parseNow();
   void tokens(string);
   string token[256];
   int tokCount=0;
   string file;
   void printToken();
   int tokeNum=0;
//------------------------------------------------------------------------
//the function that is executed to find the start of the program
   void Program();

//the function to determain the start of the block, looks for "begin"
   void Block();
   

//Functions for definitions of constants, variables, procedures
   void DefPtr();
   void Def();
   void ConstDef();
   void VarDef();

//function for the type of symbols "integer", "Boolean"
   void TypeSym();

//Functions for the names of lists
   void VarList();
   void VarListB();
   
//function for "proc"
   void ProcDef();

//functions for determining statements
   void StatPtr();
   void Stat();
   void EmptyStat();
   void ReadStat();

//functions for variable access list   
   void VarAcList();
   void VarAcListB();

//function to see if lookahead == "write"   
   void WriteStat();

//functions for expr list
   void ExpList();
   void ExpListB();
   
   void AsnStat();

   void ProcStat();

   void IfStat();

   void DoStat();

   void GarCmdList();

   void GarCmdListB();

   void GarCmd();

   void Exp();

   void ExpB();

   void PrimOp();

   void PrimExp();

   void PrimExpB();

   void RelatOp();

   void SimpExp();

   void SimpExpB();

   void Line();

   void AddOp();

   void Term();

   void TermB();

   void MultOp();

   void Factor();

   void VarAc();

   void VarAcB();

   void IndexSelect();

   void Const();

   void BoolSym();

   void VarName();

   void ConstName();

   void Num();

   void ProcName();
//---------------
   int ln[256][2];
  private:
   ifstream input;
   string LHS;
  
   void match();
   int value;
 


   void errorReport();
};
#endif
