#include "shell_head.h"

/**
 * main - Program Entry
 * @argc: argc
 * @argv: argv
 *Return: 0 or error
 */
int main(__attribute__((unused))int argc, char **argv)
{
	char *rawInput = NULL;
	ssize_t readResult;
	size_t inputLen = 0;
	int inputType;
	char **tokens = NULL;

	do {
		if (isatty(0))
			write(STDOUT_FILENO, "->::", 4);
		readResult = getline(&rawInput, &inputLen, stdin);
		if (!(readResult > 0))
			break;
		tokens = Prep_Input(rawInput, tokens);
		if (tokens == NULL || tokens[0] == NULL)
		{
			continue;
		}
		inputType = Get_Command(tokens);
		if (inputType == 1)
			Run_Command(tokens);
		else if (inputType == 0)
		{
			printf("%s: No such file or directory\n", argv[0]);
		}
	} while (readResult > 0);
	/* printf("Goodbye!\n"); */
	for (inputLen = 0; inputLen < 17; inputLen++)
	{
		if (tokens[inputLen] != NULL)
		{
			free(tokens[inputLen]);
		}
	}
	free(tokens);
	return (0);
}
