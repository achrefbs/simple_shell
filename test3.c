#include "simple_shell.h"
	int main()
	{
		char **s;
		int i = 0;
		s = handle_input();
		while (s[i] != NULL)
		{
			printf("s[%d] : %s\n",i,s[i]);
			i++;
		}
		return 0;
	}