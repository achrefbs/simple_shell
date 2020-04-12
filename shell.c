#include "shell.h"
int main(void) {
  char *line,**str;
  int i;
  while(1){
  _putchar('$');
  line = _getline();
  str = split(line);
  free(line);
  _exec(str[0],str);

  /**free**/
  for (i = 0;str[i] != NULL;i++)
  {
    free(str[i]);
  }
    free(str);
  }
  return(0);
}