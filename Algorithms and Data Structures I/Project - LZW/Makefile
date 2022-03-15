# VARIABLES
CXX			:= g++
CXXFLAGS	:= -std=c++17 -Wall -O3

.PHONY: all clean cleanall

# ACTIONS
all: LZW.x
clean:
	$(RM) *.o *.x
cleanall:
	$(RM) *.o *.x *.LZW

# RULES
%.x: %.o
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

LZW.o: LZW.cpp LZW.hpp
LZW.x: LZW.o