/*
  pre cond: char*
  post cond: int from that string
*/

#include "my.h"

int my_atoi(char *s)
{
  unsigned int counter = 0;
  unsigned int r;
  for (;*s == ' '|| *s == '\t' || *s == '\n'; s++)
    ;
  r = 0;
  if(s != NULL)
    {
      for(;*s == '+' || *s == '-'; s++)                       
        {                                                                           
          if (*s == '+')                                                    
            ;  
          else if (*s == '-')                                              
	    counter++;                                                           
	}
      while(1){
	if((*s-'0')>9 || (*s-'0')<0){
	  if(counter % 2 != 0){
	    r *= -1;
	    return r;
	  }
	  return r;
	}
	else{
	  r*=10;
	  r+=(*s-'0');
	}
	s++;
      }
    }
  return r;
}

