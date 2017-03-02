/*
  pre cond:t_node* and t_node**
  post cond: append a t_node to the head of the list
*/
#include "mylist.h"
void append(t_node *n, t_node **head)
{
  if (n == NULL || n->elem == NULL || head == NULL)
    return;
  t_node *n2 = *head;
  if(*head==NULL){
    *head=n;
    n->next=NULL;
    n->prev=NULL;
    return;
  }
  // else if(n != NULL && *head != NULL && head != NULL)
  // {
      for(n2; (n2->next) != NULL; n2 = n2->next);
      n2->next = n;
      n->prev=n2;
      n->next=NULL;
      // }
}
