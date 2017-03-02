#include "my.h"
/*
  pre cond: 2 Strings
  post cond: returns new string containing s1 followed by s2
*/
char *my_strconcat(char *s1, char *s2)
{
  int counter1=0;
  int counter2=0;
  char *s = (char*)xmalloc((my_strlen(s1)+my_strlen(s2)+1) * sizeof(char));
  
  if (s1 == NULL && s2 == NULL)
    return NULL;
  if (s1 == NULL && s2 != NULL)
    {
      s = my_strcpy(s, s2);
      return s;
    }
  if (s2 == NULL && s1 != NULL)
    {
      s = my_strcpy(s, s1);
      return s;
    }
  else
    
    {
      while(s1[counter1] != '\0')
	{
	  s[counter1] = s1[counter1];
	  counter1 ++;
	}
      while (s2[counter2] != '\0')
	{
	  s[counter1] = s2[counter2];
	  counter1 ++;
	  counter2 ++;
	}
    }
  s[counter1+counter2+1] = '\0';
  return s;
}
