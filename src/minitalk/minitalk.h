#ifndef _MINITALK_H_
#define _MINITALK_H_
#include "my.h"
#include <signal.h>

struct s_env{
	pid_t clpid;
	int num;
	char torecieve;
} gl_env;

#ifndef _SERVER_H_
void notime(int sig);
#endif

#ifndef _CLIENT_H_
void sfault1(int sig);
void sfault2(int sig);
#endif 

#endif
