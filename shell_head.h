#ifndef MY_SHELL_HEAD
#define MY_SHELL_HEAD
/* INCLUDES*/
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

/* STRUCTURES */



/* FUNCTIONS*/
char **Prep_Input(char *, char **);
char *_strcpy(char *dest, const char *src);
char *_strcat(char *dest, char *src);
char *getEnvVal(char *valName);
int Validate_Input(char **);
int Run_Command(char **);

#endif
