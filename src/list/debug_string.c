/*
  pre cond: t_node *n
  post cond: prints list in the specified format
*/
#include "mylist.h"
void debug_string(t_node *n)
{
  if(n != NULL)
    {
      for(n; n!= NULL; n = n->next)
	{
	  print_string(n);
	}
    }
  else
    {
      my_str("The list is empty\n");
    }
}
