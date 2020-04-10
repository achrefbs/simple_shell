#include "simple_shell.h"
#include "leak_detector_c.h"

/**
 **_strchr - a function that locates a character in a string.
 *@s : pointer
 *@c : char
 *Return: 0
*/
char *_strchr(char *s, char c)
{
	for (; *s != c && *s != '\0'; s++)
	;
	if (*s == c)
		return (s);
	else
		return (NULL);
}

/********************************************/

/**
 *_strlen - length of string
 *@s : string
 *Return: len
 */
int _strlen(char *s)
{
int i;
int c = 0;
if (s == NULL)
	return (0);
for (i = 0; s[i] != '\0'; i++)
{
	c++;
}
	return (c);
}

/********************************************/

/**
 *_strcpy - copy a string
 *@dest: string
 *@src: string
 *Return: copied string
*/
char *_strcpy(char *dest, char *src)
{
int i;
for (i = 0; src[i] != '\0'; i++)
{
dest[i] = src[i];
}
if (dest[i] != '\0')
dest[i] = '\0';
return (dest);
}

/********************************************/

/**
 * _putchar - writes the character c
 * @c: The character to print
 * Return: Always 0 (success)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
*_strdup - returns a pointer to newly allocated space in memory
*@str: the string source
*Return: the string destination
*/
char *_strdup(char *str)
{
	int i = 0;
	char *ing;
	char *temp;

	if (str == NULL)
		return (NULL);
	while (str[i])
		i++;
	ing = malloc(i + 1);
	temp = ing;
	if (ing == NULL)
		return (NULL);
	while (*str)
		*temp++ = *str++;
	*temp = '\0';
	return (ing);
	free(ing);
}


/**
*_strcat - concatinates two strings
*@dest: destination
*@src: source
*Return: the string d + s
*/
char *_strcat(char *dest, char *src)
{
	int i = 0, length = 0;

	while (dest[length] != '\0')
		length++;
	while (src[i] != '\0')
	{
		dest[length] = src[i];
		i++;
		length++;
	}
	return (dest);
}