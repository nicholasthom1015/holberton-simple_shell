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
        char **tokens;

	do
	{
		readResult = getline(&rawInput, &inputLen, stdin);
		tokens = Prep_Input(rawInput);
		if(tokens == NULL || tokens[0] == NULL)
			continue;
		printf("%s\n",tokens[0]);
	}while(readResult > 0);
	printf("Goodbye!\n");
	return (0);
}
