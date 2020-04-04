#include "simple_shell.h"
/**
*main - main function
*Return: Always 0
**/
int main(void)
{
	pid_t pid;
	int err, i = 0;
    char str[80], *str2[50], *token;

    
    token = strtok(str, " ");
    while(token != NULL)
    {
    /*printf("%s\n", token );*/
    _strcpy(str2[i], token);
    i++;
    token = strtok(NULL, " ");
    }
    putchar('$');
    

    while(_getline(str,STDIN_FILENO))
    {
        pid = fork();
        if (pid == -1)/*if the fork didnt work*/
		{
			perror("Error:");
			return (1);
		}
		if (pid == 0)/*this is the child*/
		{
            
            err = execv(str2[0],str2);
            if (err == -1)
            {
                perror("Error:");
                return (1);
            }
        }
        else/*this is the parent*/
		{   
			wait(NULL);
            
		}
    }

    return(0);
}
