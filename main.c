#include "shell_head.h"

/**
 * main - Program Entry
 *
 *Return: 0 or error
 */
int main(void)
{
	pid_t myPID;
	pid_t childPID;
	char *rawInput = NULL;
	ssize_t readResult;
	size_t inputLen = 0;
        char **tokens = NULL;

	do
	{
		write(STDOUT_FILENO, "->::", 4);
		readResult = getline(&rawInput, &inputLen, stdin);
		if(!readResult > 0)
			break;
		tokens = Prep_Input(rawInput, tokens);
		if(tokens == NULL || tokens[0] == NULL)
		{
			continue;
		}

		if(Validate_Input(tokens))
			Run_Command(tokens);
        }while(readResult > 0);
	/* printf("Goodbye!\n"); */
	for (inputLen = 0; inputLen < 16; inputLen++)
		free(tokens[inputLen]);
	free(tokens);
	free(rawInput);
	return (0);
}
