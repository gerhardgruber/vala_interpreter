%token	IDENTIFIER DECIMAL_NUMBER HEXADECIMAL_NUMBER BOOLEAN_TRUE BOOLEAN_FALSE SEMICOLON STRING TYPE NULL_VALUE
%token  PAREN_OPEN PAREN_CLOSE BRACE_OPEN BRACE_CLOSE OP_PLUS OP_MINUS OP_MULTIPLY OP_DIVIDE OP_NOT OP_AND OP_OR COMMA
%token  IF ELSE WHILE
%start	Program

%{
  extern int yylex( );
  extern void yyerror( const char* );
%}

%%

Expression: IDENTIFIER ;

Method_Declaration: TYPE IDENTIFIER PAREN_OPEN PAREN_CLOSE Block ;

BlockCode:          /* empty */
                    | BlockCode Block
                    | BlockCode Expression ;

Block:              BRACE_OPEN BlockCode BRACE_CLOSE ;

Program:	/* empty */
          | Program Block
          | Program Method_Declaration ;
          /*
          | Program Statement
          | Program Method_Declaration ;
          */

%%

