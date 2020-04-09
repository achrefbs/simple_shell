#include "simple_shell.h"
/**
*cmd_finder - cherche for the command location
*@cmd: the command to treat
*Return: The absolute path of the command
**/
char *cmd_finder(char *cmd)
{
	struct stat st;
	char *new_cmd =NULL, *token = NULL, *path = NULL, **full = NULL;
	int i, check;

	full = (char **)malloc(41);
	if (full == NULL)
	return ("-1");

	path = getenv("PATH");
	check = stat(cmd, &st);
	if (check == 0)
	{
		free(full);
		return (cmd);
	}
	i = 0;
	token = strtok(path, ":");
	while (token)
	{
		full[i] = token;
		token = strtok(NULL, ":");
		i++;
	}
	full[i] = NULL;

	i = 0;
	while (full)
	{
		new_cmd = strdup(full[i]);
		strcat(new_cmd, "/");
		strcat(new_cmd, cmd);

		check = stat(new_cmd, &st);
		if (check == 0)
			return (new_cmd);
		free(new_cmd);
		free(full);
		i++;
	}
	free(new_cmd);
	free(full);
	return (cmd);
}
/*
int main(void)
{
	char *c = "ls", *r;
	r = cmd_finder(c);
	printf("%s", r);
	free(r);
	return (0);
}*/