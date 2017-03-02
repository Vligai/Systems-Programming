 /*
  pre cond: t_node** and unsigned int i
  post cond: remove node at the position i of the list
*/

#include "mylist.h"

void *remove_node_at(t_node **head, unsigned int i)
{ 
  
  void   * e;
  t_node *n;
  t_node *n2;

  if(head==NULL || (*head) == NULL)
    return NULL;
  n=*head;
  if(i==0)
    return remove_node(head);
    
  while(i--){
    if((n->next)!=NULL){
      n=n->next;
    }
    else{
      break;
    }
  }
  if(n->next==NULL && n->prev==NULL){
    e=n->elem;
    (*head)=NULL;
    
    return e;
  }
  if(((int)i)<0){
    n=n->prev;
  }
  if((n->next)==NULL){
    e=n->elem;
    n2=n->prev;
    n->prev=NULL;
    n->next=NULL;
    n2->next=NULL;
    free(n);
    return e;
  }
  n2=n->next;
  e=n2->elem;
  n->next=n2->next;
  (n2->next)->prev=n;
  n2->prev=NULL;
  n2->next=NULL;
  free(n2);
  return e;
  /*
  t_node *n = *head;
  void *e;
  t_node *n2;
  if(i==0)
      return remove_node(head);
  
  if (*head != NULL && i > 0 && head != NULL)
    {
      while(i-- && (n->next) != NULL)
	  n = n -> next;
       
      if((int)i < 0)
	n=n->prev;
      if( (n->next)==NULL)
	{
	e=n->elem;
	n2=n->prev;
	n->next=NULL;
	n->prev=NULL;
	n2->next=NULL;
	free(n);
	return e;
	}
      n2 = n->next;
      e = n2->elem;
      n->next = n2->next;
      (n2->next)->prev = n;
      n2->next=NULL;
      n2->prev=NULL;
      free(n2);
      return e;
    }
  */
}
