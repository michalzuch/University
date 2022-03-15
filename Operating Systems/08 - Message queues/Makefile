CC			:= gcc
CFLAGS		:= -O3 -Wall -std=c99 -pedantic -c
DLIBCFLAGS	:= -O -fPIC
LDLIBS_A	:= -L. -lmsg -lrt
LDLIBS_B	:= -L. -lshmem -lrt
LDLIBS_C	:= -L. -lshmem -lrt -Wl,-R ./
AR			:= ar rv

.PHONY: all clean

# Libraries
msg.o: msg.c
	$(CC) -c $(DLIBCFLAGS) $<
libmsg.so: msg.o
	$(CC) -shared -o $@ $<

# Programs
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.x: %.o
	$(CC) -pthread -o $@ $< $(LDLIBS_A)

client.x: client.o libmsg.so
client.o: client.c
server.x: server.o libmsg.so
server.o: server.c

all: libmsg.so server.x client.x
clean:
	$(RM) *.o *.x *.a a.out *.so

# export LD_LIBRARY_PATH=.