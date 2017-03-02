#include "my.h"
/*
  pre cond: 2 Strings
  post cond: copies from src to dst and returns dst
*/
char *my_strcpy(char *dst, char *src)
{
  int counter = 0;
  if (dst == NULL)
    return NULL;
  if (src == NULL)
    return dst;
  else
    {
      while(src[counter] != '\0')
	{
	  dst[counter] = src[counter];
	  counter ++;
	}
      dst[counter] = '\0';
    }
  return dst;
}
