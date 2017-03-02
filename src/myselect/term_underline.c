#include "my_select.h"
/*
  Pre Cond:none 
  Post Cond:underlines elements in the terminal
 */
void term_underline()
{
  tputs(gl_env.underline, 1, my_termprint);
}
