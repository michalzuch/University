# VARIABLES
CXX			:= g++
CXXFLAGS	:= -std=c++17 -Wall -O3
LDFLAGS		:=
LDLIBS		:=

.PHONY: all clean

# ACTIONS
all: Generator.x Queue.x Radix.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

ArrayQueue.o: ArrayQueue.cpp
LinkedQueue.o: LinkedQueue.cpp

Generator.x: Generator.o
Generator.o: Generator.cpp

# Array implementation
Queue.x: Queue.o ArrayQueue.o
Queue.o: Queue.cpp ArrayQueue.hpp

# Pointer implementation
Radix.x: Radix.o LinkedQueue.o
Radix.o: Radix.cpp LinkedQueue.hpp
