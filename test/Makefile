TEST1=testlist
TEST2=atoitest
TEST3=teststr2vect
SRC1=testlist.c
SRC2=atoitest.c
SRC3=teststr2vect.c
OBJ1=$(SRC1:.c=.o)
OBJ2=$(SRC2:.c=.o)
OBJ3=$(SRC3:.c=.o)
RM=rm -f
INCLPATH= ../include
CFLAGS+=-I$(INCLPATH)
LDFLAGS+= -L../lib
LDLIBS+= -lmylist -lmy

all:$(TEST1) $(TEST2) $(TEST3)

$(TEST1):$(OBJ1)
$(TEST2):$(OBJ2)
$(TEST3):$(OBJ3)

clean:
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.core
	-$(RM) *.swp
	-$(RM) \#*

fclean:clean all

re:fclean all
