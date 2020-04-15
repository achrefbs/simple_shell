#include "shell.h"
/**
*p_env - print the envirment variables
**/
void p_env(void)
{
	size_t i;
	int len;

	for (i = 0; environ[i] != NULL; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		_putchar('\n');
	}
}

/**
**_strcat - concatenate 2 strings
*@dest : string
*@src : string
*Return: 0
*/
char *_strcat(char *dest, char *src)
{
	int i, j;

	for (i = 0; dest[i] != '\0'; i++)
	;

	for (j = 0; src[j] != '\0'; j++)
	dest[i + j] = src[j];

	dest[i + j] = '\0';
	return (dest);
}
