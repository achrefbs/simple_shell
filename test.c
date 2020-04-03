#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	char *test;
	int n = 256, c, fd;
	fd = open("AUTHORS",O_RDONLY);
	test = malloc(sizeof(char) * n);
	c = _getline(test,fd);
	printf("string is \"%s\"\nchars read : %d\n", test, c);	  
	free(test);
	return 0;
}