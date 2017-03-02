#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: turn curson on
 */
void term_ve()
{
  tputs(gl_env.cursoron, 1, my_termprint);
}
