#include "my_select.h"
/*
  Pre Cond: none
  Post Cond: unhighlight
 */
void term_standout()
{
  tputs(gl_env.standout, 1, my_termprint);
}
