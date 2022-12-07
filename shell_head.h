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


/**
 *struct builtIn - Hold function and name
 *@opName: String name of Builtin
 *@f: Method to run builtin
 */
typedef struct builtIn
{
	char *opName;
	int (*f)(char **);
} builtIn;

/* EXTERN */
extern char **environ;
/* FUNCTIONS*/
char **Prep_Input(char *, char **);
char *_strcpy(const char *src);
char *_strcat(char *dest, char *src);
char *getEnvVal(char *valName);
int Validate_Input(char **);
int Run_Command(char **);
int Get_Command(char **);
int myexit(char **);
int printEnv(char **);


#endif
