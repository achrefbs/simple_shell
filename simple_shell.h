#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

/*headers*/

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*prototypes*/

int _getline(char *lineptr,int fd);
char *_strchr(char *s, char c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strtok(char *str, const char delim);
char *_substring(char *string, int position, int length);

/*structs*/




#endif