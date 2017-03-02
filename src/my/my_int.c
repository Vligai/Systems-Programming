#include "my.h"

/*
  pre cond: int
  post cond: prints out that int
  special cond: no recursion, no arrays and < 10 lines
*/

void my_int(int i)
{
  unsigned int x;
  unsigned int y = 1;
  x = i;
  if (i == 0)
    {
      my_char('0');
      return;
    }
  if (i < 0)
    {
      x = -i;
      my_char ('-');
    }

  while (y <= x/10)
      {
	y *= 10;
      }

    while (y > 0)
      {
	my_char('0' + (x/y));
	x %= y;
	y /= 10;
      }

 
}
