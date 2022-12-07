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
		resultArray = malloc(17 * sizeof(char *));
		for (i = 0; i < 16; i++)
			resultArray[i] = NULL;
	}
	if (resultArray == NULL)
	{
		return (NULL);
	}
	resultArray[16] = line;
	curToken = _strcpy(strtok(line, delim));
	for (i = 0; curToken && i < 15; i++)
	{
		resultArray[i] = curToken;
		curToken = _strcpy(strtok(NULL, delim));
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
	char *testPath = NULL, *tempPath = NULL;

	result = (stat(tokens[0], &sb) == 0);
	if (result)
		return (result);
	path = getEnvVal("PATH");
	/*Add our program name to path */
	testPath = strtok(path, ":");
	do {
		if (testPath == NULL)
			break;
		/* Concat strings*/
		tempPath = _strcat(testPath, "/");
		testPath = _strcat(tempPath, tokens[0]);
		free(tempPath);
		/*Check and break if valid */
		if (stat(testPath, &sb) == 0)
		{
			free(tokens[0]);
			tokens[0] = testPath;
			free(path);
			return (1);
		}
		free(testPath);
	} while ((testPath = strtok(NULL, ":")));
	free(path);
	return (0);
}

/**
 * getEnvVal - get value from environ;
 * @valName: Name of value to find
 * Return: Value of ENV or null
 */

char *getEnvVal(char *valName)
{

	int valIndex = 0, charIndex = 0, nameLen = 0;

	while (valName[nameLen])
		nameLen++;

	for (; charIndex < nameLen && environ[valIndex];)
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
		return (_strcpy((environ[valIndex]) + nameLen + 1));
	return (NULL);
}
