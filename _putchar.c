#include "simple_shell.h"
#include <unistd.h>
/**
 * _putchar - writes the character c
 * @c: The character to print
 * Return: Always 0 (success)
 */
int _putchar(char c)
{
return (write(1, &c, 1));
}
