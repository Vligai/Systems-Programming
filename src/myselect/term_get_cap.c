#include "my_select.h"
/*
  Pre Cond: char* 
  Post Cond: get cap
*/
char* term_get_cap(char *c)
{ 
  char *s;
  char ar[2048];
  if ((s = tgetstr(c, (char**)&ar)) == NULL)
    my_panic("invalid input", 1);
  return s;
}
