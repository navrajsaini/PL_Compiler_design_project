#ifndef SYMBOL_H
#define SYMBOL_H

/*
  BY: Navraj Saini && Jordan Kolody
  
  enum symbol type for the terminal symbols of the language
  This will include the error handling and reporting symbols
  
  symbol.h
*/

using namespace std;

enum Symbol
{ID=256,                               //corosponding IDs
 NUM, BADNUM, BADNAME,                 //256-259
 NEWLINE, NONAME, ENDOFFILE, DIV,      //260-263
 MOD, SEMICOLON, PLUS, MINUS,          //264-267
 TIMES, DIVIDE, LEFTP, RIGHTP,         //268-271
 BADCHAR,                              //272
 //----------------reserved words-----------------
 begin, end, const1,                   //273-275
 array, integer, Boolean, proc,        //276-279
 skip, read, write, call, if1,         //280-284
 do1, fi, od, false1, true1,           //285-288

//--------------special symbols-------------------
 period, comma, rightB, leftB, and1, or1,
 not1, greater, less, equal, closedS, assign
};
#endif
