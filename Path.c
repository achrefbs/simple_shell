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
	int x = 0, check, len, lencmd;

	if (stat(cmd, &st) == 0)
		return (cmd);
	else
	{
		full = (char **)malloc(20);
		if (full == NULL)
			return (NULL);
		path = getenv("PATH");

		len = strlen(path);
		_path = malloc(len + 1);
		strcpy(_path, path);

		/*_path = strdup(path);*/
		/*printf("paths = %s\n", _path);*/
		token = strtok(_path, ":");
		while (token)
		{
			/*printf("tokens = %s\n", token);*/
			full[x] = token;
			token = strtok(NULL, ":");
			x++;
		}
		full[x] = NULL;

		x = 0;
		while (full[x])
		{
			lencmd = _strlen(full[x]);
			new_cmd = malloc(lencmd + 1);
			new_cmd = strdup(full[x]);
			_strcat(new_cmd, "/");
			_strcat(new_cmd, cmd);
			/*printf("token[%d] = %s\n", x, new_cmd);*/
			check = stat(new_cmd, &st);
			if (check == 0)
			{
				free(_path);
				free(full);
				return (new_cmd);
			}
			free(new_cmd);
			x++;
		}
	}
	free(new_cmd);
	free(_path);
	free(full);
	return (NULL);
}
/*
int main(void)
{
	char *c = "cat", *r;
	while(1)
	{
		r = cmd_finder(c);
		printf("cmd = %s\n", r);
		free(r);
		sleep(3);
	}
	return (0);
}*/
