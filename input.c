#include "shell_head.h"

char **Prep_Input(char *line)
{
	char **resultArray;
	char *curToken;
	char *delim = " \t\r\n";
	int i;

	resultArray = malloc(16 * sizeof(char *));
	if (!resultArray)
		return (NULL);
	curToken = strtok(line, delim);
        for (i = 0; curToken && i < 15; i++)
	{
		resultArray[i] = curToken;
		curToken = strtok(NULL, delim);
	}
	resultArray[i] = NULL;
        return(resultArray);
}
