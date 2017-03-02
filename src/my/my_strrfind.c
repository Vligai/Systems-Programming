#include "my.h"
/*                                                    
  pre cond: String and a char                         
  post cond: returns pointer to first iteration of the character              
  in the string                                       
*/

char *my_strrfind(char *s, char c)
{
  char *l = NULL;
  int counter = 0;

  if(s!= NULL)
    {
      for (counter; *s != '\0'; s++)
        {
	  if(*s == c)
            {
	      l = s;
            }
	
        }
    }
  return l;
}
