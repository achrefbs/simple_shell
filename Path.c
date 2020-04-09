#include "simple_shell.h"
/**
*cmd_finder - cherche for the command location
*@cmd: the command to treat
*Return: The absolute path of the command
**/
char *cmd_finder(char *cmd)
{
	struct stat st;
	char *new_cmd, *token, *path, **full = NULL;
	int i, check;

	full = (char **)malloc(256);
	if (full == NULL)
	return ("-1");

	path = getenv("PATH");
	check = stat(cmd, &st);
	if (check == 0)
	return (cmd);

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
		i++;
	}
	free(full);
	return (cmd);
}
