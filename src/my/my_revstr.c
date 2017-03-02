#include "my.h"

/*
  pre cond: string
  post cond: reverses given string and returns its length
*/

int my_revstr(char *s)
{
  unsigned int i; //counter
  char t;
  if (s == NULL)
    {
      return -1;
    }
  if(s[0] == '\0')
    {
      return 0;
    }
  else
    {
      for (i = 0; i < (my_strlen(s)/2); i++)
	{
	  t = s[i];
	  s[i] = s[my_strlen(s)-i-1];
	  s[my_strlen(s)-i-1] = t;
	}
    }
  return my_strlen(s);

}
