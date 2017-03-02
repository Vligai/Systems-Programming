/*
  pre cond: t_node**
  post cond: removes all nodes from the list
*/
#include "mylist.h"
void   empty_list(t_node** head){
  if(head==NULL || (*head)==NULL)
    return;
  
  t_node *n;
  t_node *n2;
  n2=(*head);
  n=(*head);
  while(n2!=NULL){
    n->prev=NULL;
    n=n2->next;
    n2->next=NULL;
    free(n2);
    n2=n;
  }
  *head=NULL;
  /*
  t_node *n = *head;
  if (*head != NULL && head != NULL)
    {
      for(n; n != NULL; n = n->next)
	{
	  free(n);
	}
      *head = NULL;
    }
  */
}
