%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "vala_interpreter_core.h"

  extern void lexer_error( char* );
%}

%%

\/\/.*$                 /* eat up one line comments */

[ \t\n]+                /* eat up whitespace */

.                       {
                          snprintf( errmsg, MAX_ERRMSG_LENGTH, "Unrecognized character \"%s\"", yytext );
                          lexer_error( errmsg );
                        }


%%

