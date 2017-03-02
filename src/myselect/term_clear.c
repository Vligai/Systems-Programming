#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: clears terminal
 */
void term_clear()
{
  tputs(gl_env.clear, 1, my_termprint);
}
