Compiler Design project working on the language PL
Group: Navraj Saini and Jordan Kolody

Navraj: 
I started working on the project bottom up (building the symbol, token and symbol table) while Jordan worked top down (plc, admin, scanner). We both were able to finish our parts and I was able to work on testing the function while helping Jordan implement my sections into his part.

Jordan: 

Files included: 
administration.cpp, admininstration.h, scanner.h, 
scanner.cpp Makefile, Readme, symboltable.h, 
symboltable.cpp, token.h, token.cpp

To compile:
   
   The test program: make test

   The main program: make plc

The code has no compile time errors or any runtime errors. There are a few warnings that come up if -Wall -g is added to the Makefile, which are because the private variables are assigned after the public functions manipulate them or use them in some way.

Hours spent on this assignment:

     Navraj: 27

     Jordan: 30