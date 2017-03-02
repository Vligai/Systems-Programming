/*
  pre cond none 
  post cond prints the string recieved from the client
*/
#define _SERVER_H_
#include "minitalk.h"
void sfault1(int sig)
{
  if(sig==SIGINT)
    my_panic("\n exiting, bye! \n", 0);
   if(sig==SIGUSR2)
    gl_env.clpid<<=1;
  if(sig==SIGUSR1){
    gl_env.clpid<<=1;
    gl_env.clpid|=1;
  }
}
void sfault2(int sig)
{
  gl_env.torecieve<<=1;
  if(sig==SIGUSR1)
    gl_env.torecieve|=1;
  gl_env.num++;
}
int main()
{
  char c;
  pid_t pid;
  unsigned int counter;
  c=0;
  counter = 0;
  gl_env.torecieve=0;
  gl_env.num=0;
  my_int(getpid()); my_char('\n');
  while(1)
    {
    signal(SIGUSR1, sfault1);
    signal(SIGUSR2, sfault1);
    while(counter<8*sizeof(pid_t))
      {
	pause();
	counter++;
      }
    signal(SIGUSR1, sfault2);
    signal(SIGUSR2, sfault2);
    usleep(5000);
    kill(gl_env.clpid,SIGUSR1);
    while(!c)
      {
      pause();
      if(gl_env.num==8)
	{
	my_char(gl_env.torecieve);
	gl_env.num=0;
	gl_env.torecieve=0;
      }
      if(gl_env.torecieve=='\0' && gl_env.num==8)
	{
	my_char('\n');
	c=1;
	gl_env.num=0;
	gl_env.torecieve=0;
	}
      }
    }
  return 0;
}

