#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <string.h>
char *_which(char *filename);
int main(int ac, char **av, char **env)
{
    //char *args[] = {"/bin/ls", "-lRa", "/home/yurei/shell/simple_shell", NULL};
    //struct stat st;


    pid_t pid;
    int stats, i = 0;
    char *sep = " \t\r\n\a", *token = NULL, **str2 = NULL;
    char *buffer;
    size_t bufsize = 20;
    buffer = malloc(bufsize * sizeof(char));

    char *cmd;

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
        printf("%s\n", token );
        str2[i] = token;
        i++;
        token = strtok(NULL, sep);
        }
        str2[i] = NULL;

        cmd = _which(str2[0]);

        pid = fork();
        if (pid < 0)
        {
            break;
        }
        else if (pid == 0)
        {
            execve(cmd, str2, env);
        }
        else
        {
            wait(&stats);
        }
    }
    free(str2);
    free(buffer);
    return (EXIT_SUCCESS);
}

char* path_finder(char *cmd)
{
    
}
