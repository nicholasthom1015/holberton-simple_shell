#ifndef MY_SHELL_HEAD
#define MY_SHELL_HEAD
/* INCLUDES*/

#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURES */



/* FUNCTIONS*/
char **Get_Input();
int Validate_Input (char **);
int Run_Command (char **);

#endif
