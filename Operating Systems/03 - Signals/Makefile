CC		:= gcc
CFLAGS	:= -O3 -Wall -c -std=c99
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

%.x: %.o
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

handling.o: handling.c procinfo.h
handling.x: handling.o procinfo.o
send.o: send.c
send.x: send.o handling.x
group.o: group.c
group.x: group.o handling.x
procinfo.o: procinfo.c procinfo.h

all: handling.x send.x group.x
clean:
	$(RM) *.o *.x
