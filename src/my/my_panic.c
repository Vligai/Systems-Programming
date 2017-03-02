#include "my.h"
/* 
   pre cond: String and unsigned int
   post cond: prints String and exists with status number
*/
void my_panic(char *s, unsigned int n)
{
  my_str(s);
  exit(n);
}
