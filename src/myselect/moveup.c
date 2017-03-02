#include "my_select.h"
/*
  Pre Cond: none
  Post Cond: move up by one if can't move up any further go to the last elem
 */
void moveup()
{
  refreshout(gl_env.pos);
  if((gl_env.pos -= 1) <0) 
    gl_env.pos = gl_env.nbelems-1;
  refreshin();
}


