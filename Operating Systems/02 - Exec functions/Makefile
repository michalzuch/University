CC		:= gcc
CFLAGS	:= -O3 -Wall -c
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

%.x: %.o
	$(CC) -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

procinfo.o: procinfo.o procinfo.h
tree1.o: tree1.c
tree1.x: tree1.o procinfo.o
tree2.o: tree2.c
tree2.x: tree2.o procinfo.o
parent.o: parent.c
parent.x: parent.o procinfo.o posterior.x
posterior.o: posterior.c
posterior.x: posterior.o procinfo.o
zombie.o: zombie.c
zombie.x: zombie.o
orphan.o: orphan.c
orphan.x: orphan.o

all: tree1.x tree2.x parent.x posterior.x zombie.x orphan.x
clean:
	$(RM) *.o *.x a.out
