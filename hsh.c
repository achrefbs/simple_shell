#include "simple_shell.h"
/**
*main - main function
*Return: Always 0
**/
int main(void)
{
    int i = 0;
    char *sep = " \t\r\n\a", *token = NULL, **str2 = NULL;
    char *buffer;
    size_t bufsize = 20;

    buffer = malloc(sizeof(char) * 20);
    str2 = malloc(sizeof(char *) * 100);
    if (str2 == NULL)
    return (0);

    
    while(1)
    {
        putchar('$');
        getline(&buffer, &bufsize, stdin);
        token = strtok(buffer, sep);
        while(token != NULL)
        {
        str2[i] = token;
        i++;
        token = strtok(NULL, sep);
        }
        str2[i] = NULL;

        execcmd(str2[0], str2);
    }
    
    return (EXIT_SUCCESS);
}
