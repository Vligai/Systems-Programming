#include "myselect.h"

/*
 *moves cursor to the right
*/
void moveright()
{
  if (gl_env.x == gl_env.win.ws_col)
    {
      gl_env.x = 0;
      gl_env.y++;
    }
  term_move(++gl_env.x,gl_env.y);
  /*  refreshout(gl_env.pos);
  gl_env.pos += gl_env.win.ws_row;
  if ( gl_env.nbelems == 1 )
    gl_env.pos = 0;
  else if ( gl_env.pos > gl_env.nbelems )
    gl_env.pos = gl_env.nbelems-1;
    refreshin();*/
}
