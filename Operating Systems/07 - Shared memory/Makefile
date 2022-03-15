CC			:= gcc
CFLAGS		:= -O3 -Wall -c -std=c99
DLIBCFLAGS	:= -O -fPIC
LDLIBS_A	:= -L. -lshmem -lsem -lrt
LDLIBS_B	:= -L. -lshmem -lrt
LDLIBS_C	:= -L. -lshmem -lrt -Wl,-R ./
AR			:= ar rv

.PHONY: all clean

# Libraries
sem.o: sem.c
	$(CC) -c $<
libsem.a: sem.o
	$(AR) $@ $<
shmem.o: shmem.c
	$(CC) -c $(DLIBCFLAGS) $<
libshmem.so: shmem.o
	$(CC) -shared -o $@ $<

# Programs
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
%.x: %.o
	$(CC) -pthread -o $@ $< $(LDLIBS_A)
%1.x: %.o
	$(CC) -o $@ $< $(LDLIBS_B)
%2.x: %.o
	$(CC) -o $@ $< $(LDLIBS_C)

glowny.x: glowny.o libshmem.so libsem.a producent.x konsument.x
glowny.o: glowny.c
producent.x: producent.o libsem.a libshmem.so
producent.o: producent.c
konsument.x: konsument.o libsem.a libshmem.so
konsument.o: konsument.c

all: libsem.a libshmem.so shmemuse1.x shmemuse2.x producent.x konsument.x glowny.x
clean:
	$(RM) *.o *.x *.a a.out *.so

# export LD_LIBRARY_PATH=.