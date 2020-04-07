#include "simple_shell.h"
/**
*main - main function
*Return: Always 0
**/
int main(void)
{
    char **str2 = NULL;

    str2 = malloc(sizeof(char *) * 100);
    if (str2 == NULL)
    return (0);

    
    while(1)
    {
        putchar('$');

        str2 = handle_input();

        execcmd(str2[0], str2);
    }
    
    return (EXIT_SUCCESS);
}
