/*
 * This file contains the C-code for the lexer_test program.
 * It can be used to test the lexer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vala_interpreter_core.h"

#define PROGRAM "lexer_test - A testprogram for the vala_interpreter lexer"

/**
 * This method will be called before the program stops.
 */
void shutdown( )
{
  fprintf( stdout, "Terminating %s %s\n", PROGRAM, VINTER_VERSION_SHORT );
}

/**
 * The main method of the lexer_test program
 * @param argc The number of arguments passed to the program
 * @param argv The arguments for the program
 * @return The exit code of the program (0 = ok, != 0 if an error occured)
 */
int main( int argc, char** argv )
{
  fprintf( stdout, "Starting %s %s\n", PROGRAM, VINTER_VERSION_SHORT );

  if ( argc == 1 )
  {
    fprintf( stdout, "No input file specified!\n" );
    shutdown( );
    return 0;
  }



  shutdown( );
  return 0;
}