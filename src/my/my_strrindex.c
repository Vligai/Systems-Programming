#include "my.h"

/*
  pre cond: string and char
  post cond: return index of the LAST char in string
  ("HELLO", 'L') would return 3
*/

int my_strrindex(char *str, char c)
{
  int counter = 0;
  int rev = -1;
  if (str == NULL)
    {
      return -1;
    }
  else
    {
      while (str[counter] != '\0')
	{
	  if (str[counter] == c)
	    {
	      rev = counter;
	    }
	  counter ++;
	}
    }
  return rev;
}
