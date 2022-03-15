CC		:= gcc
CFLAGS	:= -O3 -Wall -c
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

procinfo.o: procinfo.c procinfo.h
main.o: main.c procinfo.h
main.x: main.o procinfo.o
copy.o: copy.c
copy.x: copy.o
processes.o: processes.c procinfo.h
processes.x: processes.o procinfo.o
leader.o: leader.c procinfo.h
leader.x: leader.o procinfo.o

all: main.x copy.x processes.x leader.x
clean:
	$(RM) *.o *.x a.out
