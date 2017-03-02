#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: turn curson off
*/
void term_vi()
{
    tputs(gl_env.cursoroff, 1, my_termprint);
}
