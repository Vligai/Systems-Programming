/*
  pre cond: t_node**
  post cond: removes the first node of the list
*/
#include "mylist.h"
void *remove_node(t_node **head)
{
  void *e=NULL;
  t_node* n;
  if(head!=NULL && *head!=NULL){
    if((*head)->next==NULL){
      e=(*head)->elem;
      (*head)=NULL;
      return e;
    }
    n=*head;
    e=(*head)->elem;
    *head=n->next;
    (*head)->prev=NULL;
    n->next=NULL;
    n->prev=NULL;
    free(n);
  }
  return e;
  /*
  t_node *n2 = *head;
  void *e;
  if(*head != NULL && head != NULL)
    {
      e = (*head)->elem;
      *head = n2->next;
      (*head)->prev=NULL;
      n2->prev=NULL;
      n2->next=NULL;
      free(n2);
      return e;
    }
  */
}
