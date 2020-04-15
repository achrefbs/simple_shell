#include "shell.h"
void sig(int signal)
{
	if (signal == SIGINT)
	{
		_putchar('\n');
		_putchar('$');
		_putchar(' ');
	}
	
}