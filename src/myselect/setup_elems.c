#include "my_select.h"
/*
  Pre Cond: int and char** 
  Post Cond: sets up elements o nthe terminal  
 */
void setup_elems(int c, char** v)
{
  int counter;
  counter = 0;
  gl_env.elements = xmalloc(c*sizeof(t_elem));
  gl_env.nbelems = c;
  gl_env.pos = 0;
  while(counter<c)
    {
      gl_env.elements[counter].elem = v[counter];
      gl_env.elements[counter].size = my_strlen(v[counter]);
      gl_env.elements[counter].x = 0;
      gl_env.elements[counter].y = 0;
      gl_env.elements[counter].mode = 0;
      counter++;
    }
  
}
