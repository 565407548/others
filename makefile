cc=gcc
cflags=-g -I./include

bin=bin/sqrt bin/findElemInMatrix bin/selectElement


image:$(bin)

clear:
	-rm $(bin)

bin/sqrt:src/sqrt.c
	$(cc) $(cflags) -o $@ $<
bin/findElemInMatrix:src/findElemInMatrix.c
	$(cc) $(cflags) -o $@ $<
bin/selectElement:src/selectElement.c
	$(cc) $(cflags) -o $@ $<
