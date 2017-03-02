#include "myselect.h"

/*
 *sets winsize variables
*/
void get_win_size()
{
  ioctl(0,TIOCGWINSZ,&gl_env.win);
}
