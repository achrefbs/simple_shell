#include "simple_shell.h"
/**
*execcmd - execute the command
*@cmd: the command to execute
*@array: array to treat
**/
void execcmd(char *cmd, char **array)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid < 0)
	{
	perror("fail to execute");
	return;
	}
	else if (pid == 0)
	{
	if (execve(cmd, array, NULL) != 0)
	printf("Command Not Found!");
	}
	else
	{
	wait(&status);
	}
}
