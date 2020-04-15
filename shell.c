#include "shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(void)
{
	char *line, *cmd = NULL, **str, *div = " ​\t\r\n\a\v​:", *err = NULL ,*err1;
	int i, status = 1, count = 0,le,ex = 0;

	signal(SIGINT, sig);/*disable ctrl-C */
	while (status)
	{
		count++;
		if (isatty(STDIN_FILENO))
		{
		_putchar('$');
		_putchar(' ');
		}
		fflush(stdin);
		line = _getline();
		if (!line)
		{
			continue;
		}
		str = split(line, div);
		free(line);
		if (str == NULL)
		continue;
		
		if ((_strcmp(str[0], "env") == 0))
		{
			for (i = 0; str[i] != NULL; i++)
			{
			free(str[i]);
			}
			free(str);
			p_env();
			continue;
		}
		if ((_strcmp(str[0], "exit") == 0))
		{
			if (str[1] != NULL)
			{
				ex = _atoi(str[1]);
			}
			
			for (i = 0; str[i] != NULL; i++)
			{
				free(str[i]);
			}
			free(str);
			exit(ex);
		}
		cmd = path(str[0]);
		status = _exec(cmd, str);
		if (status == -1)
		{
			le = int_len(count);
			err1 = _calloc(le + 1);
			err1 = _itoa(count,err1);
			err = _calloc(le + 11);
			_strcat(err,"./shell: ");
			_strcat(err,err1);
			perror(err);
			free(err);
			free(err1);
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
