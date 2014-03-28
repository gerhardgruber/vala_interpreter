/*
 * This file contains the C-code for the vala_interpreter program.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vala_interpreter_core.h"

#define PROGRAM "vala_interpreter"

/**
 * The main method of the vala_interpreter program
 * @param argc The number of arguments passed to the program
 * @param argv The arguments for the program
 * @return The exit code of the program (0 = ok, != 0 if an error occured)
 */
int main( int argc, char** argv )
{
  fprintf( stdout, "Starting %s\n", PROGRAM );
  fprintf( stdout, "%s\n", VINTER_VERSION_LONG );
  return 0;
}
