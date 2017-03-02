#include "my.h"

/*
  post cond: prints chars from a to z
  special cond: can't be > 1B
*/
void my_alpha()
{
  char c;
  for (c = 'a'; c<='z'; c++)
    {
      my_char(c);
    }
}
