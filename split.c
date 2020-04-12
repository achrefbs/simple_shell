#include "shell.h"
/**
*split - divide the buffer to small segment
*@buffer: the buffer to divide
*Return: return a string prepared for the exec
**/
char **split(char *line, char *div)
{
	char **buffer;
	char *token;
	int i = 0, len;
	if (line == NULL)
	{
		return(NULL);
	}
	
	buffer = malloc(sizeof(char *) * 256);
	if (buffer == NULL)
		exit(EXIT_FAILURE);
	token = strtok(line, div);
	while (token)
	{
		len = strlen(token);
		buffer[i] = malloc(sizeof(char) * len);
		strcpy(buffer[i], token);
		token = strtok(NULL, div);
		i++;
	}
	buffer[i] = NULL;

	return (buffer);
}