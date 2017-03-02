/*
  pre cond: t_node*, t_node** and unsigned int
  post cond: add node at the position i of the list
*/
#include "mylist.h"
void add_node_at(t_node *n, t_node **head, unsigned int i)
{
  t_node *n2;
  t_node *n3;
  if(head==NULL || n==NULL || n->elem==NULL){
    return;
  }
  if(i==0 || (*head)==NULL){
    add_node(n, head);
    return;
  }
  n2=(*head);

  while(i--){
    if((n2->next)!=NULL){
      n2=n2->next;
    }
    else{
      break;
    }
  }
  if(((int)i)<0){
    n2=n2->prev;
  }
  if( (n2->next)==NULL){
    n2->next=n;
    n->prev=n2;
    n->next=NULL;
    return;
  }
  n3=n2->next;
  n2->next=n;
  n->prev=n2;
  n->next=n3;
  n3->prev=n;
  /*
  t_node *n2 = *head;
  t_node *n3;
  if (head == NULL || n == NULL || n->elem==NULL)
    return;
  if (i == 0 || *head == NULL)
    return add_node(n, head);
   
  //  if(n != NULL && *head != NULL && head != NULL)
  // {
  
      while(i-- && n2->next != NULL)
	n2=n2->next;
      
      if((int)i < 0)
	n2=n2->prev;

      if( (n2->next)==NULL){
	n2->next=n;
	n->prev=n2;
	n->next=NULL;
	return;

      }
      n3=n2->next;
      n2->next=n;
      n->prev=n2;
      n->next =n3;
      n3->prev=n;
      // }
      */
}
