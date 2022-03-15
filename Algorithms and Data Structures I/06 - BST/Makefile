# VARIABLES
CXX			:= g++
CXXFLAGS	:= -std=c++17 -Wall -O3

.PHONY: all clean

# ACTIONS
all: BinaryTree.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<


BinaryTree.o: BinaryTree.cpp BinaryTree.hpp
BinaryTree.x: BinaryTree.o