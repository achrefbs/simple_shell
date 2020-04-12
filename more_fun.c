#include "shell.h"
extern char** environ;
/**
*p_env - print the envirment variables
**/
void p_env(void)
{
	for (size_t i = 0; environ[i] != NULL; i++)
	{
    	printf("%s\n", environ[i]);
	}
}
