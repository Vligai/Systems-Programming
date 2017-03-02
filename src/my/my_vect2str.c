/*
  pre cond: char ** vector
  post cond: return a string with all elements of vector
*/

#include "my.h"
/*
char *my_vect2str(char** v)
{
  char *n;
  char *m;
  int i =0;
  int counter = 0;

  if(*v == NULL)
    {
      m = (char*)xmalloc(sizeof(char));
      m = "";
      return m;
    }
  
  if(v != NULL)
    {
      while(v[i] != NULL)
        {
	  counter += my_strlen(v[i]);
	  i++;
       }

      n = (char *)xmalloc(counter * sizeof(char));
      i =0;

      while(v[i] != NULL)
        {
	  n = my_strcat(n, v[i]);
	  n = my_strcat(n, " ");
	  i++;
        }

      n[++counter] = '\0';
    }

  return n;
}
*/
char *my_vect2str(char** s){
	char** ssave=s;
	int len=0;
	int i=0;
	char* ss;
	if(s==NULL){
		return NULL;
	}
	if((*s)==NULL || (s[0][0])=='\0'){
		char *s3=(char *)xmalloc(sizeof(char));
		s3[0]='\0';
		return s3;
	}
	while(s!=NULL && (*s)!=NULL){
		len+=(my_strlen(s[0])+1);
		s++;
	}
	s=ssave;
	char *s2=(char *)xmalloc(len*sizeof(char));
	ss=(char *)(*s);
	while(s[0]!=NULL){
		ss=*s;
		while(ss[0]!='\0'){
			s2[i++]=ss[0];
			ss++;
		}
		s2[i++]=((char)' ');
		s++;
	}
	s=ssave;
	s2[len-1]=((char)'\0');
	return s2;
}
