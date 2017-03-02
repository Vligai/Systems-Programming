#include "my.h"
/*
   pre cond: 2 Strings
   post cond: string comparison (<0 if s1<s2; >0 if s1>s2; 0 if s1=s2)
*/
int my_strcmp(char *s1, char *s2)
{
  if (s1 == NULL && s2 == NULL)
    {
      return 0;
    }
  if (s1 == NULL && s2 != NULL)
    {
      return -1;
    }
  if (s2 == NULL && s1 != NULL)
    {
      return 1;   
    }
  else
    {
      while (*s1 != '\0' || *s2 != '\0')
	{
	  if (*s1 > *s2)
	    {
	      return 1;
	    }
	  else if (*s1 < *s2)
	    {
	      return -1;
	    }
	  s1++;
	  s2++;
	}
     
      return 0;
    }
  
}
