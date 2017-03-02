#include "my.h"
/*
  pre cond: String and a char
  post cond: returns pointer to first iteration of the charachter
  in the string
*/

char *my_strfind(char *s, char c)
{
  int counter=0;
  if (s != NULL)
    {
      while (s[counter] != '\0')
	{
	  if (s[counter] == c)
	    {
	      return &s[counter];
	    }
	  counter++;
	}
    }
  return NULL;
}
