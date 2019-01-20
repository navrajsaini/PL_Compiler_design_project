/*
  driver program
*/

#include <iostream>
#include <fstream>

using namespace std;

int main ()
{
   // variables for file names
   
   /*remove testLang.txt when project complete*/
   string CodeFileName = "testLang.txt", TokenFileName;

   //get the file name for input and then declare and open file
   cout<<"Welcome to compiler4600, please enter your code input file name: ";
   
   /*fix the commented out cin when complete */
   //cin>>CodeFileName;
   
   ifstream TokenFileIn, CodeFileIn.open(CodeFileName);

   //get the file name for output and then declare and open file
   cout<<endl<< "Now, please enter your scanner output file: ";
   
   /*fix the commented out cin when complete */
   //cin>>TokenFileName;
   
   ofstream TokenFileOut;

   cout<<endl;

   //creating a scanner
   
   /* remove comments for scanner when scanner complete */
   //Scanner 
   
   
   return 0;
}
