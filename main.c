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
	char **tokens = NULL;

	do {
		write(STDOUT_FILENO, "->::", 4);
		readResult = getline(&rawInput, &inputLen, stdin);
		if (!(readResult > 0))
			break;
		tokens = Prep_Input(rawInput, tokens);
		if (tokens == NULL || tokens[0] == NULL)
		{
			continue;
		}

		if (Validate_Input(tokens))
			Run_Command(tokens);
		else
		{
			printf("%s: No such file or description\n", argv[0]);
		}
	} while (readResult > 0);
	/* printf("Goodbye!\n"); */
	if (tokens)
	{
		free(tokens);
	}
	if (rawInput)
		free(rawInput);
	return (0);
}
