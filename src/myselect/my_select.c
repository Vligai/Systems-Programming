/*
  pre cond: int and char**
  post cond: main method for myselect
 */
#include "my_select.h"

int main(int argc, char** argv)
{
  int n;
  char buff[4];  
  if(argc < 2)
    my_panic("Use: ./myselect arg1, arg2, ...",1);	
  signal(SIGWINCH, show_elems);
  init_terminal();		
  init_caps();			
  term_vi();
  term_clear(); 
  setup_elems(argc-1, &argv[1]);
  show_elems();
  while(1)
    {	
      n = read(0, buff, 5);	
      buff[n] = '\0';
      check_char(buff);
    }
  return 0;
}
