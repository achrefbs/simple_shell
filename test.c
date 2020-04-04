#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char *test, *token;
	int n = 256, c, fd;
	test = malloc(sizeof(char) * n);
	c = _getline(test,STDIN_FILENO);
	printf("string is \"%s\"\nchars read : %d\n", test, c);
	token = _strtok(test, ' ');
	printf("this is a token : %s\n",token);
	token = _strtok(NULL, ' ');
	printf("this is a token 2 : %s\n",token);
	free(test);
	return 0;
}