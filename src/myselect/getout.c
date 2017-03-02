#include "my_select.h"
/*
  Pre Cond: char
  Post Cond: depending on char this will exit and retore terminal
 */
void getout(char c)
{
  int counter;
  counter = 0;
  term_ve();
  term_clear();
  restore_terminal();
  if (!c)
    {
      while(counter<gl_env.nbelems)
	{
	  if(gl_env.elements[counter].mode)
	    {
	      my_str(gl_env.elements[counter].elem);
	      my_char(' ');
	    }  
	  counter++;
	}
      my_char('\n');
    }
  exit(0); 
}
