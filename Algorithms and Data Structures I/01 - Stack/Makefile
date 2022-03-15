# VARIABLES
CXX			:= g++
CXXFLAGS	:= -std=c++17 -Wall -O3
LDFLAGS		:=
LDLIBS		:=

.PHONY: all clean

# ACTIONS
all: Generator.x RPN.x Stack.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

ArrayStack.o: ArrayStack.cpp
LinkedStack.o: LinkedStack.cpp

Generator.x: Generator.o
Generator.o: Generator.cpp

# Array implementation
# Stack.x: Stack.o ArrayStack.o
# Stack.o: Stack.cpp ArrayStack.hpp

# Pointer implementation
Stack.x: Stack.o LinkedStack.o
Stack.o: Stack.cpp LinkedStack.hpp

# Array implementation
#RPN.x: RPN.o ArrayStack.o
#RPN.o: RPN.cpp ArrayStack.hpp

# Pointer implementation
RPN.x: RPN.o LinkedStack.o
RPN.o: RPN.cpp LinkedStack.hpp

