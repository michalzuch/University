CC			:= gcc
CFLAGS		:= -std=gnu99 -O3 -Wall -Wextra -pthread
LDFLAGS		:=
LDLIBS		:=

.PHONY: all clean

%.x: %.o
	$(CC) -pthread -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

bakery.o: bakery.c
bakery.x: bakery.o
bakery2.o: bakery2.c
bakery2.x: bakery2.o

all: bakery.x bakery2.x
clean:
	$(RM) *.o *.x a.out
