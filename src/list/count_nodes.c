/*
  pre cond: t_node*
  post cond: counts amount of nodes in the list
*/
#include "mylist.h"
unsigned int count_nodes(t_node *n)
{
  int counter = 0;
  if (n != NULL)
    {
      while (n != NULL)
	{
	  n = n->next;
	  counter ++;
	}
      
    }
  return counter;
  /*
  int counter = 1;
  if (n != NULL)
    {
      while (n->next != NULL)
	{
	  n = n->next;
	  counter ++;
	}
      return counter;
    }
  */
}
