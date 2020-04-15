#include "shell.h"
/**
 * _getenv - function to get enviroment variable by name
 * @name: name of the variable
 * Return: Return a pointer
 */

char *_getenv(char *name)
{
	char **env, *c, *_name;

	env = environ;
	while (*env != NULL)
	{
		for (c = *env, _name = name; *c == *_name; c++, _name++)
		{
			if (*c == '=')
				break;
		}
		if ((*c == '=') && (*_name == '\0'))
			return (c + 1);
		env++;
	}
	return (NULL);
}
/**
 **_calloc - a function that allocates memory for an array, using malloc.
 *@nmemb : int
 *@size : int
 *Return: pointer to an array
 */
void *_calloc(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}