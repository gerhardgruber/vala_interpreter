/*
 * This file contains the C-code for the lexer_test program.
 * It can be used to test the lexer.
 */

#include <stdio.h>
#include <stdlib.h>
#include "vala_interpreter_core.h"
#include "lexer.yy.h"
#include "parser.h"

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
  fprintf( stderr, "Terminating %s %s\n", PROGRAM, VINTER_VERSION_SHORT );
}

void lexer_error( char* message )
{
  fprintf( stderr, "Error while checking file %s: %s at line %d!\n", current_file, message, yylineno );
  lexer_rc = 2;
}

/**
 * This method will return the string representation of the given token.
 * It will use the STRING_TOKEN_... defines from the vala_interpreter_core header file.
 * @param token The integer value of a token (one of the defines from the parser.h file).
 * @return The string representation of the given token.
 */
const char* token_to_string( int token )
{
  switch( token )
  {
    case IDENTIFIER:
      return STRING_TOKEN_IDENTIFIER;
    case DECIMAL_NUMBER:
      return STRING_TOKEN_DECIMAL_NUMBER;
    case HEXADECIMAL_NUMBER:
      return STRING_TOKEN_HEXADECIMAL_NUMBER;
    case BOOLEAN_TRUE:
      return STRING_TOKEN_BOOLEAN_TRUE;
    case BOOLEAN_FALSE:
      return STRING_TOKEN_BOOLEAN_FALSE;
    case SEMICOLON:
      return STRING_TOKEN_SEMICOLON;
    case STRING:
      return STRING_TOKEN_STRING;
    case TYPE:
      return STRING_TOKEN_TYPE;
    case NULL_VALUE:
      return STRING_TOKEN_NULL_VALUE;
    case PAREN_OPEN:
      return STRING_TOKEN_PAREN_OPEN;
    case PAREN_CLOSE:
      return STRING_TOKEN_PAREN_CLOSE;
    case OP_PLUS:
      return STRING_TOKEN_OP_PLUS;
    case OP_MINUS:
      return STRING_TOKEN_OP_MINUS;
    case OP_MULTIPLY:
      return STRING_TOKEN_OP_MULTIPLY;
    case OP_DIVIDE:
      return STRING_TOKEN_OP_DIVIDE;
    case OP_NOT:
      return STRING_TOKEN_OP_NOT;
    case OP_AND:
      return STRING_TOKEN_OP_AND;
    case OP_OR:
      return STRING_TOKEN_OP_OR;
    case COMMA:
      return STRING_TOKEN_COMMA;
    case IF:
      return STRING_TOKEN_IF;
    case ELSE:
      return STRING_TOKEN_ELSE;
    case WHILE:
      return STRING_TOKEN_WHILE;
    default:
      return STRING_TOKEN_UNKNOWN;
  }
}

/**
 * This method will start the lexer for the given file.
 * @param file A filename which should be processed by the lexer.
 * @return 0 if no error occurs, != 0 if an error occurs.
 */
int check_file( char* file )
{
  int token;

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
  while ( ( token = yylex( ) ) != 0 )
  {
    fprintf( stdout, "%s\n", token_to_string( token ) );
  }

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

