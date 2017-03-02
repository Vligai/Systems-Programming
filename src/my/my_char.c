#include "my.h"

/*  
  pre cond: char 
  post cond: prints out that char 
*/

void my_char (char c)
{
  write (1, &c, 1);
}

