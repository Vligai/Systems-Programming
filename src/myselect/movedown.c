#include "my_select.h"
/*
  Pre Cond: none
  Post Cond: move one down
*/
void movedown()
{
  refreshout(gl_env.pos);
  gl_env.pos += 1;
  gl_env.pos %=gl_env.nbelems;
  refreshin();
}
