#include "shell_head.h"

/**
 * **Prep_Input - prepares input for shell
 * @line: length of string
 * @resultArray: buffer to store the result
 * Return: result of array
 */

char **Prep_Input(char *line, char **resultArray)
{
	char *curToken;
	char *delim = " \t\r\n";
	int i;


	if (resultArray == NULL)
	{
		resultArray = malloc(16 * sizeof(char *));
		for (i = 0; i < 16; i++)
			resultArray[i] = NULL;
	}
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
	return (resultArray);
}
/**
 * Validate_Input - validates input for shell
 * @tokens: tokens
 * Return: result
 */

int Validate_Input(char **tokens)
{
	struct stat sb;
	int result;

	result = (stat(tokens[0], &sb) == 0);
	return (result);
}
