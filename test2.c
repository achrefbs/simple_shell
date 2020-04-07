#include "simple_shell.h"
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>

int main(int ac, char **av, char **env)
{
    //char *args[] = {"/bin/ls", "-lRa", "/home/yurei/shell/simple_shell", NULL};
    //struct stat st;


    
    int i = 0;
    char *sep = " \t\r\n\a", *token = NULL, **str2 = NULL;
    char *buffer;
    size_t bufsize = 20;
    buffer = malloc(bufsize * sizeof(char));

    (void)ac;
    (void)av;
    (void)env;

    str2 = malloc(sizeof(char *) * 100);
    if (str2 == NULL)
    return (0);



    //write(STDOUT_FILENO, "$", 2);
    while(getline(&buffer, &bufsize, stdin))
    {
        //printf("buffer = %s", buffer);
        //printf("len of buffer = %ld\n", strlen(buffer) - 1);

        token = strtok(buffer, sep);
        while(token != NULL)
        {
        //printf("%s\n", token );
        str2[i] = token;
        i++;
        token = strtok(NULL, sep);
        }
        str2[i] = NULL;

        execcmd(str2[0], str2);
    }
    free(str2);
    free(buffer);
    return (EXIT_SUCCESS);
}
/*
char* path_finder(char *cmd)
{
    
}*/

