#ifndef _SIMPLE_SHELL_H_
#define _SIMPLE_SHELL_H_

#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_getline();
int _strcmp(char *s1, char *s2);
char *_strcpy(char *dest, char *src);
int _strlen(char *s);
char *_strchr(char *s, char c);
int _putchar(char c);
char *_substring(char *string, int position, int length);
char **split(char *line, char *div);
int _exec(char *cmd, char **array);
char *path(char *cmd);

#endif
