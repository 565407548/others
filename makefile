cc=gcc
cflags=-g -I./include

bin=bin/sqrt 

image:$(bin)

clear:
	-rm $(bin)

bin/sqrt:src/sqrt.c
	$(cc) $(cflags) -o $@ $<
