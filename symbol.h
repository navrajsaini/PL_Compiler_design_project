/*
  BY: Navraj Saini && Jordan Kolody
  
  enum symbol type for the terminal symbols of the language
  This will include the error handling and reporting symbols
  
  symbol.h
 */

#ifndef SYMBOL_H
#define SYMBOL_H

using namespace std;

enum Symbol {ID=256,                               //corosponding IDs
	     NUM, BADNUM, BADNAME,                 //256-259
	     NEWLINE, NONAME, ENDOFFILE, DIV,      //260-263
	     MOD, SEMICOLON, PLUS, MINUS,          //264-267
	     TIMES, DIVIDE, LEFTP, RIGHTP,         //268-271
	     BADCHAR};                             //272
#endif
