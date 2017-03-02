#include "my.h"

#include "mylist.h"





int main(){

  char *s="hello";

  char *s2="bye";

  char *s3="hi";

  char w='w';

  char a='a';

  int x=7;

  int q=0;

  t_node *n=NULL;

  t_node *p=NULL;

  t_node *n2=NULL;

  t_node *p2=NULL;

  t_node *head;

  t_node *head2;

  t_node *head3;

  t_node *head4;

  t_node *head5;

  t_node *head6;

  t_node *head7;

  t_node *head8;

  t_node *stuff;

  t_node *stuff2;



  /*Testing count_nodes with NULL */

  my_int(count_nodes(head));/* should print 0*/



  /*Testing new_node, debug_string,and print_string */

  head= new_node(s,n,p);/* should make node with hello */

  head2= new_node(s2,n2,p2);/* should make node with bye */

  head3= new_node(s,n,p);/* should make node with hello */

  head4= new_node(s,n,p);/* should make node with hello */

  head5= new_node(s3,n,p);/* should make node with hi */

  head6= new_node(s3,head4,p);/* should make node with hi with next head4 */

  head6= new_node(s,n,head4);/* should make node with hello with previous head4 */

  head7= new_node(s2,n,p);/* should make node with bye */

  head8= new_node(s3,head7,head6);/* should make node with hi with previous head6 and next head7 */

  debug_string(head8);/* should print (hello<-hi->bye) */

  print_string(head8);/* should print (hello<-hi->bye) (hi<-bye->N) */

  traverse_string(head); /* should print node with hello */

  traverse_string(head2); /* should print node with bye */

  stuff2=new_node(n,n,p);/* should return NULL */

  if(stuff==NULL){

    my_str("Correct");

  }

  else{

    my_str("Wrong");

  }

  traverse_int(n);/* the list is empty */

  traverse_string(n);/* the list is empty */

  traverse_char(n);/* the list is empty */

  debug_string(n);/* the list is empty */

  debug_int(n);/* the list is empty */

  debug_char(n);/* the list is empty */

  print_char(n);/* the list is empty */

  print_string(n);/* the list is empty */

  print_int(n);/* the list is empty */







  /*Testing add_node and add_elem */

  add_node(head2, &head);/* should make head with bye hello*/

  traverse_string(head); /* should print bye hello*/

  add_elem(s3, &head);/* should make hi bye hello*/

  traverse_string(head); /* should print hi bye hello*/



  /*Testing append */

  append(head2, &head);

  traverse_string(head); /* should print hi bye hello bye*/



  /*Testing add_node_at and my_int*/

  add_node_at(head2, &head, 1);

  traverse_string(head); /* should print hi bye bye hello bye*/

  my_int(count_nodes(head));/* should print 5*/

  add_node_at(head3, &head, 100); /* should print hi bye bye hello bye hello*/

  traverse_string(head);

  add_node_at(stuff2, &head, 1);/* should do nothing */

  traverse_string(head);



  /*Testing count_nodes */

  my_int(count_nodes(head));/*should print 6*/



  /*Testing remove_node_at */

  remove_node_at(&head, 1);

  traverse_string(head); /* should print bye bye hello bye hello*/

  remove_node_at(&head, 100);

  traverse_string(head);/* should print bye bye hello bye */



  /*Testing remove_last and my_int */

  add_node_at(head3, &head, 1);

  traverse_string(head); /* should print bye hello bye hello bye hello*/

  my_int(count_nodes(head)); /* should print 6*/

  remove_last(&head);

  traverse_string(head); /* should print bye hello bye hello bye*/

  remove_last(&stuff2);/* should print nothing*/

  traverse_string(stuff2);/* should print nothing*/



  /*Testing empty_list */

  traverse_string(head4);/* should print hello */

  add_node(head2, &head4);

  traverse_string(head4); /* should print bye hello */

  my_int(count_nodes(head4));/* should print 2*/

  empty_list(&head4);

  traverse_string(head4); /* should print nothing */

  my_int(count_nodes(head4));/* should print 0*/



  /*Testing node_at */

  stuff=node_at(head,1);

  traverse_string(stuff);/* should print hello */

  stuff=node_at(head,100);

  traverse_string(stuff);/* should print bye */

  stuff=node_at(head,0);

  traverse_string(stuff);/* should print bye */

  stuff=node_at(head3,1);

  traverse_string(stuff);/* should print hello */

  stuff=node_at(stuff2,1);

  my_int(count_nodes(head));/* should print nothing */



  /*Testing elem_at */

  elem_at(head,1);/* should print hello */

  elem_at(head,100);/* should print bye */

  elem_at(head,0);/* should print bye */

  elem_at(head3,1);/* should print hello */

  elem_at(stuff2,1);/* should print nothing */



  /*Testing remove_node */

  add_node_at(head5, &head, 1);

  traverse_string(head);/* should print bye hi hello bye hello bye*/

  add_node_at(head5, &head, 0);

  traverse_string(head);/* should print hi bye hello bye hello bye*/

  remove_node(&head);

  traverse_string(head);/* should print bye hello bye hello bye*/

  remove_node(&stuff2);/* should print nothing */



  /*Testing traverse_int traverse_char, debug_int, print_int, debug_char, print_char  */

  head4= new_node(&x,n2,p2);

  traverse_int(head4);/* should print 7 */

  debug_int(head4);/* should print (N<-7->N) */

  print_int(head4);/* should print (N<-7->N) */

  add_elem(&q, &head4);

  traverse_int(head4);/* should print 0 7 */

  debug_int(head4);/* should print (N<-0->7) */

  print_int(head4);/* should print (N<-0->7) (0<-7->N) */

  empty_list(&head4);

  head4= new_node(&a,n2,p2);

  traverse_char(head4);/* should print a */

  debug_char(head4);/* should print (N<-a->N) */

  print_char(head4);/* should print (N<-a->N) */

  add_elem(&w, &head4);

  traverse_char(head4);/* should print w a */

  debug_char(head4);/* should print (N<-w->a) */

  print_char(head4);/* should print (N<-w->a) (w<-a->N) */



  return 0;

}
