#include "simple_shell.h"
/**
*main - main function
*Return: Always 0
**/
int main(void)
{
	char **str2 = NULL;
	signal(SIGINT,SIG_IGN); /* disable ctrl-C */

	while(1)
	{
		str2 = handle_input();
		execcmd(str2[0], str2);
	}

	return (EXIT_SUCCESS);
}
