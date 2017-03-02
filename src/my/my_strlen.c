#include "my.h"

/*
  pre cond: string
  post cond: returns length of that string
*/

int my_strlen(char *s)
{
  int counter = 0;
  if (s == NULL)
    {
      return -1;
    }
  if (s[0] == '\0')
    {
      return 0;
    }
  else{
    while(s[counter] != '\0')
      {
	counter = counter + 1;
      }
  }
  return counter;
}
