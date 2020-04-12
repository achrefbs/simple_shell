#include "shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(void) 
{
	char *line, *cmd, **str, *div = " \t\r\n";
	int i;
	
	while(1)
	{
		_putchar('$');
		_putchar(' ');
		fflush(stdin);
		line = _getline();
		str = split(line, div);
		if ((strcmp(str[0], "env") == 0))
			p_env();
		if ((strcmp(str[0], "exit") == 0))
		{
			for (i = 0;str[i] != NULL;i++)
			{
				free(str[i]);
			}
			free(str);
			exit(EXIT_SUCCESS);
		}
		cmd = path(str[0]);
		_exec(cmd, str);
		/**free**/
		for (i = 0;str[i] != NULL;i++)
		{
			free(str[i]);
		}
		free(line);
		free(cmd);
		free(str);
	}
	return(0);
}