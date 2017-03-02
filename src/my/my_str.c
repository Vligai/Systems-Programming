#include "my.h"

/*
  pre cond: string
  post cond: prints out that string
*/

void my_str (char *s)
{
  int counter = 0;
  while (s != NULL && s[counter] != '\0')
    {
      my_char(s[counter]);
      counter++;
    }
}
