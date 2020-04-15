#include "shell.h"
/**
*_exec - execute the command
*@cmd: the command
*@array: array holdin the argments
*Return: Return 0 in success
*/
int _exec(char *cmd, char **array)
{
	pid_t pid;
	int status;

	if (cmd == NULL || array == NULL)
		return (-1);

	pid = fork();
	if (pid < 0)
	{
		return (-1);
	}
	else if (pid == 0)
	{
<<<<<<< HEAD
		if (execve(cmd, array, NULL) != 0)
		return (-1);
=======
		if (execve(cmd, array, environ) != 0)
		{
			perror("fail to execute");
			return (-1);
		}
>>>>>>> 5ecdf12e13af41532a6a8c346f040dc18ef4e733
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	return (1);
}
