/*
 * This header file contains some declarations used by the most source files of the vala_interpreter.
 */

#ifndef VALA_INTERPRETER_CORE_H
#define VALA_INTERPRETER_CORE_H 1

#define TRUE 1
#define FALSE 0

#define VINTER_VERSION_SHORT "version 1.0"
#define VINTER_VERSION_LONG "The amazing vala interpreter, version 1.0"

/* Maximum length of error messages */
#define MAX_ERRMSG_LENGTH 2048

/* This string can be used to temporarily store error messages */
char errmsg[ MAX_ERRMSG_LENGTH ];

/* String-Representation of the tokens. */
#define STRING_TOKEN_IDENTIFIER         "identifier"
#define STRING_TOKEN_DECIMAL_NUMBER     "decimal_number"
#define STRING_TOKEN_HEXADECIMAL_NUMBER "hexadecimal_number"
#define STRING_TOKEN_BOOLEAN_TRUE       "true"
#define STRING_TOKEN_BOOLEAN_FALSE      "false"
#define STRING_TOKEN_SEMICOLON          "semicolon"
#define STRING_TOKEN_STRING             "string"
#define STRING_TOKEN_TYPE               "type"
#define STRING_TOKEN_NULL_VALUE         "null"
#define STRING_TOKEN_PAREN_OPEN         "("
#define STRING_TOKEN_PAREN_CLOSE        ")"
#define STRING_TOKEN_BRACE_OPEN         "{"
#define STRING_TOKEN_BRACE_CLOSE        "}"
#define STRING_TOKEN_OP_PLUS            "+"
#define STRING_TOKEN_OP_MINUS           "-"
#define STRING_TOKEN_OP_MULTIPLY        "*"
#define STRING_TOKEN_OP_DIVIDE          "/"
#define STRING_TOKEN_OP_NOT             "!"
#define STRING_TOKEN_OP_AND             "&&"
#define STRING_TOKEN_OP_OR              "||"
#define STRING_TOKEN_COMMA              ","
#define STRING_TOKEN_IF                 "if"
#define STRING_TOKEN_ELSE               "else"
#define STRING_TOKEN_WHILE              "while"
#define STRING_TOKEN_UNKNOWN            "unknown"


#endif