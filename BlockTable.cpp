/*
  created and edited by Navraj Saini and Jordan Kolody
  implementation for the BlockTable.h file
 */
#include "BlockTable.h"

BlockTable::BlockTable()
{
   
}

//search till the current block level if found, return true
//else return false
bool BlockTable::search(int index)
{
   for (int i = 0; i < blockLevel; i++)
   {
      if (table[i].index == index)
	 return true;
      else
	 return false;
   }
}

//search for the index, if it's found
//return false
//else insert in the new info and return true
//if a new block can be created and the index wasn't found
//insert into the new block that was created.
//and return true
bool BlockTable::define (int index, Kind nkind, myType ntype, int nsize, int nvalue)
{
   bool found;
   
   for (int i = 0; i < blockLevel; i++)
   {
      found = search (index);
      if (found == true)
	 return false;
   }
   
   if (newBlock())
   {
            
      table[blockLevel].idindex = index;
      table[blockLevel].kind = nkind;
      table[blockLevel].type = ntype;
      table[blockLevel].size = nsize;
      table[blockLevel].value = nvalue;
      return true;
   }
}
//search all the entries in the table
//if the index is found, return true and set error to false
//else error is set to true, and return false
TableEntry BlockTable::find (int index, bool &error)
{
   for (int i = 0; i < blockLevel; i++)
   {
      if (table[i].index == index)
      {
	 error = false;
	 return true;
      }
   }
   error = true;
   return false;
}

//if the current blockLevel+1 is greater then MAXBLOCK
//return false because no more blocks can be added in
//else
//increment the blockLevel
//and return true
bool BlockTable::newBlock()
{
   if(blockLevel+1 > MAXBLOCK)
      return false;
   else
   {
      blockLevel++;
      return true;
   }
}

void BlockTable::endBlock()
{
   
}
