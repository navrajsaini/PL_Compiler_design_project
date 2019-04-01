// drive.cc
//
// This is the main driver for the PL interpreter
//

// INCLUDES

#include <iostream>    // for cout, cin
#include <fstream>     // for ostream, istream
#include <string>        // for string
#include "interp.h"      // for Interpreter
using namespace std; 

// file_exists checks to see whether or not the specified file
// exists
bool file_exists( const char* filename);

// MAIN PROGRAM

int main( int argc, char* argv[])
//
// Description: The PL interpreter's main driver
// Call       : interpret [-s] <program_filename>
// Inputs     : argc - number of arguments given on the command line
//              argv - vector of the actual command-line arguments
// Outputs    : none
// Return     : Integer indicating ab/normal termination
//

{
  string program_filename; //PLAM instruction file
  bool stepping = false;   //for debugging purposes; use switch -s

 // INITIALIZATION

  if (argc == 2) // two arguments means no options specified
  {
  // Ensure that the actual file exists
    if ( !file_exists( argv[1]))
    {  
      cout << "Program file '" << argv[1] << "' does not exist \n" << endl;
      return 1;
    }
  else
     program_filename = argv[1];
  }

  else if ( argc == 3) // three args means an option was specified
  {
    if ( string("-s") == string(argv[1]))
    {
      stepping = true;
      // ensure that the specified file exists
      if (!file_exists( argv[2]))
      {
         cout << "Program file '" << argv[2]  
              << "' does not exist \n" << endl;
         return 1;
      }
      else
         program_filename = argv[2];
    }
    else // invalid command line
    {
      cout << "Usage: interpret [-s] <program_filename> \n" << endl;
      return 1;
    } 
  }
  // interpret code file specified on command-line
  Interpreter interpreter(program_filename, stepping);
} 


bool file_exists( const char* file_name)
{
  filebuf fb;
  if ( fb.open ( file_name, ios::in))
  {
    fb.close();
    return true;
  }
  else
    return false;
}
   

