#include "my.h"
/*
  pre cond: 2 Strings and unsigned int
  post cond: copies first n characters on src to dest and return dest
*/
char *my_strncpy (char *dst, char *src, unsigned int n)
{
  int counter = 0;
  if (dst != NULL && src == NULL)
    return dst;
  if (dst == NULL)
    return NULL;  
  else
    {
      while (src[counter] != '\0' && counter < n)
	{
	  dst[counter] = src[counter];
	  counter ++;
	}
      dst[counter] = '\0';
    }
  return dst;
}
