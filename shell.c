#include "shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(int ac, char **av, char **en) 
{
	char *line, *cmd, **str, *div = " \t\r\n";
	int i, j;
	(void)ac;
	(void)av;
	
	while(1)
	{
		_putchar('$');
		_putchar(' ');

		line = _getline();
		str = split(line, div);
		free(line);

		if ((strcmp(str[0], "exit") == 0))
		{
			free(line);
			free(str);
			break;
		}
		if ((strcmp(str[0], "env") == 0))
		{
			for (j = 0; en[j] != NULL; j++)
        	printf("\n%s", en[j]);
		}
		cmd = path(str[0]);
		_exec(cmd, str);
		free(cmd);
		/**free**/
		for (i = 0;str[i] != NULL;i++)
		{
			free(str[i]);
		}
		free(str);
	}
	return(0);
}