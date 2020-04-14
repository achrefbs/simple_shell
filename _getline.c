#include "shell.h"
/**
*_getline - read the input
*Return: The line readed
*/
char *_getline()
{
	int i, buffsize = 1024;
	char c = 0;
	char *buff = malloc(sizeof(char) * buffsize);

	if (buff == NULL)
	{
		return (NULL);
	}
	for (i = 0; c != EOF && c != '\n'; i++)
	{
		fflush(stdin);
		read(STDIN_FILENO, &c, 1);

		buff[i] = c;
		if (i >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1024);
			buffsize += 1024;
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[i - 1] = '\0';
	return (buff);
}
