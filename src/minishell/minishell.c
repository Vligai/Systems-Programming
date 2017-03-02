#include "my.h"

#define BUFF 256

int main()
{
  unsigned int i;
  unsigned int n;
  unsigned int pid;
  char** e;
  char* r;
   while(1)
    {
      r = (char*)xmalloc(sizeof(char)*BUFF);
      my_str("Prompt:");
      n=read(0, r, BUFF-1);
      r[n-1] = '\0';
      e = my_str2vect(r);	
      if(n>1)
	{
	  if(my_strcmp("exit", e[0]) == 0)
	    {
	      my_panic("Bye\n", 0);
	    }
	  if(my_strcmp(e[0], "cd") == 0)
            {
	      if(e[1] == NULL)
		 my_str("Please provide arguments for cd\n");

	      else if(chdir(e[1]) != 0)
		my_str("Directory not found\n");
	    }
	  else
	    {
	      if((pid = fork())<0)
		my_panic("Forking Error\n", 1);
	      
	      if(pid > 0)
		wait();

	      else if(pid == 0)
		{
		  
		  if(execvp(e[0], e)<0)
		    {
		      my_str(e[0]);
		      my_panic(": Execution failed\n", 1);
		    }
		  exit(0);  
		}
	      
	    }	
	}
    }
   return 0;
}


