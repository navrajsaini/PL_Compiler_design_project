/*
  created and edited by Navraj Saini and Jordan Kolody
  implementation for the BlockTable.h file
 */
#include "BlockTable.h"
BlockTable::BlockTable()
{
   //vector <vector<TableEntry>> blocktable[MAXBLOCK][table];
}
BlockTable::~BlockTable(){}
//search till the current block level if found, return true
//else return false
//commented out section is for a 2d array
bool BlockTable::search(int index)
{
   int temp;
   //remove this for look for a 2d array as we don't need to search
   //through all the blocks only the current block.
   //we need the for loop that is commented out
   for (int i = 0; i < blockLevel; i++)
   {
      //for (int j = 0; j < MAXBLOCK; j++)
      if (table[i][0].idindex == index)//table[blockLevel][j].idindex == index
	 return true;
   }
   return false;
}

//search for the index, if it's found
//return false
//else insert in the new info and return true
//if a new block can be created and the index wasn't found
//insert into the new block that was created.
//and return true
bool BlockTable::define (int index, Kind nkind, myType ntype, int nsize, string nvalue)
{
   if (search(index))
      return false;
   
   if (newBlock())
   {
      table[blockLevel][0].idindex = index;
      table[blockLevel][0].kind = nkind;
      table[blockLevel][0].type = ntype;
      table[blockLevel][0].size = nsize;
      table[blockLevel][0].value = nvalue;
      return true;
   }
}
//search all the entries in the table
//if the index is found, return true and set error to false
//else error is set to true, and return false
bool/*TableEntry*/ BlockTable::find (int index, bool &error)
{
   for (int i = 0; i < blockLevel; i++)
   {
      //for (int j = 0; j < MAXBLOCK; j++
      if (table[i][0].idindex == index)//table[i][j].idindex == index
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
   if (blockLevel != 0)
      if(blockLevel+1 > MAXBLOCK)
	 return false;
      else
      {
	 blockLevel++;
	 return true;
      }
   else
      return true;
}
//pop the current blocktable entry
//so index is set to "",
//kind and type are set to NULL,
//size is set to default, 1,
//value is set to 0
void BlockTable::endBlock()
{
   for (int i = 0; i < blockLevel; i++)
   {
      //for (int j = 0; j < MAXBLOCK; j++)
      //table[i][j]. ... = ...;
      table[i][0].idindex = 0;
      table[i][0].kind = UNDEFINED;
      table[i][0].type = UNIVERSAL;
      table[i][0].size = 1;
      table[i][0].value = "";
      blockLevel--;
   }
}
