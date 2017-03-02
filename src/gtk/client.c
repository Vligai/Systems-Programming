/*
  pre cond: name of the machine server is running on, port number, message
  post cond: sends message to the server, where it is displayed
  same idea as sockets, but add gtk to the client side
*/
#include "gsockets.h"
t_env gl_env;

void notime(int sig)
{
  if(sig == SIGINT)
    {
      my_str("bye\n");
      write(gl_env.sockfd, "/exit", sizeof("/exit"));
      gtk_main_quit();
      exit(0);
    }
}
void notime2(int sig)
{
  if(sig == SIGINT)
    {
      my_str("bye\n");
      gtk_main_quit();
      exit(0);
    }
}
void conn_close(GtkWidget *win, gpointer data)
{
  if((my_connect(win, data)) <= 0)
    {
      gl_env.connected = 1;
      gtk_widget_destroy(data);
    }      
  else 
    gl_env.connected = 0;
}
gint conf_close(GtkWidget *win, GdkEvent *evt, gpointer data)
{
  gtk_widget_destroy(win);
  return 0;
}
gint cwin_close(GtkWidget *win, GdkEvent *evt, gpointer data)
{
  gtk_toggle_button_set_active((GtkToggleButton*)gl_env.bconnect ,FALSE);
  gtk_widget_destroy(win);
  return 0;
}
void cli_close(GtkWidget *win, gpointer data)
{
  write(gl_env.sockfd, "/exit", 6);
  close(gl_env.sockfd);
  gtk_main_quit();
}
gint conf_call(GtkWidget *win, GdkEvent *evt, gpointer data)
{
  GtkWidget *byes;
  GtkWidget *bno;
  GtkWidget *label;
  GtkWidget *btop;
  GtkWidget *bbox;
  GtkWidget *vbox;
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  byes = gtk_button_new_with_label("yes");
  bno = gtk_button_new_with_label("no");
  label = gtk_label_new("are you sure?");
  btop = gtk_hbox_new(FALSE, 0);
  bbox = gtk_hbox_new(FALSE, 0);
  vbox = gtk_vbox_new(FALSE, 0);
  g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(conf_close), NULL);
  g_signal_connect_swapped(G_OBJECT(bno), "clicked", G_CALLBACK(gtk_widget_destroy), G_OBJECT(win));
  g_signal_connect(G_OBJECT(byes), "clicked", G_CALLBACK(cli_close), NULL);
  gtk_box_pack_start(GTK_BOX(bbox), byes, TRUE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(bbox), bno, TRUE, TRUE, 1);
  gtk_box_pack_start(GTK_BOX(btop), label, TRUE, TRUE, 3);
  gtk_box_pack_start(GTK_BOX(vbox), btop, TRUE, TRUE, 4);
  gtk_box_pack_start(GTK_BOX(vbox), bbox, TRUE, TRUE, 4);
  gtk_container_add(GTK_CONTAINER(win), vbox);
  gtk_container_set_border_width(GTK_CONTAINER(win), 5);
  gtk_widget_show(win);  
  gtk_widget_show(byes);
  gtk_widget_show(bno);
  gtk_widget_show(label);
  gtk_widget_show(btop);
  gtk_widget_show(bbox);
  gtk_widget_show(vbox);
  return 1;
}
void conn_call (GtkWidget *wid, gpointer data) 
{
  GtkWidget *win;
  GtkWidget *label;
  GtkWidget *ok;
  GtkWidget *can; 
  GtkWidget *host;
  GtkWidget *nport;
  GtkWidget *nnick;
  GtkWidget *rbox;
  GtkWidget *lbox;
  GtkWidget *hbox;
  GtkWidget *nick;
  GtkWidget *mac;
  GtkWidget *port;
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  label = gtk_label_new("connect");
  ok = gtk_button_new_with_label("ok");
  can = gtk_button_new_with_label("cancel");
  host = gtk_entry_new();
  nport = gtk_entry_new();
  mac = gtk_label_new("host: ");
  port = gtk_label_new("port: ");
  nick = gtk_label_new("nick: ");
  nnick = gtk_entry_new();
  hbox = gtk_hbox_new(FALSE, 0);
  rbox = gtk_vbox_new(FALSE, 0);
  lbox = gtk_vbox_new(FALSE, 0);
  gl_env.ent[0] = host;
  gl_env.ent[1] = nport;
  gl_env.ent[2] = nnick;
  g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(cwin_close), NULL);
  g_signal_connect_swapped(G_OBJECT(can), "clicked", G_CALLBACK(cwin_close), G_OBJECT(win));
  g_signal_connect(G_OBJECT(ok), "clicked", G_CALLBACK(conn_close), G_OBJECT(win));
  gtk_box_pack_start(GTK_BOX(rbox), host, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(rbox), nport, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(rbox), nnick, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(rbox), ok, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(lbox), label, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(lbox),  mac, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(lbox),  port, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(lbox),  nick, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(lbox), can, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(hbox), lbox, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(hbox), rbox, TRUE, TRUE, 2);
  gtk_container_add(GTK_CONTAINER(win), hbox);
  gtk_container_set_border_width(GTK_CONTAINER(win), 10);
  if(gl_env.connected && !gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON (wid)))
    {
      gtk_toggle_button_set_active((GtkToggleButton*)gl_env.bconnect, FALSE);
      write(gl_env.sockfd, "/exit", 6);
      close(gl_env.sockfd);
      gl_env.connected = 0;
    } 
  else 
    {
      gtk_widget_show( mac);
      gtk_widget_show( port);
      gtk_widget_show( nick);
      gtk_widget_show(host);
      gtk_widget_show(nport);
      gtk_widget_show(nnick);
      gtk_widget_show(rbox);
      gtk_widget_show(lbox);
      gtk_widget_show(hbox);
      gtk_widget_show(can);
      gtk_widget_show(ok);
      gtk_widget_show(win);
    }
}
void send_call(GtkWidget *win, gpointer data)
{
  char c[MAX_NUM];
  char* s;
  if(gl_env.connected)
    {
      s = (char*)gtk_entry_get_text(GTK_ENTRY(data));
      write(gl_env.sockfd, s, MAX_NUM-1);
      if(my_strncmp(s, "/exit", 5) == 0 && (s[5]==' ' || s[5]=='\t' || s[5]=='\0' || s[5]=='\n'))
	{
	  close(gl_env.sockfd);
	  gl_env.connected = 0;
	  gtk_toggle_button_set_active((GtkToggleButton*)gl_env.bconnect, FALSE);
	  s = "";
	  gtk_entry_set_text(GTK_ENTRY(data), s);
	  return;
	}
      read(gl_env.sockfd, c, MAX_NUM-1);
      if(c[0] != '~')
	{
	  gtk_toggle_button_set_active((GtkToggleButton*)gl_env.bconnect, FALSE);
	  gl_env.connected = 0;
	}
    }
  s = "";
  gtk_entry_set_text(GTK_ENTRY(data), s);
}
int my_connect(GtkWidget *wid, gpointer data)
{
  struct sockaddr_in srv;
  gl_env.port = my_atoi((char*)(gtk_entry_get_text((GtkEntry*)gl_env.ent[1])));
  if(gl_env.port > 0 && gl_env.port < (1<<16)-1)
    {
      gl_env.sockfd = socket(AF_INET, SOCK_STREAM, 0);
      gl_env.mac = (char*)gtk_entry_get_text((GtkEntry*)gl_env.ent[0]);
      if((gl_env.bserv = gethostbyname(gl_env.mac)) == NULL)
	  return 1;
      memset(&srv, 0, sizeof(srv));
      srv.sin_family = AF_INET;
      srv.sin_port = htons(gl_env.port);
      memcpy(&srv.sin_addr.s_addr, gl_env.bserv->h_addr, gl_env.bserv->h_length);
      if((connect(gl_env.sockfd, (struct sockaddr*)&srv, sizeof(srv))) < 0)
	  return 1;
      gl_env.nick = (char*)gtk_entry_get_text((GtkEntry*)gl_env.ent[2]);
      write(gl_env.sockfd, gl_env.nick, MAX_NUM-1);
      signal(SIGINT, notime);
      return 0;
    }
  else
    return 1;
}
int main (int argc, char* argv[])
{
  GtkWidget *win;
  GtkWidget *field;
  GtkWidget *bsend;
  GtkWidget *btop;
  GtkWidget *bbot;
  GtkWidget *bexit;
  GtkWidget *vbox;
  gtk_init(&argc, &argv);
  signal(SIGINT, notime2);
  win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  field = gtk_entry_new();
  bsend = gtk_button_new_with_label("send");
  btop = gtk_hbox_new(FALSE, 0);
  bbot = gtk_hbox_new(FALSE, 0);
  bexit = gtk_button_new_with_label("exit");
  vbox = gtk_vbox_new(FALSE, 0);
  gtk_container_add(GTK_CONTAINER(win), vbox);
  gtk_container_set_border_width(GTK_CONTAINER(win), 17);
  gl_env.bconnect = gtk_toggle_button_new_with_label("connect");
  g_signal_connect(G_OBJECT(win), "delete_event", G_CALLBACK(conf_call), NULL);
  g_signal_connect(G_OBJECT(bexit), "clicked", G_CALLBACK(conf_call), NULL);
  g_signal_connect(G_OBJECT(gl_env.bconnect), "clicked", G_CALLBACK(conn_call), NULL);
  g_signal_connect(G_OBJECT(bsend), "clicked", G_CALLBACK(send_call), field);
  gtk_box_pack_start(GTK_BOX(bbot), gl_env.bconnect, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(bbot), bexit, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(btop), field, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(bbot), bsend, TRUE, TRUE, 2);
  gtk_box_pack_start(GTK_BOX(vbox), btop, TRUE, TRUE, 0);
  gtk_box_pack_start(GTK_BOX(vbox), bbot, TRUE, TRUE, 0);
  gtk_widget_show(win);
  gtk_widget_show(field);
  gtk_widget_show(bsend);
  gtk_widget_show(btop);  
  gtk_widget_show(bbot);
  gtk_widget_show(bexit);
  gtk_widget_show(vbox); 
  gtk_widget_show(gl_env.bconnect);
  gtk_main();
  return 0;
}
