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
#include "types.h"
#include "administration.h"
#include "BlockTable.h"
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
   void asnS(int, string);
//starts parsing through the Grammar
   void parseNow();
//print the token string
   void printToken();
//creats a list of the tokens to be parsed
   void tokens(string);
//var for token strings
   string token[256];
//parse vars: tokCount is for match, file is for opening the file,
//and tokeNum is also for match, the two allow for the flexebility, for error reporting during the parsing stage 
   int tokCount = 0;
   string file;
   int tokeNum = 0;
//for outputting the parsing as it occours, mostly a testing variable
   bool yn = 0, yn2 = 0;
//test array for line number, index, and value
   int ln[256][3];
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
//Scope/Type
/*This block of code is for the scope and type checking parts*/
//test for lexical error report inside of the scope and type check.
   string lnLex[256];
//initializing the block table for scope and typ checking
   BlockTable bTable;
//outputs an error
   void scopeError(string);
//initiates and checks the error as to see if its in block table or not it it isnt
//it inserts if it isnt it returns false and then the scope error fucntion is ran
   bool checkDef();
//erases the varaiables for the next check.
   void eraseVar();
//assigns both index and checkLex
   void asnIndexVal(int);
   void asnIndexValList(int);
//variable list
   int varListIndex[10];
   int varListVal[10];
// 0 = name, 1 = index 
   bool checkDefList();
   int listDepth = 0;
   void eraseList();
//value for the initilizing either the value or index, LorA is differentiating
//between list and list ac.
   int dx = 2, vl = 3, bl0 = 0, bl1 = 1, LorA = 0;
//varAcL keeps track fo how many left variables are used
//varAcR keeps track of how many right variables have been used. 
   int varAcL = 0, varAcR = 0;
   int varAcName[10];//the array for the names for var ac
   bool exist = 0, en;
   void o();
   void printPop();
  private:
//indicates type for the block table
   myType eType;
//indicated the kind for block table
   Kind eKind;
//indicates the index for the original hash table
   int index, index2;
//index= ln[tokeNum][1];
   int checkVal = 0;
//for size of arrays
   int size[10] = {1};
//test line for 
//      if (!bTable.define(cnameindex, CONSTANT, temptype, 1, tempvalue))
//	 scopeError("Ambiguous definition of constant");
   void printScopeType(bool);
   TableEntry ent;
/*end of scope and type checking variables and functions*/
//--------------------------------
//FILE STREAM
   ifstream input;
//private variables: LHS is look ahead symbol
   string LHS = "";
   string NS;
   int value;
//when a match is found match is called and match incriments LHS by one.
   void match();
//error reporting fuction
   void errorReport();
//the check function that compares then incriments
   void check();
//states where the parsing is, mostly for error checking and bug testing.
   string where;

   Admin gen;
   int NewLabel();
   int label = 0;
   int varLabel, startLabel, varLength;
};
#endif
