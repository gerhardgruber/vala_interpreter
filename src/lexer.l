%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "vala_interpreter_core.h"
  #include "parser.h"

  extern void lexer_error( char* );
%}

line_comment        \/\/.*$
whitespace          [ \t\n]
identifier          [a-z][a-zA-Z_0-9]*
hex_digit           [0-9a-fA-F]
digits              [0-9]*
digit_without_zero  [1-9]
type                (uint8|int8|uint16|int16|uint32|int32|uint64|int64|uint|int|ulong|long|uchar|char|unichar|string|void)

/* States */
%x IN_COMMENT

%option yylineno
%%

-?0x{hex_digit}+                return HEXADECIMAL_NUMBER;
-?{digit_without_zero}{digits}  return DECIMAL_NUMBER;

true                            return BOOLEAN_TRUE;
false                           return BOOLEAN_FALSE;

\"(\\.|[^"])*\"                 return STRING;

{type}                          return TYPE;

null                            return NULL_VALUE;

"("                             return PAREN_OPEN;
")"                             return PAREN_CLOSE;

"+"                             return OP_PLUS;
"-"                             return OP_MINUS;
"*"                             return OP_MULTIPLY;
"/"                             return OP_DIVIDE;

"!"                             return OP_NOT;
"&&"                            return OP_AND;
"||"                            return OP_OR;

","                             return COMMA;
;                               return SEMICOLON;

if                              return IF;
else                            return ELSE;
while                           return WHILE;

{identifier}                    return IDENTIFIER;

"/*"                            { BEGIN( IN_COMMENT ); }
<IN_COMMENT>"*/"                { BEGIN( INITIAL ); }
<IN_COMMENT>.                   { } /* eat up commented character */
<IN_COMMENT>\n                  { } /* eat up commented character */
{line_comment}                  /* eat up one line comments */

{whitespace}                    /* eat up whitespace */

.                               {
                                  snprintf( errmsg, MAX_ERRMSG_LENGTH, "Unrecognized character \"%s\"", yytext );
                                  lexer_error( errmsg );
                                }


%%

