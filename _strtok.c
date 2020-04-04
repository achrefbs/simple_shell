#include <stdio.h>
#include "simple_shell.h"
#include<string.h>
/** in progress **/
char *_strtok(char *str, const char delim)
{
	static char *rest,  buff[256];
	char *ptr;
	unsigned int len, lenptr;

	if(delim == '\0')
	return(NULL);

	/** check if string is NULL then buffer will be the rest of the last called fucntion
		else buffer would be the input string**/
	if (str == NULL)
		_strcpy(buff,rest);
	else
		_strcpy(buff, str);

	len = _strlen(buff);

	/** ptr : pointer to the first occurrence of the delim in the string str **/
	ptr = _strchr(buff,delim);

		/** return the last token **/
		if (ptr == NULL)
		{
			return(buff);
		}

	lenptr = _strlen(ptr);

	/** rest will recieve the rest of the string after the first token **/
	rest = _substring(buff, len - lenptr + 2, len);

	/** replace delim with an empty character to end the string (buffer) **/
	if (ptr)
		*ptr = '\0';

	return (buff);
}
/**
 * _substring - find substring of a string 
 * @position : the start of the substring
 * @length : the end of the string
 * Retrun : pointer to substring
 */

char *_substring(char *string, int position, int length)
{
	char *pointer;
	int c;
	
	pointer = malloc(length + 1);
	
	if (pointer == NULL)
	{
		return (NULL);
	}

	for (c = 0 ; c < length ; c++)
	{
		*(pointer + c) = *(string + position - 1);
		string++;  
	}

	*(pointer + c) = '\0';
	
	return (pointer);
}