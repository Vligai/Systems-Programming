#include "my_select.h"
/*
  Pre Cond: none
  Post Cond: gets terminal window size
 */
char get_win_size(){
  ioctl(0, TIOCGWINSZ, &gl_env.win);
}
