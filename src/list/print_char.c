/*
  pre cond: t_node *n
  post cond: prints list in the specified format
*/
#include "mylist.h"
void print_char(t_node *n)
{
  if(n != NULL)
    {
      my_str("(");
      if(n->prev != NULL)
	{
	  my_char(*((char*)((n->prev)->elem)));
	}
      else
	{
	  my_str("N");
	}
      my_str("<-");
      my_char(*((char*)(n->elem)));
      my_str("->");
      if(n->next != NULL)
	{
	  my_char(*((char*)((n->next)->elem)));
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
