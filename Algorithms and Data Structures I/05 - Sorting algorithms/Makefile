# VARIABLES
CC		:= g++
CFLAGS	:= -std=c++17 -Wall -O3
LDFLAGS	:=
LDLIBS	:=

.PHONY: all clean

# ACTIONS
all: Generator.x BubbleSort.x InsertionSort.x SelectionSort.x
clean:
	$(RM) *.o *.x

# RULES
%.x: %.o
	$(CC) -o $@ $^
%.o: %.cpp
	$(CC) $(CFLAGS) -o $@ -c $<


Generator.o: Generator.cpp
Generator.x: Generator.o

BubbleSort.o: BubbleSort.cpp
BubbleSort.x: BubbleSort.o

InsertionSort.o: InsertionSort.cpp
InsertionSort.x: InsertionSort.o

SelectionSort.o: SelectionSort.cpp
SelectionSort.x: SelectionSort.o

BubbleSortWithCounter.o: BubbleSortWithCounter.cpp
BubbleSortWithCounter.x: BubbleSortWithCounter.o

SelectionMinmax.o: SelectionMinmax.cpp
SelectionMinmax.x: SelectionMinmax.o
