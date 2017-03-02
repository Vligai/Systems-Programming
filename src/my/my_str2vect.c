#include "my.h"


char **my_str2vect(char *s)
{
    char fl;
    unsigned int len;
    unsigned int counter;
    unsigned int counter2;
    char **r = NULL;
    char *r2;

    if(s != NULL)
    {
      counter2 = 0;
      fl = 1;
      counter = 0;
      len = 0;
      
      while(s[counter] != '\0')
	{
	  if(s[counter] == ' ' || s[counter] == '\n' || s[counter] == '\t')
	    counter++;
	  else
	    break;
	}
      if (s[counter] == '\0')
	{
	  r = (char**)xmalloc((len + 1) * sizeof(char*));
	  r[0] = NULL;
	  return r;
	}
      counter = 0;
      while (s[counter] != '\0')
	{
	       
	  if (fl == 1 && s[counter] != ' ' && s[counter] != '\n' && s[counter] != '\t')
	    {
	      fl = 0;
	      len++;
	    }
	  if (s[counter] == ' ' || s[counter] == '\n' || s[counter] == '\t')
	    fl = 1;
	  counter++;
	}
        len++;

	//s = bak;
	counter = 0;
        r = (char**)xmalloc((len + 1) * sizeof(char*));
        //r[len] = NULL;
        len = 0;
	
	while(1)
	  {
	    
	    // my_char(s[counter]); my_char('\n');
	    //my_char(s[counter+1]); my_char('\n');
	    if (s[counter] != ' ' && s[counter] != '\n' && s[counter] != '\t' && s[counter] != '\0')
	      {
		len++;
		//my_int(len); my_char('\n');
	      }
	    else
	    //if (s[counter] == ' ' || s[counter] == '\n' || s[counter] == '\t')
	      {
		if (len != 0)
		  {
		    //my_str("hello");
		    r2 = (char*)xmalloc((len+1)*sizeof(char));
		    r[counter2]=r2;
		    counter2++;
		    len=0;
		  }
	      
	      }
	    if (s[counter] == '\0'){
	      //my_str("vlad");
	      //my_int(len);
	      break;
	    }
	    counter++;
	    // my_str("hi");
	  }
	//return NULL;
	//my_str("bye");
	//my_str("vlad");
	counter2=0;
	len =0;
	counter=0;
	while(1)
	  {
	    if (s[counter] != ' ' && s[counter] != '\n' && s[counter] != '\t' && s[counter] != '\0')
	      {
		r[counter2][len++] = s[counter];
		if(s[counter+1] == ' ' || s[counter+1] == '\n' || s[counter+1] == '\t' || s[counter+1] == '\0')
		  counter2++;
	      }
	    if (s[counter] == ' ' || s[counter] == '\n' || s[counter] == '\t')
	      {
		len = 0;
	      }
	    counter++;
	    if(s[counter] == '\0')
	      break;
	   
	  }
	r[counter2] = NULL;
    }
         
    return r;
}

