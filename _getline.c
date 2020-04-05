#include "simple_shell.h"
#include "leak_detector_c.h"

/**
*_getline - get the commend
*@lineptr: the commend
*@fd: the len
*Return: the len of the char
*/
int _getline(char *line,int fd)
{
	char buff[256];
	int rd;
	char *ptr;
	unsigned int len;

	if (line == NULL || fd == -1)
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

   _strcpy(line,buff); 
   return(len);
	
}	
