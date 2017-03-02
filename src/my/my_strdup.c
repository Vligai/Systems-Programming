#include "my.h"
/*
  pre cond: String
  post cond: duplicates a String in the allocated memory
*/
char *my_strdup(char* s)
{
  char *des = (char *)xmalloc((my_strlen(s)+1)*sizeof(char));
  if (s == NULL)
    {
      des = NULL;
      return des;
    }
  else
    {
      des = my_strcpy(des, s);
      des [my_strlen(s)] = '\0';
      return des;
    }

}
