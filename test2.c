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
    (void)ac;
    (void)av;
    //char *args[] = {"/bin/ls", "-lRa", "/home/yurei/shell/simple_shell", NULL};

    pid_t pid;
    int stats, i = 0;
    char *sep = " \t\r\n\a", *token = NULL, **str2 = NULL;
    char *buffer;
    size_t bufsize = 20;
    buffer = malloc(bufsize * sizeof(char));


    while(getline(&buffer, &bufsize, stdin))
    {
        //printf("buffer = %s", buffer);
        //printf("len of buffer = %ld\n", strlen(buffer) - 1);

        str2 = malloc(sizeof(char *) * 64);
        if (str2 == NULL)
		return (0);

        token = strtok(buffer, sep);
        while(token != NULL)
        {
        //printf("%s\n", token );
        str2[i] = token;
        i++;
        token = strtok(NULL, sep);
        }
        str2[i] = NULL;


        pid = fork();
        if (pid == 0)
        {
            execve(str2[0], str2, env);
        }
        else if (pid > 0)
        {
            wait(&stats);
        }
    }
    free(str2);
    free(buffer);
    return (0);
}
