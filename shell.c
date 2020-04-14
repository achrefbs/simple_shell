#include "shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(void)
{
	char *line, *cmd = NULL, **str, *div = " \t\r\n";
	int i, status = 1;

	/*signal(SIGINT, SIG_IGN);disable ctrl-C */
	while (status)
	{
		_putchar('$');
		_putchar(' ');
		fflush(stdin);
		line = _getline();
		str = split(line, div);
		free(line);
		if ((strcmp(str[0], "env") == 0))
			p_env();
		if ((strcmp(str[0], "exit") == 0))
		{
			for (i = 0; str[i] != NULL; i++)
			{
				free(str[i]);
			}
			free(str);
			exit(EXIT_SUCCESS);
		}
		cmd = path(str[0]);
		status = _exec(cmd, str);
		/**free**/
		for (i = 0; str[i] != NULL; i++)
		{
			free(str[i]);
		}
		free(str);
		free(cmd);
	}
	return (0);
}
