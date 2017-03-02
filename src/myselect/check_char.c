#include "my_select.h"
/*
  Pre Cond: char*
  Post Cond: do stuff depending on which action is done
 */
char check_char(char *c)
{
  if (!strcmp(c, KL))
    moveleft();
  if (!strcmp(c, " "))     
    doselect();
  if (!strcmp(c, KD))
    movedown();	
  if (!strcmp(c, KU))
    moveup();
  if (!strcmp(c, KR))      
    moveright();
  if (c[0] == ESC && c[1] == '\0')
    {
      getout(1);
    }	
  if (c[0] == '\n' && c[1] == '\0')
    {
      getout(0);
    }
  return 0;
}
