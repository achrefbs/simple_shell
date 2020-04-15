#include "shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(void)
{
	char *line, *cmd = NULL, **str, *div = " ​\t\r\n\a\v​:";
	int i, status = 1;

	signal(SIGINT, SIG_IGN);/*disable ctrl-C */
	while (status)
	{
		if (isatty(STDIN_FILENO))
		{
		_putchar('$');
		_putchar(' ');
		}
		fflush(stdin);
		line = _getline();	
		str = split(line, div);
		if (str == NULL)
		continue;
		free(line);
		if ((_strcmp(str[0], "env") == 0))
			p_env();
		if ((_strcmp(str[0], "exit") == 0))
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
		if (status == -1)
		{
			perror("./shell");
		}
		
		/**free**/
		for (i = 0; str[i] != NULL; i++)
		{
			free(str[i]);
		}
		free(str);
		free(cmd);
		if (!isatty(STDIN_FILENO))
		exit(0);
		
	}
	return (0);
}
