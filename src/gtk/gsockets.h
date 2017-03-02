/*
  Header File
 */
#ifndef _GSOCKETS_H_
#define _GSOCKETS_H_
#ifndef _MY_H_
#include "../../include/my.h"
#endif
#define MAX_NUM 1024
#include <signal.h>
#include <gtk/gtk.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netdb.h>

typedef struct s_env
{
int sockfd;
char* nick;
char* mac;
char connected;
GtkWidget* ent[3];
GtkWidget* bconnect;
unsigned short port;
struct hostent *bserv;
}              t_env;

#ifndef _CLIENT_H_
int my_connect(GtkWidget*, gpointer);
void cli_close(GtkWidget*, gpointer);
gint conf_close(GtkWidget*, GdkEvent*, gpointer);
void conn_close(GtkWidget*, gpointer);
gint cwin_close(GtkWidget*, GdkEvent*, gpointer);
#endif

#ifndef _SERVER_H_
void notime(int sig);
#endif

#endif
