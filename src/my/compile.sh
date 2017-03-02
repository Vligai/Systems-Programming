#!/bin/bash

cc -c -I../../include my_*.c xmalloc.c
ar -rc libmy.a my_*.o xmalloc.o
ranlib libmy.a
mv libmy.a ../../lib
