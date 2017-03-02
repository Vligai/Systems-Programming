#include "my_select.h"
/*
  Pre Cond: none 
  Post Cond: initial terminal
 */
void init_terminal()
{
  char* n;
  struct termio l;
  int fd;
  ioctl(0, TCGETA, &l);
  gl_env.line_backup = l;
  l.c_lflag &= ~(ICANON|ISIG|ECHO);
  l.c_cc[VMIN] = READMIN;
  l.c_cc[VTIME] = READTIME;
  ioctl(0, TCSETA, &l);
  n = ttyname(0);
  fd = open(n, O_WRONLY);
  gl_env.stdio_backup = dup(1);
  dup2(fd, 1);
}




    

    
