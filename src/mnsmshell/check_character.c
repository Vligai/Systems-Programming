#include "mnsmshell.h"

/*
 *pre: takes a char * for the keypress
 *post: performs the correct function based on keypress
*/
extern char *buf;
extern char *bufbak;
extern t_node *listhead;
extern t_node *temphead;
char check_character(char *c)
{
  char **lastvect;
  unsigned int i;
  unsigned int n;
  int xadj;
  char *s;
  char *s2;
  int len;
  int len2;
  /*Up key: Previous Command*/
  if (!my_strcmp(c-3,KU))
    {
      buf = bufbak;
      memset(bufbak,'\0',MAX-1);
      if (temphead != NULL)
	lastvect = (char **)temphead->elem;
      if (lastvect != NULL)
	for (i=0,xadj=0; lastvect[i] != NULL; ++i)
	  {
	    my_strcat(buf,lastvect[i]);
	    // if (lastvect[i+1] != NULL)
	    my_strcat(buf," ");
	  }
      my_str(buf);
      gl_env.x += my_strlen(buf);
      buf += my_strlen(buf);
      if (gl_env.x > gl_env.win.ws_col)
	{
	  gl_env.y++;
	  gl_env.x = gl_env.x - gl_env.win.ws_col;
	}
      if (temphead != NULL)
	temphead = temphead->next;
      *(buf) = '\n';
    }
  /*Down key: Next Command*/
  else if (!my_strcmp(c-3,KD))
    {
      buf = bufbak;
      memset(bufbak,'\0',MAX-1);
      if (temphead != NULL)
	lastvect = (char **)temphead->elem;
      if (lastvect != NULL)
	for (i=0,xadj=0; lastvect[i] != NULL; ++i)
	  {
	    my_strcat(buf,lastvect[i]);
	    // if (lastvect[i+1] != NULL)
	    my_strcat(buf," ");
	  }
      my_str(buf);
      gl_env.x += my_strlen(buf);
      buf += my_strlen(buf);
      if (gl_env.x > gl_env.win.ws_col)
	{
	  gl_env.y--;
	  gl_env.x = gl_env.x - gl_env.win.ws_col;
	}
      if (temphead != NULL)
	temphead = temphead->prev;
      *(buf) = '\n';
    }
  /*Right key: move along the line*/
  else if (!my_strcmp(c-3,KR))
    moveright();
  /*Left key: move along the line*/
  else if (!my_strcmp(c-3,KL))
    moveleft();
  /*Esc key*/
  else if (*c == ESC)
    getout(ESC);
  /*Ctrl-l: clears shell*/
  else if (*(c-1) == CTRL_L)
    {
      *(c-1) = '\0';
      gl_env.x = 2;
      gl_env.y = 0;
      term_clear();
      my_str("> ");
      my_str(bufbak);
    }
  /*Ctrl-A: moves cursor to the beginning of the line*/
  else if (*(c-1) == CTRL_A)
    {
      *(c-1) = '\0';
      gl_env.x = 2;
      term_move(gl_env.x, gl_env.y);
    }
  /*Ctrl-C: exits whatever is currently running in shell*/
  else if (*(c-1) == CTRL_C)
    {
      temphead = listhead;
      buf = bufbak;
      *buf = '\0';
      my_str("^C");
      gl_env.x = 2;
      gl_env.y++;
      my_str("\n> ");      
    }
  /*Ctrl-E: move cursor to the end of the line*/
  else if (*(c-1) == CTRL_E)
    {
      *(c-1) = '\0';
      gl_env.x = 2;
      term_move(gl_env.x + my_strlen(bufbak), gl_env.y);
    }
  /*Ctrl-K: Cuts the string from the position of the cursor to the end*/
  else if (*(c-1) == CTRL_K)
    {
      //need to find substring from location of mouse
    }
  /*Ctrl-Y: inserts whatever has been cut(by Ctrl-K/Ctrl-W)*/
  else if (*(c-1) == CTRL_Y)
    {
      //do stuff
      my_str("here");
    }
  /*Ctrl-W: Cuts the word before the cursor*/
  else if (*(c-1) == CTRL_W)
    {
      //do stuff
      my_str("here");
    }
  /*Ctrl-D: Deletes next character*/
  else if (*(c-1) == CTRL_D)
    {
       if (gl_env.x > 2)
	{
	  moveright();
	  my_termprint(' ');
	  *(c-1) = '\0';
	  *(c-2) = '\0';
	  buf-=2;
	}
      else if (gl_env.x <= 2)
	{
	  buf = bufbak;
	  memset(bufbak,'\0',MAX-1);
	  gl_env.x = 3;
	  moveright();
	}
    }
  /*Ctrl-U: Clears the line before the cursor position*/
  else if (*(c-1) == CTRL_U)
    {
      //do stuff
      my_str("here");
    }
  /*Backspace: removes previous character*/
  else if ( *(c-1) == BS && c > bufbak)
    {
      if (gl_env.x > 2)
	{
	  moveleft();
	  my_termprint(' ');
	  *(c-1) = '\0';
	  *(c-2) = '\0';
	  buf-=2;
	}
      else if (gl_env.x <= 2)
	{
	  buf = bufbak;
	  memset(bufbak,'\0',MAX-1);
	  gl_env.x = 3;
	  moveleft();
	}
    }
  else
    {
      gl_env.x++;
      my_termprint(*(c-1));
    }
  return 0;
}
