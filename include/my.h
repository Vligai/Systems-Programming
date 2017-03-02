/*
Header File
*/
#ifndef _MY_H_
#define _MY_H_
#ifndef NULL
#define NULL ((void*)0)
#endif
#include <unistd.h>
#include <stdlib.h>
/*
  pre cond: char
  post cond: prints out that char
*/
void my_char(char);
/*               
  pre cond: string
  post cond: prints out that string (test NULL)       
*/
void my_str(char*);
/*                   
  pre cond: int
  post cond: prints out that int
  special cond: no recursion, no arrays and < 10 lines
*/
void my_int(int);
/*                                                                                                
  pre cond: int and string  
  post cond: prints out int in the base of the length of the string;
  if string is "" or NULL print out "Base not valid \n"                                                              
*/
void my_num_base(int, char*);
/*                                                                      
  post cond: prints out chars from a to z
  special cond: can't be > 1B
*/
void my_alpha();
/*                                                                                    
  post cond: prints out integers from 0 to 9
  special cond: can't be > 1B
*/
void my_digits();
/*                                                                               
  pre cond: string                                                                 
  post cond: returns the length of the string, if string is NULL return -1 and
  if "" return 0                                                
*/
int my_strlen(char*);
/*                                                                               
  pre cond: string                                                                 
  post cond: reverses the string and returns its length, if string is NULL return
  -1 and if "" return 0
*/
int my_revstr(char*);
/*                                                                               
  pre cond: string and char                                                                 
  post cond: my_strindex starts search for char from index 0 of the string;
  it returns index of the first char it finds in the string; if char not found
  return -1
  special cond: 1 parse
*/
int my_strindex(char*, char);
/*                                                                               
  pre cond: char and string                                                                 
  post cond: returns index of the last char it endounters in the string; if char not 
  found then return -1
  special cond: 1 parse
*/
int my_strrindex(char*, char);
void *xmalloc(unsigned int);
char *my_strdup(char*);
char *my_strcpy(char*, char*);
char *my_strncpy(char *, char*, unsigned int);
int my_strcmp(char*, char*);
int my_strncmp(char*, char*, unsigned int);
char *my_strconcat(char*, char*);
char *my_strnconcat(char*, char*, unsigned int);
char *my_strcat(char*, char*);
void my_panic(char*, unsigned int);
char *my_strfind(char*, char);
char *my_strrfind(char*, char);
char *my_vect2str(char**);
char **my_str2vect(char*);
int my_atoi(char*);

#endif
