CC			:= gcc
CFLAGS		:= -std=gnu99 -O3 -Wall -Wextra -pthread
LDFLAGS		:=
LDLIBS		:=

.PHONY: all clean

%.x: %.o
	$(CC) -pthread -o $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

exclusion.o: exclusion.c
exclusion.x: exclusion.o

all: exclusion.x
clean:
	$(RM) *.o *.x a.out
