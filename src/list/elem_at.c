/*
  pre_cond: t_node* and unsigned int 
  post_cond: return element in the node at the position i in the list
*/
#include "mylist.h"
void *elem_at(t_node *n, unsigned int i)
{
  t_node *n2;
  if(n==NULL)
    return NULL;
  if(i == 0)
    return n->elem;
  n2 = n;
  // if (n != NULL && i > 0)
  //{
  while (n2->next != NULL && i > 0)
    {
      i--;
      n2 = n2->next;
    }
  if((n2->next) == NULL)
    {
      return n2->elem;
    }
  
  return (n2->next)->elem;
  //}
  /*
  t_node *n2 = n;
  if(i == 0)
    {
      return n->elem;
    }
  if (n != NULL && i > 0)
    {
      while (n2->next != NULL && i > 0)
	{
	  i--;
	  n2 = n2->next;
	}
      if((n2->next) == NULL)
	{
	  return n2->elem;
	}

      return (n2->next)->elem;
    }
  */
}
