#include "shell.h"
int _exec(char *cmd, char **array)
{
		pid_t pid;
		int status;
		if (cmd == NULL || array == NULL)
		{
			return -1;
		}
		pid = fork();
		if (pid < 0)
		{
			perror("fail to execute");
			return (-1);
		}
		else if (pid == 0)
		{
		if (execve(cmd, array, NULL) != 0)

			return(-1);
		}
		else
		{
			wait(&status);
		}
		return (1);
}