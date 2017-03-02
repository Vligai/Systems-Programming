#include "my.h"

/*
  pre cond: 2 Strings
  post cond: copies s2 at the end of s1
*/

char *my_strcat(char *s1, char *s2)
{
  unsigned int counter1 = 0;
  unsigned int counter2 = my_strlen(s1);
  if(s1 == NULL && s2 == NULL||
     s1 == NULL && s2 != NULL||
     s1 != NULL && s2 == NULL)
    {
      return s1;
    }
  else
    {
      while (s2[counter1] != '\0')
	{
	  s1[counter1+counter2] = s2 [counter1];
	  counter1 ++;
	}
      s1[counter1 + counter2] = '\0';
    }
  return s1;

}
