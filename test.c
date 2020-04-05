#include "simple_shell.h"
#include "leak_detector_c.h"
int main()
{
	char line[256], *token;
	_getline(line ,STDIN_FILENO);
	printf("%s\n",line);
	token = _strtok(line,' ');
	printf("token : %s\n",token);
	atexit(report_mem_leak);
	return 0;
}