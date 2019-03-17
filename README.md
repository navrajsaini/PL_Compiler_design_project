Compiler Design project working on the language PL
Group: Navraj Saini and Jordan Kolody
--------------------------------------SCANNER------------------------------------------------------

Navraj: 
I started working on the project bottom up (building the symbol, token and symbol table) while Jordan worked top down (plc, admin, scanner). We both were able to finish our parts and I was able to work on testing the function while helping Jordan implement my sections into his part.

Jordan:
I began my journey in the main of plc. I finnished formatting plc correctly and then when onto fry bigger fish. The creation of admin and scanner was my focus following plc. From there i began creating each of the functions of Admin, and Scannner. Then intergrated them in the time that followed. The final piece of the puzzle was tokenLine and getToken. These two functions required the most focus as sorting symbols from numerics from names was a challange late into the night. The next proccess included intergrating with raj's functions. Once these were done some polish was lightly applied to functions lacking. At last i removed most of my debuging lines and raj and i's project was packaged for submition.

Files included: 
administration.cpp, admininstration.h, scanner.h, 
scanner.cpp Makefile, Readme, symboltable.h, 
symboltable.cpp, token.h, token.cpp

To compile:
   
   The test program: make test. 
      
   The main program: make plc

The code has no compile time errors or any runtime errors. There are a few warnings that come up if -Wall -g is added to the Makefile, which are because the private variables are assigned after the public functions manipulate them or use them in some way.

Hours spent on this assignment:

     Navraj: 27

     Jordan: 30

--------------------------------PARSER------------------------------------------

Navraj:
I was under the assumption the project was due on the 5th, not the 3rd. Under that assumption I was unable to help with some of the stuff Jordan was working on. I was able to fix the hash function to work better and a few other issues from the scanner. For the parser I created the .h file and added in the functions that needed to be implemented. Majority of the work for the Parser was done by Jordan. I was able to make sure any and all issues he had with the scanner, on my part, were fixed. This included adding a function for the returning the token name based on the value (location) of the token in the symbol table, fixing the insert function in symbol table as it kept breaking, and making other miscellaneous changes to token.cpp and symboltable.cpp.

Jordan:
Long days and plesant nights of coding resulted in a compleate parser function. The work started when I fixed some of the issues I knew had carried over from the Scanner section. Once those pesky deficiencies were looked at I stepped up and the parser stepped down into my care. I worked on her through the night. Since my last week was filled with midterms and asignments time was limited untill the weekend hit. There was a bit of a struggle getting the Line numbers over to Parser, but after I paresed out the issue, it came down to the bottem line. It was time to Finnish the Parser. I created each of the grammar rules on cue cards for easy reading and then did the same with the first sets. Error checking came quick while I was writing the grammar out. The last bit was some reformating of the errorReport function. At the end, I sit hear on the precipce of compleating this assignment with tired eyes and a hungry stomach quite satisfied in the work that has been done. 

Files included: 
administration.cpp, admininstration.h, scanner.h, 
scanner.cpp Makefile, Readme, symboltable.h, 
symboltable.cpp, token.h, token.cpp, parser.h, 
parser.cpp

To compile:

   The test program: make test
   
            The test file is created for the purpose of testing the functions in the scanner and the parser.
            It can also be used to test all the testlang files (test1-test7) in one run.
            Once those files complete the testLang files is run once. 
            It is the only files that does not contain errors.

   The main program: make plc
    
The code has no compile time errors or any runtime errors.

Hours spent on this assignment:

     Navraj: 11

     Jordan: 25
-----------------------------------------------Scope and Type Checking--------------------------------------------

Navraj:

Jordan:

Files included: 
administration.cpp, admininstration.h, scanner.h, 
scanner.cpp Makefile, Readme, symboltable.h, 
symboltable.cpp, token.h, token.cpp, parser.h, 
parser.cpp, types.h, BlockTable.h, BlockTable.cpp

To compile:

   make plc
   
The code has no compile time errors or any runtime errors.

Hours spent on this assignment:

      Navraj: 
   
      Jordan: 
