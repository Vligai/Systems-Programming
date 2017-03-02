/*
  pre cond: t_node *n
  post cond: prints list in the specified format
*/
#include "mylist.h"
void traverse_int(t_node *n)
{
  if (n != NULL)
    {
      for (n; n != NULL; n = n->next)
	{ 
	  my_int(*((int*)(n->elem)));
	  my_char(' ');
	}
    }
  else
    {
      my_str("The list is empty\n");
    }
}
