#include "minitalk.h"
/*
  pre cond: int (pid) and vector
  post cond: converts vector to string and passes it to the server
*/
#define _CLIENT_H_
void notime(int sig)
{
  if(sig==SIGALRM)
    my_panic("timed out \n", 1);
}
int main( int argc, char* argv[] )
{
  int pid;
  unsigned int counter;
  unsigned int counter2;
  unsigned int x;
  int pid2;
  unsigned int k;
  char c;
  char* tosend;
  pid2=getpid();
  pid=my_atoi(argv[1]);
  tosend=my_vect2str(&argv[2]);
  counter = 0;
  counter2 = 0;
   k=1<<(8*sizeof(pid_t)-1);
  if(argc<2){
    my_str("Usage: ./client arg1 arg2 [...]\n");
    return 1;
  }
  if(pid <= 1)
    {
    my_str("Invalid PID\n");
    return 1;
    }
  signal(SIGUSR1, notime);
  signal(SIGALRM, notime);
  while(counter<(8*sizeof(pid_t)))
    {
      if(pid2&k)
	kill(pid,SIGUSR1);
      else
	kill(pid,SIGUSR2);
      pid2<<=1;
      usleep(3000);
      counter++;
    }
  alarm(2);
  pause();
  alarm(0);
  k=0;
  k=1<<8*(sizeof(char));
  counter = 0;
  x = my_strlen(tosend)+1;
  while(counter<x)
    {
      c=tosend[0];
       for(counter2=0;counter2<8*sizeof(char);counter2++)
	 {
	 if(c&k)
	   kill(pid,SIGUSR1);
	 else
	   kill(pid,SIGUSR2);
	 c<<=1;
	 usleep(2000);
       }
       tosend++;
       counter++;
    }
   return 0;
}


