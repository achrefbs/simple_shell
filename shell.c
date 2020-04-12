#include "shell.h"
/**
*main - tha main function
*Return: Always 0
*/
int main(void) 
{
	char *line, **str;
	int i;
	while(1)
	{
		_putchar('$');
		_putchar(' ');

		line = _getline();
		str = split(line);
		free(line);
		if ((strcmp(str[0], "exit") == 0))
			break;
		_exec(str[0],str);

		/**free**/
		for (i = 0;str[i] != NULL;i++)
		{
			free(str[i]);
		}
		free(str);
	}
	return(0);
}