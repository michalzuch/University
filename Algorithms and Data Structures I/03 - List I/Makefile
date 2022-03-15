# VARIABLES
CC		:= g++
CFLAGS	:= -std=c++17 -Wall -O3
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

# ACTIONS
all: Generator.x LinkedList.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

Generator.x: Generator.o
Generator.o: Generator.cpp

LinkedList.o: LinkedList.cpp LinkedList.hpp
LinkedList.x: LinkedList.o
