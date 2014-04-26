/*
 * This file contains the C-code for the parser_test program.
 * It can be used to test the parser.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vala_interpreter_core.h"
#include "lexer.yy.h"
#include "parser.h"

extern int yyparse( );

#define PROGRAM "parser_test - A testprogram for the vala_interpreter parser"

/* This variable will be returned by the check_file method and may be manipulated by the parser_error method. */
int parser_rc = 0;

/* The filename of the file which is currently checked. Will be set by the check_file method. */
char* current_file = NULL;

/**
 * This method will be called before the program stops.
 */
void shutdown( )
{
  fprintf( stderr, "Terminating %s %s\n", PROGRAM, VINTER_VERSION_SHORT );
}

void lexer_error( char* message )
{
  fprintf( stderr, "Error while checking file %s: %s at line %d!\n", current_file, message, yylineno );
  parser_rc = 2;
}

void parser_error( char* message )
{
  fprintf( stderr, "Error while checking file %s: %s at line %d!\n", current_file, message, yylineno );
  parser_rc = 2;
}

void yyerror( char* message )
{
  parser_error( message );
}

/**
 * This method will start the parser for the given file.
 * @param file A filename which should be processed by the parser.
 * @return 0 if no error occurs, != 0 if an error occurs.
 */
int check_file( char* file )
{
  int token;

  FILE* fin = fopen( file, "r" );
  parser_rc = 0;
  current_file = file;

  if ( fin == NULL )
  {
    snprintf( errmsg, MAX_ERRMSG_LENGTH, "Could not open input file %s", file );
    perror( errmsg );
    return 1;
  }

  yyin = fin;
  while ( !feof( yyin ) )
  {
    yyparse( );
  }

  fclose( fin );

  return parser_rc;
}

/**
 * The main method of the parser_test program
 * @param argc The number of arguments passed to the program
 * @param argv The arguments for the program
 * @return The exit code of the program (0 = ok, != 0 if an error occured)
 */
int main( int argc, char** argv )
{
  int file;
  int rc = 0;

  fprintf( stderr, "Starting %s %s\n", PROGRAM, VINTER_VERSION_SHORT );

  if ( argc == 1 )
  {
    fprintf( stderr, "No input file specified!\n" );
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

