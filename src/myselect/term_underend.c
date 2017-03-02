#include "my_select.h"
/*
  Pre Cond: none
  Post Cond: un-underline
 */
void term_underend()
{
  tputs(gl_env.under_end, 1, my_termprint);
}
