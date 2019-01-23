/*
  By: Navraj Saini && Jordan Kolody
  implements a symbol table with linear probe hashing
*/

#include <string>
#include <vector>
#include "token.h"
#define SYMTABLESIZE 307 //define the size to the next prime number after 300

using namespace std;

class Symtable
{
  public:
   //create a table the size of SYMTABLESIZE
  Symtable():occupied(0), htable(SYMTABLESIZE){}
   //ini the table with reserved words
   void loadResvd();
   //destructor
   ~Symtable();
   //search the htable for lexeme s, return the position if found, else -1
   int search (string);
   //insert a token with lexeme s in the symbol table. if already in the table
   //return its location. else create a token of appropriate type.
   //Insert the token and return its location.
   //------------might need to be modified later----------------
   int insert(string);
   //return true if table is full
   bool full(){return occupied == SYMTABLESIZE;}
   //return the number of occupied cells
   int getOC(){return occupied;}
   //print the table on standard output
   //only for debugging
   void printTable();

  private:
   vector<Token> htable;//the hashtable
   int occupied = 0;//number of cells occupied
   int hashfn(string);//hash function

};

#endif
