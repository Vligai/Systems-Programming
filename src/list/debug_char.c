/*
  pre cond: t_node *n
  post cond: prints list in the specified format  pre cond
*/
#include "mylist.h"
void debug_char(t_node *n)
{
  if(n != NULL)
    {
      for (n; n!= NULL; n = n-> next)
	{
	  print_char(n);
	}
    }
  else
    {
      my_str("The list is empty\n");
    }
}
