# VARIABLES
CC		:= g++
CFLAGS	:= -std=c++17 -Wall -O3
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

# ACTIONS
all: ArrayList.x CursorList.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<

ArrayList.o: ArrayList.cpp ArrayList.hpp
ArrayList.x: ArrayList.o
CursorList.o: CursorList.cpp CursorList.hpp
CursorList.x: CursorList.o
