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
/*
char *_itoa(unsigned int n)
{
	int len = 0, i = 0;
	char *s;

	while (n / 10)
	{
		s[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}
	s[i] = (n % 10) + '0';
	rev_arr(s, len);
	s[i + 1] = '\0';
	return (s);
}*/

/**
 *reverse_array - reverse
 *@a : array
 *@n : integer
 *Return: 0
 */
/*void reverse_array(int *a, int n)
{
int i, c;
for (i = 0; (i < (n - 1) / 2); i++)
{
c = a[i];
a[i] = a[n - 1 - i];
a[n - 1 - i] = c;
}
}*/