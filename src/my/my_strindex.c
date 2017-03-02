#include "my.h"

/*
  pre cond: string and char
  post cond: returns index of the FIRST found char in the string
  ("HELLO", 'L') would return 2
  special cond: 1 parse
*/

int my_strindex (char *s, char ch)
{
  int counter = 0;
  if (s == NULL)
    {
      return -1;
    }
  else
    {
      while (s[counter] != '\0')
	{
	  if(s[counter] == ch)
	    {
	      return counter;
	    }
	  counter ++;
	}
    }
  return -1;
}

