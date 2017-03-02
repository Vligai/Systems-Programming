/*
  pre cond: t_node**
  post cond: removes last node of the list
*/

#include "mylist.h"
void *remove_last(t_node **head)
{
  void   * e;
  t_node *n;
  t_node *n2;
  if(head==NULL || (*head) == NULL)
    return NULL;
  n = *head;
  for(n; (n->next) != NULL; n=n->next);
  e=n->elem;
  if(n->prev==NULL){
    (*head)=NULL;
    return e;
  }
  n2=n->prev;
  n->prev=NULL;
  n->next=NULL;
  n2->next=NULL;
  free(n);
  return e;

  /*
  t_node *n = (*head)->next;
  t_node *n2;
  void *e;
  if(*head != NULL && head != NULL)
    {
      for(n; (n->next) != NULL; n=n->next);
      e=n->elem;
      n2=n->prev;
      n->next=NULL;
      n->prev=NULL;
      n2->next=NULL;
      free(n);
      return e;
    }
  */
}


