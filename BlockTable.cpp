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
   int tempcomp;//temp variable for comparison done in if block
   for (int i = 0; i < blockLevel; i++)
   {
      for (vector<TableEntry>::iterator j = table[i].begin();
	   j != table[i].end(); ++j)
      {
	 cout << "searching: the idindex is: " << i -> idindex << endl;
	 /*
	 cout << "in search function. if there's a issue after this" << endl
	      << "j -> idindex does not place the first member in the struct"
	      << endl << "to tempcomp..... idindex: "
	      << j->idindex << endl;*/
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
   bool error, newblock_ret;
   TableEntry findtable, a;
   // I will be manipulating findtable for the code generation part.
   //don't need to do anything with it for now.
   findtable = find (index, error);
   if (error)
   {
      cout << "error is true..." << endl;
      return false;
   }
   else
   {/*
      cout << "in the define func, if there's a error after this line..."
	   << endl << "I need to find a better way to assign the stuff..."
	   << endl;*/
      
      //create the Table entry
      a.idindex = index;
      a.kind = nkind;
      a.type = ntype;
      a.size = nsize;
      a.value = nvalue;
      
      //push it to the new vector
      /*cout << "if there is a error it will be after this line...." << endl
	<< "then blockLevel shouldn't be blockLevel-1..." << endl;*/
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
   /*cout << "in find function. if there are any issues here..." << endl
	<< "the comparison or the for loop are not working properly."
	<< endl << endl;*/
   //for (vector<TableEntry>::iterator j = table[blockLevel].begin();
//	j != table[blockLevel].end(); ++j)
   for (int i = 0; i < table[blockLevel].size(); i++)
   {
      cout << endl << table[blockLevel][i].idindex << " " << index << endl;
      if (table[blockLevel][i].idindex == index)
      {
	 cout << "done with find func" << endl;
	 
	 error = true;
	 inScope = true;
	 a.idindex = table[blockLevel][i].idindex;
	 a.kind = table[blockLevel][i].kind;
	 a.type = table[blockLevel][i].type;
	 a.size = table[blockLevel][i].size;
	 a.value = table[blockLevel][i].value;
	 
	 return a;
      }
   }
   cout << "done with find func, couldn't find it" << endl;
   a.idindex = index;
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
   cout << "making a new block..." << endl << endl;
   if(blockLevel+1 > MAXBLOCK)//check if blockLevel+1 is > 10
      return false;
   else//if it isn't increment blockLevel and return true
   {
      blockLevel++;
      /*cout << endl << "newBlock, blockLevel: " << blockLevel << endl << endl;*/
      return true;
   }
}

//pop the current blocktable entry
//so index is set to "",
//kind and type are set to NULL,
//size is set to default, 1,
//value is set to 0
void BlockTable::endBlock()
{/*
   cout << "in the endBlock function. " << endl
	<< "if there's a error,it will be in the next line. " << endl
	<< "I need to figure out how to erase the vector properly." << endl;
	cout << "printing the table before deleting it..." << endl;*/
   printtable();
   //erase all entries in the current block
   table[blockLevel].erase(table[blockLevel].begin(), table[blockLevel].end());
   if (blockLevel > -1)
      blockLevel--;
   else
      ;
   cout << "done with endBlock" << endl;
}

void BlockTable::printtable()
{
   /*cout << "printtable, blockLevel: " << blockLevel << endl;*/
   int ind = 0;
   for (int i = 0; i <= blockLevel; i++)
   {
      for (vector<TableEntry>::iterator j = table[i].begin();
	   j != table[i].end(); ++j)
      {
	 cout << "location: " << ind << endl
	      << "   index: " << j -> idindex << endl
	      << "   kind: " << j -> kind << endl
	      << "   type: " << j -> type << endl
	      << "   size: " << j -> size << endl
	      << "   value: " << j -> value << endl;
	 ind++;
      }
   }
   cout << "done with printtable" << endl;
}
