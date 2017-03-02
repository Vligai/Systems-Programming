#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: move right by one, if nothing to the right move to the last elem
 */
void moveright()
{
  refreshout(gl_env.pos);
  if((gl_env.pos += gl_env.win.ws_row) >= gl_env.nbelems)
    gl_env.pos = gl_env.nbelems-1;
  refreshin();
}


