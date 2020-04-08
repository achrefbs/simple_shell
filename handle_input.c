#include "simple_shell.h"
char *clean_input(char *line,int len);
/**
*handle_input - treat the input
*Return: The array treated
**/
char **handle_input()
{
	char *line,*token, **str,*buffer;
	int i = 0, s = 10, tlen, ilen;
	const char sep = ' ';

	buffer = malloc(sizeof(char) * 256);
	_putchar('$');
	_putchar(' ');
	ilen = _getline(buffer,STDIN_FILENO);
	line = clean_input(buffer, ilen);
	free(buffer);
	str = malloc(sizeof(char *) * s);

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
char *clean_input(char *line,int len)
{
	int s,i,e = 0,blen;
	char *buffer ,*str ;
	buffer = malloc(sizeof(char) * len + 1);
	_strcpy(buffer,line);
	for (s = 0;buffer[s] == ' '; s++);
	for (i = len - 1; buffer[i] == ' '; i--)
		e++;
	buffer[len - e] = '\0';
	blen = _strlen(buffer);
	str = _substring(buffer,s + 1,blen);
	free(buffer);
	return(str);
}
