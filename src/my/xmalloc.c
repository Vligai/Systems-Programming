#include "my.h"
/*
  pre cond: unsigned int
  post cond: allocates memory 
*/
void *xmalloc(unsigned int n)
{
  void *p = NULL;
  if(!(p=malloc(n)))
    {
      my_str("Virtual Memory Exhausted \n");
      exit(1);
    }
  return p;
}
