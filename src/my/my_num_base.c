#include "my.h"

/*
  pre cond: int and string
  post cond: prints out int in the base of the length of the string
  if string is "" or NULL print out "Base not valid \n"
*/
void my_num_base(int i, char *s)
{
  unsigned int e;
  unsigned int r;
  if (my_strlen(s)>0 && s != NULL)
    {
      e = i;
      if (i <0)
	{
	  my_char('-');
	  e = -i;
	}
 
      if(my_strlen(s) == 1)
	{
	  while(e -->0)
	    {
	      my_char(*s);
	    }
	}
      if(my_strlen(s) > 1){
	if (i == 0)
	  {
	    my_char(s[0]);
	    return;
	  }

	r = 1;
	while (r <= e/my_strlen(s))
	  {
	    r *= my_strlen(s);
	  }

	while (r > 0)
	  {
	    my_char(s[e/r]);
	    e %= r;
	    r /= my_strlen(s);
	  }
      }
    }
  else
    {
      my_str("Base not valid \n");
    }
  
}
