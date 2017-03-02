#include "my_select.h"
/*
 Pre Cond: none
 Post Cond: select element
 */
void doselect()
{
  if(gl_env.elements[gl_env.pos].mode != 0)
    {
      gl_env.elements[gl_env.pos].mode = 0;
    }
  else
    {
      gl_env.elements[gl_env.pos].mode = 1;
      movedown();     
    }
  refreshin();  
}
