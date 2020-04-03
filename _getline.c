#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

char *_strchr(char *s, char c);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

int _getline(char ** lineptr,int fd)
{
	static char buff[256];
	int rd;
	char *ptr;
	unsigned int len;

	if (lineptr == NULL || fd == -1)
	{
		return (-1);
	}
	
	rd = read(fd,buff,256);
	if (rd == -1)
	{
		return(-1);
	}


	ptr = _strchr(buff,'\n');   
   	if (ptr)
      *ptr = '\0';

   len = _strlen(buff);

   _strcpy(*lineptr,buff); 
   return(len);
	
}	

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

/**
 *_strlen - length of string
 *@s : string
 *Return: len
 */
int _strlen(char *s)
{
int i;
int c = 0;
for (i = 0; s[i] != '\0'; i++)
{
c++;
}
return (c);
}

/**
*_strcpy - copy a string
*@dest: string
*@src: string
*Return: 0
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