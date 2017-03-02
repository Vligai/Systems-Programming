/*
  pre cond: void and 2 t_nodes 
  post cond: creates a new node
*/
#include "mylist.h"
t_node *new_node(void *e, t_node *n, t_node *p)
{
  t_node *node = (t_node*)xmalloc(sizeof(t_node));
  if (e != NULL)
    {
      node->elem = e;
      node->next = n;
      node->prev = p;
      return node;
    }
}
