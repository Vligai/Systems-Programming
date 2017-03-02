#include "my_select.h"
/*
  Pre Cond: int 
  Post Cond: print terminal
 */
int my_termprint(int c)
{
  return write(1, &c, 1);
}
