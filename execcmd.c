#include "simple_shell.h"
/**
*
*
**/
void execcmd(char *cmd, char **array)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid < 0)
    {
        perror("fail to execute");
        return;
    }
    else if (pid == 0)
    {
        execve(cmd, array, NULL);
    }
    else
    {
        wait(&status);
    }
}