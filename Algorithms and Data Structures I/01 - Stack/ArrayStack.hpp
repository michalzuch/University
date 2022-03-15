#ifndef ARRAYSTACK_HPP
#define ARRAYSTACK_HPP

class Stack {
private:
    int _top = 0;
    int _capacity;
    int *data = new int;

public:

    // Constructor, argument - array size
    Stack(int capacity);

    // Adds element to stack
    void push(int x);

    // Removes the element from stack and returns its value
    int pop();

    // Returns amount of elements on stack
    int size();

    // Checks if stack is empty
    bool empty();

};

#endif //ARRAYSTACK_HPP
