#include "my.h"
/*
  pre cond: 2 Strings and unsigned int
  post cond: string comparison for the first n chars
  (<0 if s1<s2, >0 if s1>s2, 0 if s1=s2)
*/
int my_strncmp(char *s1, char *s2, unsigned int n)
{
  int counter = 0;
  if (s1 == NULL && s2 == NULL)
    {
      return 0;
    }
  if (s1 == NULL && s2 != NULL)
    {
      return -1;
    }
  if (s1 != NULL && s2 == NULL)
    {
      return 1;
    }
  else
    {
      while ((*s1 != '\0' || *s2 != '\0') && counter < n)
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
	  counter ++;
        }

      return 0;

    }

}
