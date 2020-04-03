#include "simple_shell.h"
/**
*main - main function
*Return: Always 0
**/
int main(void)
{
    char *buffer;
    size_t bufsize = 256;
    size_t size;

    (void)size;

    buffer = malloc(sizeof(char) * bufsize);
    if( buffer == NULL)
    {
        free(buffer);
        exit(1);
    }

    _putchar('$');
    size = _getline(&buffer,&bufsize);


    
    
    free(buffer);
    return(0);
}