NAME1=my_select
SRC1=my_select.c init_terminal.c restore_terminal.c term_get_cap.c init_caps.c \
my_termprint.c term_clear.c term_vi.c term_ve.c check_char.c get_win_size.c \
show_elems.c refreshin.c refreshout.c moveup.c movedown.c moveleft.c moveright.c \
doselect.c getout.c setup_elems.c term_move.c term_move_to_item.c term_underline.c \
term_standout.c term_standend.c term_underend.c 

OBJ1=$(SRC1:.c=.o)
RM=rm -f
INCLPATH= ../../include
LIBPATH = ../../lib
CFLAGS+=-I$(INCLPATH)
LDFLAGS+= -L../../lib -Wall
LDLIBS+= -lmy -ltermcap

all:$(NAME1)

$(NAME1):$(OBJ1)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean: clean
	-$(RM) $(NAME1)

re: fclean all
