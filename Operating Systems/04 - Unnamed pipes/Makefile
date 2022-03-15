CC		:= gcc
CFLAGS	:= -O3 -Wall -c -pedantic -std=c99
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

%.x: %.o
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

prodcons.o: prodcons.c
prodcons.x: prodcons.o

all: prodcons.x
clean:
	$(RM) *.o *.x a.out