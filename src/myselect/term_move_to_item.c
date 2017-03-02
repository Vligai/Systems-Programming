#include "my_select.h"
/*
  Pre Cond: int
  Post Cond: move to that item
 */
void term_move_to_item(int n) 
{
   term_move(gl_env.elements[n].x, gl_env.elements[n].y);
}
