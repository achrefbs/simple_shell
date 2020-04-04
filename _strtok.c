#include <stdio.h>
#include "simple_shell.h"
#include<string.h>
/** in progress **/
char *_strtok(char *str, const char delim)
{
  static char *rest;
  char buff[256], *ptr;
  unsigned int len, lenptr;

  _strcpy(buff, str);
  if(str == NULL)
  {
    if(rest != NULL)
    _strcpy(str, rest);
    else
    return (NULL);
  }
  if(delim == '\0')
  return(NULL);

  len = _strlen(str);
  ptr = _strchr(str,delim);
  lenptr = _strlen(ptr);
  rest = substring(str, len - lenptr + 2, len);
  if (ptr)
  *ptr = '\0';
  len = _strlen(str);
  return str;

}
