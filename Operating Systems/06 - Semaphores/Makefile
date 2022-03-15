CC		:= gcc
CFLAGS	:= -O3 -Wall -c -pedantic -std=c99
LDFLAGS	:= -pthread -L.
LDLIBS	:= -lrt -lsem
AR		:= ar rv

.PHONY: all clean

%.a:
	$(AR) $@ $<
%.x: %.o
	$(CC) $(LDFLAGS) -o $@ $^ $(LDLIBS)
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

libsem.a: sem.o
sem.o: sem.c sem.h
semuse.o: semuse.c sem.h
semuse.x: semuse.o libsem.a
prog.o: prog.c
prog.x: prog.o libsem.a
multiplier.o: multiplier.c
multiplier.x: multiplier.o libsem.a

all: libsem.a semuse.x multiplier.x prog.x
clean:
	$(RM) *.o *.x *.a a.out