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

   char now[256] = " ";
   int i=0;
   input.open(in.c_str());
   input.getline(now,256);
   do
   {
   view.ahead=now[i+1];
   cout<<now[i]<<" "<<view.ahead<<endl;
   }while(view.ahead!='/n');
   //while(view.aheadChar!=EOF)
   //{   
   //}
   

   return 1;
}
