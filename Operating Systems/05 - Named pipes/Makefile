CC		:= gcc
CFLAGS	:= -O3 -Wall -c -pedantic -std=c99
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

%.x: %.o
	$(CC) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -o $@ $<

fifo.o: fifo.c
fifo.x: fifo.o producer.x consumer.x
producer.o: producer.c
producer.x: producer.o
consumer.o: consumer.c
consumer.x: consumer.o

all: producer.x consumer.x fifo.x
clean:
	$(RM) *.o *.x a.out