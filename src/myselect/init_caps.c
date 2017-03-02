#include "my_select.h"
/*
  Pre cond: none
  Post Cond: initial caps
 */
void init_caps()
{
  char ar[2048];
  char* t;
  t = getenv("TERM");
  tgetent(ar, t);
  gl_env.clear = term_get_cap(CLEAR);
  gl_env.move = term_get_cap(MOVE);
  gl_env.standout = term_get_cap(STANDOUT);
  gl_env.stand_end = term_get_cap(STAND_END);
  gl_env.underline = term_get_cap(UNDERLINE);
  gl_env.under_end = term_get_cap(UNDER_END);
  gl_env.cursoroff = term_get_cap(CURSOROFF);
  gl_env.cursoron = term_get_cap(CURSORON);
}
