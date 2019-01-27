/*
  provide services that are nto directly related to compiler phases.
  admininstration.cpp
 */
#include "administration.h"
#include <fstream>
#include <iostream>

using namespace std;

Admin::Admin(string inFile, string outFile, Scanner &sn)
{
   in = inFile;
   out = outFile;
   //scnr = &scan;
}



int Admin::scan()
{
   char now[256];
   input.open(in.c_str());

   //cout<<now[i]<<" "<<view.ahead<<endl;
   do{
      //clearing the array of characters
      for(int j=0;j<255;j++)
	 now[j]=' ';  
      input.getline(now,256);
      
      view.tokenLine(now, 256);
     
      
      
   }while(!input.eof());
   //{   
   //}
   

   return 1;
}
