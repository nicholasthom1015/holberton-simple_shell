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
	printf("%lu\n", sizeof(struct stat));
	do
	{
		write(STDOUT_FILENO, "->::", 4);
		readResult = getline(&rawInput, &inputLen, stdin);
		if(!readResult > 0)
			break;
		tokens = Prep_Input(rawInput, tokens);
		if(tokens == NULL || tokens[0] == NULL)
		{
			write(STDOUT_FILENO, "Wo\n",3);
			continue;
		}

		if(Validate_Input(tokens))
			printf("JACKPOT!\n");
		else
			printf("Well it ran...\n");
	}while(readResult > 0);
	printf("Goodbye!\n");
	free(rawInput);
	return (0);
}
