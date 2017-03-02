#include "my_select.h"

/*
  Pre Cond: int
  Post Cond: refresh while resizing window large
*/

void refreshout(int n)
{
  term_move_to_item(n);
  if(gl_env.elements[n].mode)
    term_standout();
  my_str(gl_env.elements[n].elem);
  term_standend();
}
