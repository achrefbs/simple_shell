#include "shell.h"
/**
*split - divide the buffer to small segment
*@line: the buffer to divide
*@div: the character to split with
*Return: return a string prepared for the exec
**/
char **split(char *line, char *div)
{
	char **buffer;
	char *token;
	int i = 0, len;

	if (line == NULL)
	{
		return (NULL);
	}

	buffer = malloc(sizeof(char *) * 256);
	if (buffer == NULL)
		return (NULL);
	token = strtok(line, div);
	while (token)
	{
		len = strlen(token);
		buffer[i] = malloc(sizeof(char) * len);
		if (buffer[i] == NULL)
		return (NULL);
		strcpy(buffer[i], token);
		token = strtok(NULL, div);
		i++;
	}
	buffer[i] = NULL;
	return (buffer);
}
