#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: move one left
*/
void moveleft()
{
  refreshout(gl_env.pos);
  if((gl_env.pos -= gl_env.win.ws_row) < 0)
    gl_env.pos = 0;
  refreshin();
}
