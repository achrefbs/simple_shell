#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
int main()
{
	char *test;
	int n = 256, c;
	test = malloc(sizeof(char) * n);
	c = _getline(&test,fileno(stdout));
	printf("string is \"%s\"\nchars read : %d\n", test, c);
  	free(test);
	return 0;
}