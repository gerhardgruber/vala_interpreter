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

#endif