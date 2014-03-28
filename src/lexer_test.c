/*
 * This file contains the C-code for the lexer_test program.
 * It can be used to test the lexer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vala_interpreter_core.h"
#include "lexer.yy.h"

#define PROGRAM "lexer_test - A testprogram for the vala_interpreter lexer"

/* This variable will be returned by the check_file method an may be manipulated by the lexer_error method. */
int lexer_rc = 0;

/* The filename of the file which is currently checked. Will be set by the check_file method. */
char* current_file = NULL;

/**
 * This method will be called before the program stops.
 */
void shutdown( )
{
  fprintf( stdout, "Terminating %s %s\n", PROGRAM, VINTER_VERSION_SHORT );
}

void lexer_error( char* message )
{
  fprintf( stderr, "Error while checking file %s: %s at line %d!\n", current_file, message, yylineno );
  lexer_rc = 2;
}

/**
 * This method will start the lexer for the given file.
 * @param file A filename which should be processed by the lexer.
 * @return 0 if no error occurs, != 0 if an error occurs.
 */
int check_file( char* file )
{
  FILE* fin = fopen( file, "r" );
  lexer_rc = 0;
  current_file = file;

  if ( fin == NULL )
  {
    snprintf( errmsg, MAX_ERRMSG_LENGTH, "Could not open input file %s", file );
    perror( errmsg );
    return 1;
  }

  yyin = fin;
  yylex( );

  fclose( fin );

  return lexer_rc;
}

/**
 * The main method of the lexer_test program
 * @param argc The number of arguments passed to the program
 * @param argv The arguments for the program
 * @return The exit code of the program (0 = ok, != 0 if an error occured)
 */
int main( int argc, char** argv )
{
  int file;
  int rc = 0;

  fprintf( stdout, "Starting %s %s\n", PROGRAM, VINTER_VERSION_SHORT );

  if ( argc == 1 )
  {
    fprintf( stdout, "No input file specified!\n" );
    shutdown( );
    return 0;
  }

  for ( file = 1; file < argc; file ++ )
  {
    int check_rc = check_file( argv[ file ] );
    if ( check_rc > rc )
    {
      rc = check_rc;
    }
  }

  shutdown( );
  return rc;
}

