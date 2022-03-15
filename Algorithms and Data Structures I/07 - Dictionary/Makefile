# VARIABLES
CXX			:= g++
CXXFLAGS	:= -std=c++17 -Wall -O3

.PHONY: all clean test compare

# ACTIONS
all: Dict.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CXX) -o $@ $^
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

Dict.o: Dict.cpp
Dict.x: Dict.o

test:
	./Dict.x pairs.txt < input.txt > output.txt
compare:
	diff -s result.txt output.txt