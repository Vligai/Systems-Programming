/*
  pre cond:
  post cond:
*/
#include "my.h"
#define MAX 256

int main (int argc, char **argv)
{
  int pid;
  int fds[2];
  int fds1[2];
  int n;
  char buff[MAX];
  char *c;
 
  if (argc < 2)
    my_panic("Use: ./pipes arg1 [arg2 arg3 ...] \n", 1);

  pipe(fds);
  
  if ( (pid = fork()) < 0 )
    my_panic("NO \n", 1);

  c = my_vect2str(&argv[1]);

  if (pid > 0)
    {
      
      close(fds[0]);
      my_str("Passing ");
      my_str(c);
      my_str(" from grandpa \n");
      write(fds[1], c, MAX-1);
      wait();
    }
  else
    {
      close(fds[1]);
      n = read(fds[0], buff, MAX-1);

      my_str("Parent Recieving ");
      my_str(buff);
      my_str(" from grandpa and passing it to child \n");

      pipe(fds1);

      if((pid = fork()) <0)
	my_panic("NO \n", 1);

      if(pid>0)
	{
	  close(fds1[0]);
	  write(fds1[1], buff, MAX-1);
	  wait();
	}
      else
	{
	  close(fds1[1]);
	  n = read(fds1[0], buff, MAX-1);
	  
	  my_str("Child Recieving ");
	  my_str(buff);
	  my_str(" from parent \n");
	  exit(0);
	}
    }
  return 0;
}
