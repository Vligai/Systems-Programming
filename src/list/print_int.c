/*
  pre cond: t_node *n
  post cond: prints nodes of the list in the specified format
*/
#include "mylist.h"
void print_int(t_node *n)
{
  if(n != NULL)
    {
      my_str("(");
      if(n->prev != NULL)
	{
	  my_int(*((int*)((n->prev)->elem)));
	}
      else
	{
	  my_str("N");
	}
      my_str("<-");
      my_int(*((int*)(n->elem)));
      my_str("->");
      if(n->next != NULL)
	{
	  my_int(*((int*)((n->next)->elem)));
	}
      else
	{
	  my_str("N");
	}
      my_str(") ");
    }
  else
    {
      my_str("The list is empty\n");
    }
}
