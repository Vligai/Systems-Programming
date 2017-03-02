NAME=pipes
SRC=pipes.c
OBJ=$(SRC:.c=.o)
RM = rm -f
INCLPATH = ../../include
LIBPATH = ../../lib
CFLAGS += -I$(INCLPATH)
all:$(OBJ)
	cc -L$(LIBPATH) $(OBJ) -lmy -Wall -pedantic-errors -o $(NAME)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) \#*

fclean: clean
	-$(RM) $(LIBPATH)/$(NAME)

re: fclean all
