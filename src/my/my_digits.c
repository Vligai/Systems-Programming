#include "my.h"

/*
  post cond: prints out ints from 0 to 9
  special cond: can't be > 1B
*/
void my_digits()
{
  char c;
  for(c = '0'; c <='9'; c++)
    {
      my_char(c);
    }
}
