#include "simple_shell.h"
/**
*main - main function
*Return: Always 0
**/
int main(void)
{
	char **str, *cmd;

	/*signal(SIGINT, SIG_IGN);  disable ctrl-C */

	while (1)
	{
	str = handle_input();
	cmd = cmd_finder(str[0]);
	execcmd(cmd, str);	
	free(str);
	free(cmd);
	}
	return (EXIT_SUCCESS);
}
