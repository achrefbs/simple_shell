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

extern char **environ;
int _atoi(char *s);
void sig(int signal);
void rev_string(char *s);
void *_calloc(unsigned int size);
void function();
int int_len(int n);
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
void p_env(void);
char *_strcat(char *dest, char *src);
char *_getenv(char *path);
void error_msg(char *cmd, int i);
char* _itoa(int num, char* str);
#endif
