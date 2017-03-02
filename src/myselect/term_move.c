#include "my_select.h"
/*
  Pre Cond: 2 ints
  Post Cond: moving terminal around
 */
void term_move(int c, int r)
{
  tputs(tgoto(gl_env.move, c, r), 1, my_termprint);
}
