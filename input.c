#include "shell_head.h"

char **Prep_Input(char *line, char **resultArray)
{
	char *curToken;
	char *delim = " \t\r\n";
	int i;


	if(resultArray == NULL)
		resultArray = malloc(16 * sizeof(char *));

	if (resultArray == NULL)
	{
		return (NULL);
	}
	curToken = strtok(line, delim);
        for (i = 0; curToken && i < 15; i++)
	{
		resultArray[i] = curToken;
		curToken = strtok(NULL, delim);
	}
	resultArray[i] = NULL;
        return(resultArray);
}

int Validate_Input(char **tokens)
{
	struct stat sb;
	int result;
	result = (stat(tokens[0], &sb) == 0);
	return (result);
}
