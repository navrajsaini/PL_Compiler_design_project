#include "BlockTable.h"

BlockTable::BlockTable()
{
   
}

bool BlockTable::search(int index)
{
   //search till the current block level if found, return true
   //else return false
   for (int i = 0; i < blockLevel; i++)
   {
      if (table[i].index == index)
	 return true;
      else
	 return false;
   }
}

bool BlockTable::define (int index, Kind nkind, myType ntype, int nsize, int nvalue)
{
   bool found;
   if (newBlock())//if we can create a new block
   {
      //search for the index, if it's found
      //return false
      //else insert in the new info and return true
      for (int i = 0; i < blockLevel; i++)
      {
	 //if (table[i].idindex == index)
	 //return false;
	 found = search (index);
	 if (found == true)
	    return false;
      }
      
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
