/*
  created and edited by Navraj Saini and Jordan Kolody
  implementation for the BlockTable.h file
*/
#include "BlockTable.h"

//constructor
BlockTable::BlockTable()
{}

//destructor
BlockTable::~BlockTable(){}

//search till the current block level
//if found, return true, else return false
bool BlockTable::search(int index)
{
   int tempcomp;//temp variable for comparison done in if block
   for (int i = 0; i <= blockLevel; i++)
   {
      for(int j = 0; j < table[i].size(); j++)
      {
	 tempcomp = table[i][j].idindex;
	 if (tempcomp == index)//the comparison that tempcomp is needed for
	 {
	    return true;
	 }
      }
   }
   return false;
}

//search for the index, if it's found
//return false
//else insert in the new info and return true
//if a new block can be created and the index wasn't found
//insert into the new block that was created.
//and return true
bool BlockTable::define (int index, Kind nkind, myType ntype, int nsize, int nvalue, int disp)
{
   bool error, newblock_ret;
   TableEntry findtable, a;
   // I will be manipulating findtable for the code generation part.
   //don't need to do anything with it for now.
   findtable = find (index, error);
   if (error)
   {
      return false;
   }
   else
   {
      //create the Table entry
      a.idindex = index;
      a.kind = nkind;
      a.type = ntype;
      a.size = nsize;
      a.value = nvalue;
      a.disp = disp;
      //push it to the new vector
      table[blockLevel].push_back(a);
      return true;
   }
}

//search all the entries in the table
//if the index is found, return it's location and
// set error to false
//else error is set to true
TableEntry BlockTable::find (int index, bool &error)
{   
   TableEntry a;
   for (int i = 0; i < table[blockLevel].size(); i++)
   {
      if (table[blockLevel][i].idindex == index)
      {
	 error = true;
	 inScope = true;
	 a.idindex = table[blockLevel][i].idindex;
	 a.kind = table[blockLevel][i].kind;
	 a.type = table[blockLevel][i].type;
	 a.size = table[blockLevel][i].size;
	 a.value = table[blockLevel][i].value;
	 a.disp = table[blockLevel][i].disp;
	 return a;
      }
   }
   a.idindex = index;
   a.size = 1;
   error = false;
   inScope = false;
   return a;
}

//if the current blockLevel+1 is greater then MAXBLOCK
//return false because no more blocks can be added in
//else
//increment the blockLevel
//and return true
//blockLevel start's at -1, that way we don't have to worry
//about starting from 1 insead of 0.
bool BlockTable::newBlock()
{
   if(blockLevel+1 > MAXBLOCK)//check if blockLevel+1 is > 10
      return false;
   else//if it isn't increment blockLevel and return true
   {
      blockLevel++;
      return true;
   }
}

//pop the current blocktable entry
//so index is set to "",
//kind and type are set to NULL,
//size is set to default, 1,
//value is set to 0
void BlockTable::endBlock()
{
   //erase all entries in the current block
   table[blockLevel].erase(table[blockLevel].begin(), table[blockLevel].end());
   if (blockLevel > -1)
      blockLevel--;
   else
      ;
}

void BlockTable::printtable()
{
   int ind = 0;
   cout << "blockLevel: " << blockLevel+1 << endl;
   for (vector<TableEntry>::iterator j = table[blockLevel].begin();
	j != table[blockLevel].end(); ++j)
   {
      cout << "location: " << ind+1 << endl
	   << "   index: " << j -> idindex << endl
	   << "   kind: " << j -> kind << endl
	   << "   type: " << j -> type << endl
	   << "   size: " << j -> size << endl
	   << "   value: " << j -> value << endl
	   << "   disp: " << j -> disp << endl;
      ind++;
   }
}
