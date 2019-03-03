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
//CONSTRUCTOR
   Parse(string in);
//INITIATES THE Parsing
   void parseIt();
//assigns the parse teser line 
   void asn(int, int, int);
//starts parsing through the Grammar
   void parseNow();
//print the token string
   void printToken();
//creats a list of the tokens to be parsed
   void tokens(string);
//var for token strings
   string token[256];
//parse vars: tokCount is for match, file is for opening the file,
//and tokeNum is also for match
   int tokCount=0;
   string file;
   int tokeNum=0;
   bool yn=0;
//------------------------------------------------------------------------
/*The Grammar Rule functions
  For a more detailed explanation go to parse.cpp  
 */
   void Program();
   void Block();
   void DefPtr();
   void Def();
   void ConstDef();
   void VarDef();
   void VarDefB();
   void TypeSym();
   void VarList();
   void VarListB();
   void ProcDef();
   void StatPtr();
   void Stat();
   void EmptyStat();
   void ReadStat();   
   void VarAcList();
   void VarAcListB();   
   void WriteStat();
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
//---------------------------------------------
//test array for line number and error reporting 
   int ln[256][2];

  private:
//FILE STREAM
   ifstream input;
//private variables: LHS is look ahead symbol
   string LHS;
   string NS;
   int value;
//when a match is found match is called and match incriments LHS by one.
   void match();
//error reporting fuction
   void errorReport();
   void check();
   string where;
};
#endif
