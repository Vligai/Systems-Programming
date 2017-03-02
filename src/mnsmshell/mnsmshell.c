#include "mnsmshell.h"

char *buf;
char *bufbak;
t_node *listhead;
t_node *temphead;

/*void ctrlc(int sig)
{
  unsigned int i;
  for (i=0; i<MAX; i++)
    bufbak[i] = '\0';
  buf = bufbak;
  *buf = '\n';
  //my_str("\n");
  *(++buf) = '\n';
  my_termprint('\n');
  my_str("> ");
  return;
}
*/

/*
 *pre: does not take any arguments..
 *post: when run, you get a working (minimal shell) that can be used to execute other commands
 */
int main()
{
  char **vect;
  char chk;
  int pid;
  int n;
  int chd;
  unsigned int i;
  
  buf = (char *)xmalloc(MAX*sizeof(char));
  bufbak = buf;
  listhead = new_node(NULL,NULL,NULL);
  temphead = listhead;
  signal(SIGWINCH,get_win_size);
  get_win_size();
  //signal(SIGINT,ctrlc);
  init_caps();
  init_terminal();
  term_clear();

  //my_char('\n');
  my_str("> ");
  gl_env.x = 2;
  gl_env.y = 0;
  while (1)
    {
      n = read(0, buf, 3);
      if (n<0)
	my_panic("Error reading input.\n",-2);
      buf+=n;
      *buf = '\0';
      chk = check_character(buf);

      if (*(buf-1) != '\n')
	continue;

      gl_env.y++;
      *(buf-1) = '\0';
      vect = my_str2vect(bufbak);
      /* expand ~ to HOME env variable */
      for (i=0; vect[i] != NULL; ++i)
	if (!my_strcmp(vect[i],"~"))
	  vect[i] = getenv("HOME");
      /* add cmd to list */
      add_elem(vect,&listhead);
      temphead = listhead;
      /* check if command is non-fork */
      if ( my_strcmp(*vect,"cd") == 0 )
	{
	  if (*(vect+1) == NULL)
	    {
	      my_str("Usage: cd <directory>\n");
	    }
	  else if (chdir(*(vect+1)))
	    {
	      my_str("Cannot change directory to ");
	      my_str(vect[1]);
	      my_char('\n');
	    }
	}
      else if ( my_strcmp(*vect,"exit") == 0 )
	{
	  restore_terminal();
	  my_str("Bye!\n");
	  exit(0);
	}
      else if ( my_strcmp(*vect,"clear") == 0 )
	{
	  memset(bufbak,'\0',MAX-1);
	  gl_env.x = 2;
	  gl_env.y = 0;
	  term_clear();
	}
      /* otherwise fork */
      else
	{
	  pid = fork();
	  if ( pid == 0 )
	    {
	      if ( execvp(vect[0],vect) )
		{
		  my_str(vect[0]);
		  my_panic(" command not found.\n",2);
		}
	      exit(0);
	    }
	  else if (pid < 0)
	    my_panic("Fork failed.\n",1);
	  else
	    wait();
	}
      //for (i=0; i<MAX; i++)
      //bufbak[i] = '\0'
      buf = bufbak;
      my_str("> ");
      gl_env.x = 2;
    }
  return 0;
}
