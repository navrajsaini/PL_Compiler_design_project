// BlockTable class interface.  BlockTable is used to keep track of object
// definition information within blocks.

#ifndef BLOCKTABLE_H
#define BLOCKTABLE_H
#include <vector>
#include <string>
#include <iostream>
#include "types.h"

using namespace std;
// Constant block table size limit.
#define MAXBLOCK 10

// Our compiler is fairly simple so this is all we need to store for every
// possible type. 
typedef struct {
      int idindex;//scanner hash table index of the object 
      Kind kind;  // object Kind
      myType type; // object type (integer, boolean)
      int size;    // single variable size = 1; for arrays the value in [] 
      string value;   // value of named constants  
} TableEntry;

class BlockTable {
  public:
   BlockTable();
   ~BlockTable();
   // Returns true when index is found in current block, false when not.
   bool search(int index);
   // Inserts a TableEntry with the given field values in parameters. 
   // Returns true when successful, false when previously defined (ambiguous)
   bool define(int index, Kind nkind, myType ntype, int nsize,
	       string nvalue);
   // true when found, false when not in the entire block table
   TableEntry find(int index, bool &error);
   // true when new block created, false when over MAXBLOCK
   bool newBlock();
   void endBlock();
  private:
   // Use an array of vectors for the block table.
   vector<TableEntry> table[MAXBLOCK];
   // Keep track of the current block level.
   int blockLevel = 0;
   int vecloc = 0;
};
#endif
