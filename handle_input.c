#include "simple_shell.h"
char **handle_input()
{
	char *line,*token, **str;
	int i = 0, s = 10, tlen;
	const char sep = ' ';

	line = malloc(sizeof(char) * 256);
	str = malloc(sizeof(char *) * s);
	_getline(line,STDIN_FILENO);

	token = _strtok(line, sep);
	tlen = _strlen(token);

	while (token != NULL)
	{
		str[i] = malloc(sizeof(char) * tlen + 1);
		_strcpy(str[i], token);
		token = _strtok(NULL, sep);
		tlen = _strlen(token);
		i++;
	}
	str[i] = NULL;
	free(line);
	return(str);

}