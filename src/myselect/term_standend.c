#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: highlight
 */
void term_standend()
{
  tputs(gl_env.stand_end, 1, my_termprint);
}
