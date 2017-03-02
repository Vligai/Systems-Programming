/*
  pre cond: void*, t_node**
  post cond: creates a node with an element e inside and puts it in the list
*/
#include "mylist.h"

void add_elem(void *e, t_node **head)
{
  if (head != NULL && e != NULL)
    add_node(new_node(e,NULL,NULL),head);
  /*
  t_node *n = new_node(e, *head, NULL);
  if (*head == NULL)
    {
      n=new_node(e,NULL,NULL);
      *head = n;
      return;
    }

  if (e != NULL && *head !=NULL && head != NULL)
    {
      (*head)->prev = n;
      n->next = *head;
      *head = n;
    }
  */
 
}
