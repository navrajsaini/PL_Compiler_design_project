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
//commented out section is for a 2d array
bool BlockTable::search(int index)
{
   /*
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
   */
   
   int tempcomp;//temp variable for comparison done in if block
   for (int i = 0; i < blockLevel; i++)
   {
      for (vector<TableEntry>::iterator j = table[blockLevel].begin();
	   j != table[blockLevel].end(); ++j)
      {
	 cout << "in search function. if there's a issue after this" << endl
	      << "j -> idindex does not place the first member in the struct"
	      << endl << "to tempcomp.....";
	 tempcomp = j->idindex;
	 if (tempcomp == index)//the comparison that tempcomp is needed for
	 {
	    cout << "done with search funciton" <<endl;
	    return true;
	 }
      }
   }
   cout << "done with search func" << endl;
   return false;
}

//search for the index, if it's found
//return false
//else insert in the new info and return true
//if a new block can be created and the index wasn't found
//insert into the new block that was created.
//and return true
bool BlockTable::define (int index, Kind nkind, myType ntype, int nsize, int nvalue)
{
   bool error;
   TableEntry findtable, a;
   // I will be manipulating findtable for the code generation part.
   //don't need to do anything with it for now.
   findtable = find (index, error);
   if (error)
      return false;
   
   else if (newBlock())
   {
      cout << "in the define func, if there's a error after this line..."
	   << endl << "I need to find a better way to assign the stuff..."
	   << endl;
      //create the Table entry
      
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
   else
   {
      cout << "no more space in the BlockTable" << endl;
      return false;
   }
}

//search all the entries in the table
//if the index is found, return it's location and
// set error to false
//else error is set to true
TableEntry BlockTable::find (int index, bool &error)
{   
   TableEntry a;
   cout << "in find function. if there are any issues here..." << endl
	<< "the comparison or the for loop are not working properly."
	<< endl;
   for (auto j = table[blockLevel].begin();
	j != table[blockLevel].end(); ++j)
   {
      if (j -> idindex == index)
      {
	 cout << "done with find func" << endl;
	 error = false;
	 
	 a.idindex = j -> idindex;
	 a.kind = j -> kind;
	 a.type = j -> type;
	 a.size = j -> size;
	 a.value = j -> value;
	 
	 return a;
      }
   }
   cout << "done with find func" << endl;
   a.idindex = 0;
   a.kind = UNDEFINED;
   a.type = UNIVERSAL;
   a.size = 1;
   a.value = 0;
   error = true;
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
   cout << "in the endBlock function. " << endl
	<< "if there's a error,it will be in the next line. " << endl
	<< "I need to figure out how to erase the vector properly." << endl;
   //erase all entries in the current block
   table[blockLevel].erase(table[blockLevel].begin(), table[blockLevel].end());
   if (blockLevel > -1)
      blockLevel--;
   else
      ;
   cout << "done with endBlock" << endl;
}
