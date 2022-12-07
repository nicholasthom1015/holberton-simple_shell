#include "shell_head.h"
#include "errno.h"
#include "sys/wait.h"
/**
 *Run_Command - Fork execution and run program
 *@argV: Null Terminated Array of arguments
 *
 *Return: 0 or fail
 */
int Run_Command(char **argV)
{
	pid_t childPID;
	int status;
	/* if passed NULL, Return -1 */
	if (argV == NULL || argV[0] == NULL)
		return (-1);
	childPID = fork();
	if (childPID == 0)
	{
		if (execve(argV[0], argV, NULL) == -1)
			exit(errno);
	}
	else
	{
		wait(&status);
	}
	return (0);

}
