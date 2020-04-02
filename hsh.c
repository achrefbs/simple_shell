#include "simple_shell.h"
/**
*
*
**/
int main(void)
{
    char *buffer;
    size_t bufsize = 32;
    size_t size;

    (void)size;

    buffer = malloc(sizeof(char) * bufsize);
    if( buffer == NULL)
    {
        free(buffer);
        exit(1);
    }

    _putchar('$');
    size = getline(&buffer,&bufsize,stdin);

    
    
    
    return(0);
}