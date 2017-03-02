NAME1=client
NAME2=server
SRC1=client.c
SRC2=server.c
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)
LDFLAGS+= -L../../lib -Wall
LDLIBS+= -lmy

all:$(NAME1) $(NAME2)

$(NAME1):$(OBJ1)
$(NAME2):$(OBJ2)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) \#*

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all
