/*
  pre cond: t_node* and unsigned int
  post cond: returns a node at the position i of the list
*/
#include "mylist.h"
t_node *node_at(t_node *n, unsigned int i)
{
  t_node *n2 = n;
  if(i == 0)
    {
      return n;
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
          return n2;
        }

      return n2->next;
    }

}
