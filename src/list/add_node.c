/*
  pre cond: t_node* and t_node**
  post cond: adds a node in the beginning of the list
*/
#include "mylist.h"

void add_node(t_node *n, t_node **head)
{
  if(head != NULL && n != NULL && n->elem != NULL)
    {
      if(*head!=NULL)
	(*head)->prev =n;
      n->next=*head;
      n->prev=NULL;
      *head=n;
    }
  /*
  if(*head == NULL)
    {
      *head = n;
      n->next=NULL;
      n->prev=NULL;
      return;
    }
  if (head == NULL || n ==NULL)
    return;
  else
    {
      n->prev=NULL;
      n->next=(*head);
      (*head)->prev=n;
      *head=n;
    }
  */
}
