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
