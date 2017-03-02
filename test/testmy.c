/*
   Vladislav Ligai
   I pledge my honor that I have abided by the Stevens Honor System
   testmy tests methods in /src/my folder
   if no errors found return 0
*/
#include "my.h"
int main ()
{
  int maxneg;
  char str[] = "even";
  char str2[] = "odd";
  /*
    testing my_char method
  */
  my_char('1'); my_char('\n'); //prints 1
  my_char('a'); my_char ('\n');
  /*                                          
    testing my_str method                    
  */
  my_str("dwad"); my_char ('\n'); //prints dwad 
  my_str(NULL); my_char ('\n');
  my_str(""); my_char ('\n');
  my_str("131232"); my_char ('\n');
  /*                                          
    testing my_int method                    
  */
  my_int(13000); my_char ('\n');
  my_int(321312); my_char ('\n'); //prints 321312
  my_int(-1232); my_char ('\n');
  my_int(0); my_char ('\n');
  maxneg = 1 << (8* sizeof(int)-1); 
  my_int(maxneg); my_char ('\n');
  /*                                          
    testing my_num_base method                    
  */
  my_num_base(9, "BLAH"); my_char ('\n');//prints AL
  my_num_base(-9, "BLAH"); my_char ('\n');//prints -AL
  my_num_base(maxneg, "0123456789"); my_char('\n');
  my_num_base(4, "?"); my_char ('\n');//prints ????
  my_num_base(-4, "?"); my_char ('\n'); //prints -????
  my_num_base(16, "0123456789abcdef"); my_char ('\n'); //prints 10
  my_num_base(0, "!"); my_char ('\n');//nothing
  my_num_base(0, "BLAH"); my_char ('\n');//prints B
  my_num_base(9, ""); my_char ('\n');//prints "Base not valid\n"
  my_num_base(88, NULL); my_char ('\n');//prints "Base not valid \n"
  /*                                          
    testing my_alpha method                    
  */
  my_alpha(); my_char ('\n'); //prints chars a-z
  /*                                          
    testing my_digits method                    
  */
  my_digits(); my_char ('\n'); //prints ints 0-9
  /*                                          
    testing my_strlen method                    
  */
  if (my_strlen(NULL) != -1)
    {
      my_str("error in my_strlen"); my_char ('\n');
    }
  else
    {
      my_str("my_strlen NULL works"); my_char('\n');
    }
  if (my_strlen("abc") != 3)
    {
      my_str("error in my_strlen"); my_char ('\n');
       
    }
  if (my_strlen("") != 0) //if string is empty and output is not 0
    {
      my_str("error in my_strlen"); my_char ('\n');
       
    }
  if (my_strlen(":;//??**") != 8)
    {
      my_str("error in my_strlen"); my_char ('\n');
       
    }
  if (my_strlen("123456789") != 9)
    {
      my_str("error in my_strlen"); my_char ('\n');
       
    }
  if (my_strlen("uuuu") != 4)
    {
      my_str("error in my_strlen"); my_char ('\n');
       
    }
  else
    {
      my_str("my_strlen works"); my_char('\n');
    }
  /*                                          
    testing my_revstr method                    
  */
  my_int(my_revstr(str)); my_char ('\n');
    my_str(str); my_char ('\n');
  my_int(my_revstr(str2)); my_char ('\n');
    my_str(str2); my_char ('\n');
  my_int(my_revstr(NULL)); my_char ('\n');
       
  /*                                          
    testing my_strindex method                    
  */
  if (my_strindex("abcd", 'd') != 3)
    {
      my_str("error in my_strindex"); my_char ('\n');
    }
  else
    {
      my_str("case 1 of strindex works"); my_char ('\n');
    }
  if (my_strindex("abc", 'd') != -1)
    {
      my_str("error in my_strindex"); my_char ('\n');
    }
  if (my_strindex("", 'd') != -1)
    {
      my_str("error in my_strindex"); my_char ('\n');
    }
  if (my_strindex(NULL, 'd') != -1)
    {
      my_str("error in my_strindex"); my_char ('\n');
       
    }
  if (my_strindex("Potllo", 'l') != 3)
    {
      my_str("error in my_strindex"); my_char ('\n');
       
    }
  if (my_strindex("Potlllllllo", 'l') != 3)
    {
      my_str("error in my_strindex"); my_char ('\n');
       
    }
  /*                                                           
    testing my_strrindex method                                 
  */
  if (my_strrindex("0123", '3') != 3)
    {
      my_str("error in my_strrindex"); my_char ('\n');
       
    }
  if (my_strrindex("abc", 'd') != -1)
    {
      my_str("error in my_strrindex"); my_char ('\n');
       
    }
  if (my_strrindex("", 'd') != -1)
    {
      my_str("error in my_strrindex"); my_char ('\n');
       
    }
  if (my_strrindex(NULL, 'd') != -1)
    {
      my_str("error in my_strrindex"); my_char ('\n');
       
    }
  if (my_strrindex("Hello", 'l') != 3)
    {
      my_str("error in my_strrindex"); my_char ('\n');
       
    }
  if (my_strrindex("Hellllllo", 'l') != 7)
    {
      my_str("error in my_strrindex"); my_char ('\n');
       
    }
  my_str("Clap_Clap"); my_char('\n');
  return 0;  
}  

