//--------------------------------------------------
// interp.h
// Description	:	Translated from Brinch Hansens PL interpreter
//-------------------------------------------------------

#ifndef INTERP_H
#define INTERP_H

// INCLUDES

#include <string>
using namespace std;

// CONSTANTS

const int STORE_SIZE = 1000; // maximum size of storage

// ENUMERATTIONS

enum OperationCode
{
  OP_ADD, OP_AND, OP_ARROW, OP_ASSIGN, OP_BAR, OP_CALL, OP_CONSTANT,
  OP_DIVIDE, OP_ENDPROC, OP_ENDPROG, OP_EQUAL, OP_FI, OP_GREATER,
  OP_INDEX, OP_LESS, OP_MINUS, OP_MODULO, OP_MULTIPLY, OP_NOT,
  OP_OR, OP_PROC, OP_PROG, OP_READ, OP_SUBTRACT, OP_VALUE, OP_VARIABLE,
  OP_WRITE
};

// Messages

static const string opcode_name[] =
{
 "add", "and", "arrow", "assign", "bar", "call", "constant",
 "divide", "endproc", "endprog", "equal", "fi", "greater",
 "index", "less", "minus", "modulo", "multiply", "not",
 "or", "proc", "prog", "read", "subtract", "value",
 "variable", "write"
};

// CLASSES

class Interpreter
{
public:

    // CONSTRUCTION

    Interpreter(string, bool = false);

    // ACCESS

    void memory_dump(string) const;

private:
    void load_program( string);
    void run_program();
    void runtime_error(string, int = -1);
    void allocate( int );

    // PL MACHINE INSTRUCTION SET
    
    void variable(int, int);
    void index(int, int);

    void constant( int );
    void value();
    void plnot();

    void multiply();
    void divide();
    void modulo();

    void minus();
    void add();
    void subtract();

    void less();
    void equal();
    void greater();

    void pland(); 
    void plor(); 

    void read(int);    
    void write(int);

    void assign( int );
    
    void call( int, int);

    void arrow( int );
    void bar( int);
    void fi (int);

    void proc(int, int);
    void endproc();
  
    void prog( int, int);
    void endprog();

    // COMPONENTS

    int store[STORE_SIZE + 1]; // storage space
    int stack_bottom;          // bottom of the stack
    int stack_register,        // top of stack pointer (top)
        base_register,         // br
        program_register;      // pc

    bool running;              // status of the interpreter
    bool stepping;             // sets the step-by-step execution 
}; // end class Interpreter
#endif
// interp.h	
