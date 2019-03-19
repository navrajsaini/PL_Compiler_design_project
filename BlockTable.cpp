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
   
   else if (newBlock())
   {
      //create the Table entry
      TableEntry a;
      a.idindex = index;
      a.kind = nkind;
      a.type = ntype;
      a.size = nsize;
      a.value = nvalue;
      
      //push it to the new vector
      cout << "if there is a error it will be after this line...." << endl
	   << "the push_back function did not work properly." << endl;
      table[blockLevel].push_back(a);
      return true;
      /*
      table[blockLevel][0].idindex = index;
      table[blockLevel][0].kind = nkind;
      table[blockLevel][0].type = ntype;
      table[blockLevel][0].size = nsize;
      table[blockLevel][0].value = nvalue;
      return true;
      */
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
   cout << "in the endBlock function. " << endl
	<< "if there's a error,it will be in the next line. " << endl
	<< "I need to figure out how to erase the vector properly." << endl;
   //erase all entries in the current block
   table[blockLevel].erase(table[blockLevel].begin(), table[blockLevel].end());

   //if the blockLevel is greater than 0, decrement block
   if (blockLevel > 0)
      blockLevel--;
}
