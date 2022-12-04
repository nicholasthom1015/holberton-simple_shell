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
	char *path = NULL;
	char *testPath = NULL;

	result = (stat(tokens[0], &sb) == 0);
	if (result)
		return (result);
	path = getEnvVal("PATH");
        path = _strcpy(NULL, path);
	/*Add our program name to path */
	testPath = strtok(path, ":");
	do
	{
		if (testPath == NULL)
			break;
		/* Concat strings*/
		testPath = _strcat(testPath, tokens[0]);
		/*Check and break if valid */
		if (stat(testPath, &sb) == 0)
		{
			tokens[0] = testPath;
			free(path);
			return (1);
		}
	}while (testPath = strtok(NULL, ":"));
	free(path);
	return (0);
}

/**
 * getEnvVal - get value from environ;
 * @valName: Name of value to find
 *Return Value of ENV or null
 */

char *getEnvVal(char *valName)
{

	extern char **environ;
	char *result = NULL;
	int valIndex = 0, charIndex = 0, nameLen = 0;

	while(valName[nameLen])
		nameLen++;

	for(valIndex, charIndex;charIndex < nameLen && environ[valIndex];)
	{
		if (environ[valIndex][nameLen] != '=')
		{
			valIndex++;
			continue;
		}
		if (environ[valIndex][charIndex] == valName[charIndex])
		{
			charIndex++;
			continue;
		}
		else
		{
			charIndex = 0;
			valIndex++;
			continue;
		}
	}
	if (environ[valIndex])
		return ((environ[valIndex]) + nameLen + 1);
	return (NULL);
}
