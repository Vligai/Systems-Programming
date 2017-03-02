#include "my_select.h"
/*
  Pre Cond: none
  Post Cond: restores terminal to its original state
 */

void restore_terminal()
{
  term_ve();
  term_standend();
  term_underend();
  ioctl(0, TCSETA, &(gl_env.line_backup));
  dup2(gl_env.stdio_backup, 1);
}
