#include "shell_head.h"
#include "errno.h"
#include "sys/wait.h"

int Run_Command(char **argV)
{
	pid_t childPID;
	/* if passed NULL, Return -1 */
	if (argV == NULL || argV[0] == NULL)
		return (-1);
	childPID = fork();
	if(childPID == 0)
	{
		if (execve(argV[0], argV, NULL) == -1)
		exit(errno);
	}
	else
	{
		waitpid(childPID, NULL, WNOHANG | WUNTRACED);
	}
	return (0);

}
