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
   eraseList();
   for(int i = 0; i<10; i++)
      valLength[10] = 0;
   for(int i = 0; i<10; i++)
      levelOfCurrentBlock[i] = 3;
   
   label = 0;
   displacement = 3;
   tpVl = 0;
   currentLevel = 0;
   tempSizeRead = 0;
   tempSizeWrite = 0;
   tempSizeAsn = 0;
   startLabel = 0;
   varLabel = 0;
   listDepth = 0;
   for(int i = 0; i<10; i++)
      size[i] = 1;
}
//assins the test line
void Parse::asn(int sec, int part, int numb)
{
   ln[sec][part] = numb;
   //test line
   //cout<<"token/line/num: "<<numb<<" "<<endl;
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
   for(int i=1; i<256;i++)
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
//give a decent detailed report of the type of error that has been found
//additionaly it stops outputting errors after the first one
void Parse::errorReport()
{
   gen.emitting = 0;
   if(isErr == 0)
   {
      isErr = 1;
      cout<<endl<<"Total tokens parsed: '"<<tokeNum;
      cout<<"' There was an error on Line Number: '";
      cout<<ln[tokeNum][0]<<"'"<<endl;
      cout<<"This, has the last function to be called acronymed as: '";
      cout<<where<<"'"<<endl;
      cout<<"The token of issue is: '"<<LHS;
      cout<<"' with a hashval of: '"<<ln[tokeNum][1]<<"'"<<endl;
      cout<<"The token val of: '"<<ln[tokeNum][2]<<"'"<<endl;
      stopType = 1;
      ctd = 0;
   }
}
//check for user input to then pring parsing as it occours
void Parse::check()
{
   if(yn==1)
   {
      cout<<endl<<LHS<<" "<<ln[tokeNum][1]<<" "<<where<<" line "<<ln[tokeNum][0]<<endl;
   }
}
//outputs the error msg for the scope
void Parse::scopeError(string s)
{
   gen.emitting = 0;
   if(stopType == 0)
   {
      isErr = 1;
      cout<<s<<" with index: "<<ln[tokeNum][1]<<" at line:  "<<ln[tokeNum][0]<<" with token : "<<NS<<endl;
      ctd = 0;
   }
}
//wipe the variables for the next type check
void Parse::eraseVar()
{
   index = 0;
   eKind = UNDEFINED;
   eType = UNIVERSAL;
   checkVal = 0;
   size[0] = 1;
   listDepth = 0;

}

bool Parse::checkDefConst()
{//printScopeType(true);
   if (!bTable.define(index, eKind, eType, size[0], checkVal, levelOfCurrentBlock[currentLevel], 0))//proc label and displacement
   {
      eraseVar();
      return false;
   }
   //cout<<endl<<"'"<<levelOfCurrentBlock[currentLevel]<<"'"<<currentLevel<<"'"<<endl;
   levelOfCurrentBlock[currentLevel]++;
   eraseVar();
   return true;
}

//checks the scope and inserts into the table
bool Parse::checkDef(int procLabel)
{//printScopeType(true);
   if (!bTable.define(index, eKind, eType, 0, 0, 0, procLabel))
   {
      eraseVar();
      return false;
   }
   eraseVar();
   return true;
}
//this does the same thing as check Deff but parses through a list of pairs of values
bool Parse::checkDefList()
{//printScopeType(false);
   
   for(int limit = 0; limit < listDepth; limit++)
   {
      
      if (!bTable.define(varListIndex[limit], eKind, eType, size[limit], varListVal[limit],levelOfCurrentBlock[currentLevel], 0))//incriment displacment by 1
      {
	 eraseList();
	 return false;
      }
      //cout<<endl<<"'"<<levelOfCurrentBlock[currentLevel]<<"'"<<currentLevel<<"'"<<endl;
      levelOfCurrentBlock[currentLevel]++;
   }
   eraseList();
   return true;
}
//erases the list for the next line that has it.
void Parse::eraseList()
{
   eraseVar();
   for(int i = 0; i <= 10; i++)
   {
      varListIndex[i] = 0;
      varListVal[i] = 0;
      size[i] = 1;
   }
   listDepth = 0;
}

void Parse::printScopeType(bool y)
{
   if(y)
      cout<<"index: "<<index<<" "<<NS<<endl<<LHS<<"  "<<ln[tokeNum][1]<<endl;
   if(!y)
      cout<<"indexAc: "<<varListIndex[listDepth-1]<<" "<<endl<<LHS<<"  "<<ln[tokeNum][1]<<endl;
}

void Parse::o()
{ for(int i=1;token[i]!=".";i++)
   {
      cout<<"ln["<<i<<"][0]: "<<ln[i][0]<<endl;
      cout<<"ln["<<i<<"][1]: "<<ln[i][1]<<endl;
      cout<<"ln["<<i<<"][2]: "<<ln[i][2]<<endl;
      cout<<"token["<<i<<"]: "<<token[i]<<endl<<endl;
   }

}
void Parse::printPop()
{
   if(yn2==1)
      bTable.printtable();
}
//--------------------------------------------------------------------------
//the start of the grammar
void Parse::parseNow()
{  //test line
   //printToken();
   //o();
   //LHS = token[tokeNum];
   for(int i = 0; i<10; i++)
      valLength[i] = 0;
   NS=LHS;
   //cout<<endl<<LHS<<endl;
   Program();
   for(int i = 0; i<10; i++)
      valLength[i] = 0;
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
/*comments for the psudo code gen
lable is to increment after every token eccept for semicolin
The Emit called is dependent on what info is needed , the instruction
plus the info: var len, address, ...
*/
//--- depicts that the functions before belong to the scope type check and
//*** depicts functions related to code genneration
void Parse::Program()
{where="P";check();
   if(LHS=="begin")     
   {      
      //create a new block for scope/type
      if(!bTable.newBlock())
	 scopeError("Exceded Block limit");
      //---
      varLabel = newLabel();
      startLabel = newLabel();
      gen.emit3("PROG", varLabel, startLabel);
      //***   
      //call Block    
      Block();     
      //pop block
      printPop();
      bTable.endBlock();
      //---
      if(LHS==".")
      {
	 where="P";check();
	 cout<<"YOU SUCCESSFULY PARSED, CONGRATS!!!!"<<endl;
	 valLength[valLenPtr] = 0;
	 
      }else
	 errorReport();
      //
      gen.emit1("ENDPROG");     
      //***

   }else
      errorReport();
}
//-----
void Parse::Block()
{where="B";check();
   //local variable for code gen
   int sLabel = startLabel ,vLabel = varLabel;
   
   if(LHS=="begin")
   {

      
      
      match();
      //call defptr then stat ptr
      DefPtr();
      //
      gen.emit3("DEFARG", vLabel, valLength[valLenPtr]);
      gen.emit2("DEFADDR", sLabel);
      //***
      
      StatPtr();
      
      if(LHS=="end")
      {
	 valLength[valLenPtr] = 0;
	 match();
	 
      }else
	 errorReport();
   }else
      errorReport();
}
//-----
void Parse::DefPtr()
{where="DP";check();
// local code gen vars
   int varLength = 0;
   
   
   if(LHS=="const"||LHS=="integer"||LHS=="boolean"||LHS=="proc"||LHS=="Boolean")
   {  //calling def
      Def();
      
      
      if(LHS==";")
      {
	 match();
	 
	 DefPtr();
       
      }else if(LHS==".")
      {
      }else	 
	 errorReport();
   }  
}
//-----
void Parse::Def()//definition function
{where="D";check();

   
   if(LHS=="const")
   {
      //addone to the number of variables at the current block
      valLength[valLenPtr]++;

      //into const deff.
      ConstDef();
      //this adds the constant to the stack
      if(!checkDefConst())
	 scopeError("Ambiguous definition of constant");
      
   }else if(LHS=="integer"||LHS=="boolean"||LHS=="Boolean")
   {
      
      VarDef();
      if(!checkDefList())
	 scopeError("Ambiguious declaration in variable list");
   }else if(LHS=="proc")
   {
      //incriment to the next block
      valLenPtr++;

      ProcDef();

      //decrement to the previous block since end has been reached for current procedure
      valLenPtr--;
   }else
      errorReport();
}
//----
void Parse::ConstDef()
{where="CD";check();
   if(LHS=="const")
   {  //Initializing
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
   listDepth = 0;
   if(LHS=="boolean"||LHS=="Boolean"||LHS=="integer")
   {  //varKind
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
      valLength[valLenPtr]++;
      VarList();
   }else if(LHS=="array")
   {
      eKind = ARR;
      match();
      
      VarList();
      if(LHS=="[")
      { 
	 match();
	 bool sVal = 1;
	 if(LHS=="num")
	 {
	    checkVal=ln[tokeNum][2];	    
	 }else if(LHS=="id")
	 {	   
	    index2 = ln[tokeNum][1];
	    ent = bTable.find_all_level(index2);
	    bool lVal = bTable.search(index2);
	    sVal=lVal;
	    //cout<<bTable.inScope;
	    en=1;
	 }	 
	 Const();
	 if(!sVal)
	 {
	    scopeError("Error, Variable not declared in scope");    
	 }
	 bTable.inScope = 0;
	 if(en=1)
	 {
	    for(int i = 0; i < listDepth; i++)
	    {
	       size[i] = ent.value;
	    }
	 }else
	 {
	    for(int i = 0; i<listDepth;i++)
	    {
	       size[i] = checkVal;
	    }
	 }
	 size[0] = checkVal;
	 int tmp = checkVal;
	 valLength[valLenPtr] = valLength[valLenPtr] + checkVal;//
	 if(!checkDefList())
	    scopeError("Ambiguous definition of array");
	 levelOfCurrentBlock[currentLevel] = levelOfCurrentBlock[currentLevel] + (tmp - 1);
	 if(LHS=="]")
	 {
	    match();
	 }else
	    errorReport();
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
   {  //cout<<ln[tokeNum][1]<<where;
      varListIndex[listDepth] = ln[tokeNum][1];
      varListVal[listDepth] = 0;
      listDepth++;
      VarName();
      VarListB();
   }else
      errorReport();
}
void Parse::VarListB()//variable list for multiple itiretions
{where="VLB";check();
   if(LHS==",")
   {
      valLength[valLenPtr]++;
      match();
      //cout<<ln[tokeNum][1]<<where;
      varListIndex[listDepth] = ln[tokeNum][1];
      listDepth++;
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
      eKind = PROCEDURE;
      int procLabel = newLabel();
      // add to current block 
      if(!checkDef(procLabel))
	 scopeError("Ambiguous definition of Procedure");
      //add to block stack
      if(!bTable.newBlock())
	 scopeError("Exceded Block limit while declaring procedure");
      //

      varLabel = newLabel();
      startLabel = newLabel();  
      gen.emit2("DEFADDR", procLabel);
      gen.emit3("PROC", varLabel, startLabel);
      //***
      valLenPtr++;
      valLength[valLenPtr] = 0;
      currentLevel++;
      Block();
      valLenPtr--;
      levelOfCurrentBlock[currentLevel] = 3;
      currentLevel--;
      //remove block from stack
      printPop();
      bTable.endBlock();
      gen.emit1("ENDPROC");
   }
}

void Parse::StatPtr()//statement part
{where="SP";check();

      Stat();
      if(LHS==";")
      {
	 match();
	 StatPtr();
      }else if(LHS=="end"||LHS=="[]"||LHS=="fi"||LHS=="od")
      {
      }else
	 errorReport();

}
void Parse::Stat()//statement
{where="S";check();
   if(LHS=="[]"||LHS=="fi"||LHS=="od")
   {     
   }else if(LHS=="read")
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
   }else if(LHS=="end")
   {
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
      
      gen.emit2("READ", tempSizeRead);
      tempSizeRead = 0;
      
   }else
   {

   }
}
void Parse::VarAcList()//variable access list
{where="VAL";check();
   if(LHS=="id")
   {
      tempSizeRead++;
      tempSizeAsn++;
      VarAc();
      VarAcListB();
   }else
      errorReport();
}
void Parse::VarAcListB()//variable access list for iterations
{where="VALB";check();
   if(LHS==",")
   {
      tempSizeRead++;
      tempSizeAsn++;
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
      gen.emit2("WRITE", tempSizeWrite);
      tempSizeWrite = 0;
   }
}
void Parse::ExpList()//expression list
{where="EL";check();
   if(LHS!="-")
   {
      
      
   }
   tempSizeWrite++;
      Exp();
      ExpListB();
}
void Parse::ExpListB()//expression list for multiple iterations
{where="ELB";check();
   if(LHS==",")
   {
      tempSizeWrite++;
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
   gen.emit2("ASSIGN", tempSizeAsn);
   
   tempSizeAsn = 0;

}
void Parse::ProcStat()//procedure statement
{where="PS";check();
   if(LHS=="call")
   {
      match();      
      ProcName();
            if(!bTable.search(index))
	 scopeError("Procedure Not Defined in ProcStat");

      ent = bTable.find_all_level(index);
      //cout<<endl<<ln[tokeNum-1][0]<<", with label";
      //cout<<" "<<ent.procLabel<<", ";
      gen.emit3("CALL", bTable.loc(index), ent.procLabel);

      
   }
}
void Parse::IfStat()//if statements
{where="IS";check();

   match();
   int startL = newLabel(), doneL= newLabel(), pass1 = startL, pass2 = doneL;
   GarCmdList(pass1, pass2);
   gen.emit2("DEFADDR", startL);
   if(LHS=="fi")
   {
      gen.emit2("FI", ln[tokeNum][0]);
      match();
      gen.emit2("DEFADDR", doneL);
   }else
      errorReport();
}

void Parse::DoStat()//do statement
{where="DS";check();
   int startL = newLabel(), loopL= newLabel(), pass1 = startL, pass2 = loopL;
   
   match();
   gen.emit2("DEFADDR", loopL);
   GarCmdList(pass1, pass2);
   if(LHS=="od")
   {
      gen.emit2("OD", ln[tokeNum][0]);
      match();
       gen.emit2("DEFADDR", startL);
   }else
	 errorReport();
}

void Parse::GarCmdList(int &l1, int l2)//guarded command list
{where="GCL";check();
   
   GarCmd(l1, l2);
   GarCmdListB(l1, l2);
}
void Parse::GarCmdListB(int &l1, int l2)//guarded command list for multiple iterations
{where="GCLB";check();
   if(LHS=="["||LHS=="[]")
   {
      match();
      if(LHS=="]"||NS=="[]")
      {
	 match();
	 GarCmd(l1, l2);
	 GarCmdListB(l1, l2);
      }else
	 errorReport();
   }else
   {
      
   }
}

void Parse::GarCmd(int &l1, int l2)//guarded command
{where="GC";check();

   gen.emit2("DEFADDR", l1);
      Exp();
   l1 = newLabel();
   if(LHS=="->")
   {
      gen.emit2("ARROW", l1);
      match();
      StatPtr();
      gen.emit2("BAR", l2);
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
      gen.emit1("AND");
      match();
   }else if(LHS=="|")
   {
      gen.emit1("OR");
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
      gen.emit1("LESS");
      match();
   }else if(LHS=="=")
   {
      gen.emit1("EQUAL");
      match();
   }else if(LHS==">")
   {
      gen.emit1("GREATER");
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
      gen.emit1("ADD");
      match();
   }else if(LHS=="-")
   {
      gen.emit1("SUBTRACT");
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
      gen.emit1("TIMES");
      match();
   }else if(LHS=="%")
   {
      gen.emit1("MODULO");
      match();
   }else if(LHS=="/")
   {
      gen.emit1("DIVIDE");
      match();
   }else
      errorReport();
}
void Parse::Factor()//factor
{where="F";check();
   if(LHS=="num"||LHS=="false"||LHS=="true")
   {
      Const();
      gen.emit2("CONSTANT", tpVl);
      
   }else if(LHS=="id")
   {
      VarAc();
      gen.emit1("VALUE");
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
      gen.emit1("NOT");
      match();
      Factor();
   }else
      errorReport();
}
void Parse::VarAc()//Variable access
{where="Va";check();
   
   if(LHS=="id")
   {

      VarName();
      ent = bTable.find_all_level(index);
      //cout<<endl<<ent.disp<<endl;
      gen.emit3("VARIABLE", bTable.loc(index), ent.disp);
      //cout << endl << "index: "<< ent.idindex << endl << endl;
      if(!bTable.search(index))
	 scopeError("list Variable not Defined in VarAc");
      VarAcB();
      if(ary == 1)
      {
	 gen.emit3("INDEX", ent.size, ln[tokeNum][0]);
	 ary = 0;
      }
   }else
      errorReport();
}
void Parse::VarAcB()//variable access for mulitple iterations
{where="VAB";check();
   if(LHS=="[")
   {
      ary = 1;
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
   eKind = CONSTANT;
   if(LHS=="num")
   {  //
      eType = INT;
      
      Num();
  
   }else if(LHS=="true"||LHS=="false")
   {  //
      eType = BOOL;
      BoolSym();
   }else if(LHS=="id")
   {

      ConstName();
      tempEnt = bTable.find_all_level(index);
      tpVl = tempEnt.value;

      if(!bTable.inScope)
	 scopeError("Error, Variable not declared in scope");
   }else
      errorReport();
}
void Parse::BoolSym()//boolean symbol
{where="BS";check();
   if(LHS=="false")
   {  //calling to initialize val to 0 for the type
      checkVal = 0;
      varListVal[listDepth] = 0;
      tpVl=checkVal;
      //ctd
      match();
   }else if(LHS=="true")
   {  //calling to initialize val to 1 for the type
      checkVal = 1;
      varListVal[listDepth] = 1;
      tpVl=checkVal;
      //ctd
      match();
   }else
      errorReport();
}
void Parse::VarName()//variable name
{where="VN";check();
   if(LHS=="id")
   {  //initialise index
      //cout<<index;
      index = ln[tokeNum][1];
      match();
   }
}
void Parse::ConstName()//constant name
{where="CN";check();
   if(LHS=="id")
   {  //initialise index
      index=ln[tokeNum][1];
      //cout<<endl<<index<<"  "<<LHS<<"  "<<endl;
      match();
   }else
      errorReport();
}
void Parse::Num()//number
{where="N";check();
   if(LHS=="num")
   {  //initialise val of number
      //asnIndexVal(vl);
      checkVal=ln[tokeNum][2];
      tpVl=checkVal;
      //cout<<endl<<checkVal<<"  "<<LHS<<"  "<<endl;
      match();
   }else
      errorReport();
}
void Parse::ProcName()//procedure name
{where="PN";check();
   if(LHS=="id")
   {  //initialise index
      index = ln[tokeNum][1];
      match();
   }else
      errorReport();
}

//the parser code gen function(s)
int Parse::newLabel()
{
   label++;
   return label;
}
