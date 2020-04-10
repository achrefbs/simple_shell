#include "simple_shell.h"
/**
*cmd_finder - cherche for the command location
*@cmd: the command to treat
*Return: The absolute path of the command
**/
char *cmd_finder(char *cmd)
{
	struct stat st;
	char *new_cmd = NULL, *token = NULL, *path = NULL, *_path = NULL, **full = NULL;
	int i = 0, x = 0, check;

	if (stat(cmd, &st) == 0)
		return (cmd);
	else
	{
		full = (char **)malloc(20);
		if (full == NULL)
			return (NULL);
		path = getenv("PATH");
		_path = strdup(path);
		/*printf("paths = %s\n", _path);*/
		token = strtok(_path, ":");
		i = 0;
		while (token)
		{
			/*printf("tokens = %s\n", token);*/
			full[i] = token;
			token = strtok(NULL, ":");
			i++;
		}
		full[i] = NULL;

		x = 0;
		while (full[x])
		{
			new_cmd = strdup(full[x]);
			strcat(new_cmd, "/");
			strcat(new_cmd, cmd);
			/*printf("token[%d] = %s\n", x,new_cmd);*/
			check = stat(new_cmd, &st);
			if (check == 0)
			{
				free(full);
				return (new_cmd);
			}
			free(new_cmd);
			x++;
		}
	}
	free(full);
	return (NULL);
}
/*
int main(void)
{
	char *c = "ls", *r;
	while(1)
	{
		r = cmd_finder(c);
		printf("cmd = %s\n", r);
		free(r);
		sleep(3);
	}
	return (0);
}*/
